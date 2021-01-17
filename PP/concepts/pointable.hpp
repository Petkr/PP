#pragma once
#include "atomic/pointable.hpp"
#include "referencable.hpp"
#include "void.hpp"

namespace PP
{
	namespace concepts
	{
		template <typename T>
		concept pointable = is_pointable(type_v<T>) || referencable<T> || void_type<T>;
	}
}
