#include "pascals_triangle.h"

namespace pascals_triangle {

auto generate_rows(unsigned n) -> std::vector<std::vector<int>> {
    auto result = std::vector<std::vector<int>>{};
    result.reserve(n);

    for (auto i = 0u; i < n; ++i) {
        auto& row = result.emplace_back();
        row.reserve(i + 1);

        for (auto j = 0u; j <= i; ++j) {
            if (j == 0 || j == i) {
                row.emplace_back(1);
            } else {
                row.emplace_back(result[i - 1][j - 1] + result[i - 1][j + 0]);
            }
        }
    }

    return result;
}

} // namespace pascals_triangle
