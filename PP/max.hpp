#pragma once
#include "functional/functor.hpp"
#include "view.hpp"

namespace PP
{
	PP_FUNCTOR(max, auto&& comparer, concepts::view auto&& v)
	{
		auto [begin, end] = view_begin_end(PP_FORWARD(v));

		if (begin == end)
			return end;

		auto max_i = begin;

		++begin;

		for (; begin != end; ++begin)
		{
			if (PP_FORWARD(comparer)(*max_i, *begin))
				max_i = begin;
		}

		return max_i;
	});
}
