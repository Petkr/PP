#pragma once
#include <tuple>

#include "view_tuple.hpp"

namespace std
{
	template <typename Iterator, std::size_t Count>
	struct tuple_size<PP::view_tuple<Iterator, Count>> : public integral_constant<size_t, Count> {};
	template <std::size_t I, typename Iterator, std::size_t Count>
	struct tuple_element<I, PP::view_tuple<Iterator, Count>> : public type_identity<PP::iterator_base_t<Iterator>> {};
}
