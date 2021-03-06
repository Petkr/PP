#pragma once
#include "../declval.hpp"
#include "complete_object.hpp"
#include "function.hpp"
#include "reference.hpp"
#include "void.hpp"

namespace PP
{
	PP_FUNCTOR(is_destructible, concepts::type auto t)
	{
		constexpr auto T = PP_COPY_TYPE(t);

		if constexpr (is_reference(T))
			return true;
		else if constexpr (is_complete_object(T))
		{
			using U = PP_GET_TYPE(T);
			return requires
			{
				declval(type<U&>).~U();
			};
		}
		else
			return false;
	});

	namespace concepts
	{
		template <typename T>
		concept destructible = is_destructible(PP::type<T>) || reference<T>;
	}
}
