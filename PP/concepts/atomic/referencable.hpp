#pragma once
#include "../../get_type.hpp"
#include "../../templated_dummy.hpp"

namespace PP
{
	PP_FUNCTOR(is_referencable, type_wrap auto t)
	{
		return requires
		{
			typename detail::templated_dummy<PP_GET_TYPE(t)&>;
		};
	}};
}
