#pragma once

#include <optional>
#include <string_view>
#include <unordered_map>

namespace alphametics {

auto solve(std::string_view letters) -> std::optional<std::unordered_map<char, int>>;

} // namespace alphametics
