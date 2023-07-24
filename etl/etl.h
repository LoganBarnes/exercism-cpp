#pragma once

#include <map>
#include <vector>

namespace etl {

auto transform(std::map<int, std::vector<char>> const& old)
    -> std::map<char, int>;

} // namespace etl
