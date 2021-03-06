#pragma once
#include "template_t.hpp"
#include "get_value.hpp"
#include "tuple_recursive.hpp"
#include "tuple_head_no_get.hpp"

namespace PP
{
	template <template <typename...> typename...>
	struct template_tuple_t {};
	template <template <typename...> typename T, template <typename...> typename... Templates>
	struct template_tuple_t<T, Templates...>
	{
		constexpr auto head() const noexcept
		{
			return Template<T>;
		}
		constexpr auto head_element() const noexcept
		{
			return type<template_t<T>>;
		}
		constexpr auto pred() const noexcept
		{
			return template_tuple_t<Templates...>{};
		}
		constexpr auto operator[](concepts::value auto i) const noexcept
		{
			return tuple_recursive(tuple_head_no_get, i, *this);
		}
	};

	template <template <typename...> typename... Templates>
	constexpr inline template_tuple_t<Templates...> template_tuple = {};

	template <template <typename...> typename... Templates>
	constexpr auto tuple_count_implementation(template_tuple_t<Templates...>) noexcept
	{
		return value<sizeof...(Templates)>;
	}
}
