#include "diamond.h"

#include <format>
#include <numeric>
#include <ranges>

namespace diamond {

auto mirror(auto value) {
    value.insert(value.end(), value.rbegin() + 1, value.rend());
    return value;
}

auto rows(char const c) -> std::vector<std::string> {
    auto const n = static_cast<size_t>(c - 'A');

    auto const result
        = std::views::iota(0UL, n + 1UL)
        | std::views::transform([n](auto const i) {
              return mirror(std::format("{:>{}c}{}", 'A' + i, n - i + 1UL, std::string(i, ' ')));
          })
        | std::ranges::to<std::vector>();

    return mirror(result);
}

} // namespace diamond
