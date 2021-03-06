#pragma once
#include "functional/functor.hpp"
#include "concepts/pointable.hpp"
#include "remove_reference.hpp"

namespace PP
{
	constexpr inline auto add_pointer = functor([](concepts::type auto t)
	{
		if constexpr (is_pointable(PP_COPY_TYPE(t)))
			return type<PP_GET_TYPE(t)*>;
		else
			return t;
	}) | remove_reference;
}
