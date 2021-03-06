#pragma once
#include "../functional/functor.hpp"
#include "../functional/negate.hpp"
#include "../get_type.hpp"
#include "atomic/class.hpp"
#include "union.hpp"

namespace PP
{
	constexpr inline auto is_non_union_class = is_class && !is_union;

	PP_CONCEPT1(non_union_class)
}
