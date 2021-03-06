#pragma once
#include "arrow_operator_wrapper.hpp"
#include "functional/compose.hpp"
#include "remove_cvref.hpp"
#include "template_t.hpp"
#include "type_t.hpp"
#include "type_tuple.hpp"

namespace PP
{
	template <typename T>
	constexpr auto type_t<T>::operator->() const noexcept
	{
		return arrow_operator_wrapper(**this);
	}

	namespace detail
	{
		template <template <typename...> typename T, typename... Types>
		struct decompose_pair
		{
			template_t<T> Template;
			type_tuple_t<Types...> types;
		};

		template <typename T>
		struct decompose_dummy {};
	}
	
	constexpr inline auto decompose = make_overloaded_pack(
		[] <template <typename...> typename T, typename... Types>(type_t<T<Types...>>)
		{
			return detail::decompose_pair(Template<T>, type_tuple<Types...>);
		},
		[](auto&&)
		{
			return detail::decompose_pair(Template<detail::decompose_dummy>, type_tuple<>);
		}) | remove_cvref;

	constexpr inline auto decompose_template = functor([](auto p) { return p.Template; }) | decompose;
	constexpr inline auto decompose_types = functor([](auto p) { return p.types; }) | decompose;

	constexpr auto operator*(concepts::type auto t) noexcept
	{
		return decompose(t);
	}
}
