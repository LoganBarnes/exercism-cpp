#pragma once

#include <array>
#include <string_view>

namespace yacht {

auto score(std::array<int, 5U> const& dice, std::string_view category) -> int;

} // namespace yacht
