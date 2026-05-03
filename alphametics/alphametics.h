#pragma once

#include <optional>
#include <string>
#include <unordered_map>

namespace alphametics {

auto solve(std::string letters) -> std::optional<std::unordered_map<char, int>>;

} // namespace alphametics
