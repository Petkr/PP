#pragma once
#include "type_pack.hpp"
#include "type_t.hpp"
#include "apply_pack.hpp"

namespace PP
{
	namespace detail
	{
		struct first_pack__empty_pack_error {};

		template <typename... T>
		struct first_pack_helper : type_t<first_pack__empty_pack_error> {};
		template <typename T, typename... U>
		struct first_pack_helper<T, U...> : type_t<T> {};
	}

	template <typename Pack>
	using first_pack = apply_pack_types<detail::first_pack_helper, Pack>;
}