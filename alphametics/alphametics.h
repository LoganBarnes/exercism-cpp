#pragma once

#include <optional>
#include <string_view>
#include <unordered_map>

namespace alphametics {

using CharNumberMap = std::unordered_map<char, int>;

auto solve(std::string_view str) -> std::optional<CharNumberMap>;

} // namespace alphametics
