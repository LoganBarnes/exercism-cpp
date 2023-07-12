#pragma once

#include <string>
#include <vector>

namespace series {

auto slice(std::string const& input, int length) -> std::vector<std::string>;

} // namespace series
