#pragma once
#include "fundamental_integers_signed.hpp"
#include "fundamental_integers_unsigned.hpp"
constexpr auto fundamental_integers = join<fundamental_integers_signed, fundamental_integers_unsigned>;