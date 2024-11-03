#include "diamond.h"

namespace diamond {

auto rows(char const c) -> std::vector<std::string> {
    auto const n   = static_cast<size_t>(c - 'A');
    auto const dim = 2UL * n + 1UL;

    auto result = std::vector<std::string>{n + 1UL, std::string(dim, ' ')};

    for (auto i = 0UL; i <= n; i++) {
        result[i][n - i] = result[i][n + i] = static_cast<char>('A' + i);
    }
    result.insert(result.end(), result.rbegin() + 1, result.rend());

    return result;
}

} // namespace diamond
