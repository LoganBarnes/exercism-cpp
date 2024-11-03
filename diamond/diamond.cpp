#include "diamond.h"

#include <format>
#include <numeric>
#include <ranges>

// C++26 ranges version

namespace diamond {

using namespace std;

auto mirror(auto v) {
    return views::concat(v, v | views::reverse | views::drop(1)) | ranges::to<decltype(v)>();
}

auto rows(char const c) -> vector<string> {
    auto const n = static_cast<size_t>(c - 'A') + 1UL;

    auto const to_row = [n](auto const row) {
        return mirror(format("{:>{}c}{}", 'A' + row, n - row, string(row, ' ')));
    };

    return mirror(views::iota(0UL, n) | views::transform(to_row) | ranges::to<vector>());
}

} // namespace diamond
