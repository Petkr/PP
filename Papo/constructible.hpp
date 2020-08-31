#pragma once
#include "declval.hpp"

namespace Papo
{
	template <typename T, typename... Args>
	concept constructible = requires
	{
		T(declval<Args>()...);
	};
}
