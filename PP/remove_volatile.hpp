#pragma once
#include "functional/compose.hpp"
#include "get_type.hpp"
#include "overloaded.hpp"
#include "type_t.hpp"

namespace PP
{
	constexpr inline auto remove_volatile = functor{ overloaded
	{
		[]<typename T>(type_t<volatile T>) { return type_v<T>; },
		[]<typename T>(type_t<         T>) { return type_v<T>; }
	}} | to_type_t;
}