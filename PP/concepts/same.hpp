#pragma once
#include "../type_t.hpp"

namespace PP::concepts
{
	template <typename T, typename U>
	concept same = PP::type<T> == PP::type<U> && PP::type<U> == PP::type<T>;
	template <typename T, typename U>
	concept different = !same<T, U>;
}
