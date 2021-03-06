#pragma once
#include "atomic/reference.hpp"
#include "../functional/negate.hpp"
#include "lvalue_reference.hpp"

namespace PP
{
	constexpr inline auto is_rvalue_reference = is_reference && !is_lvalue_reference;

	PP_CONCEPT1(rvalue_reference)
}
