#pragma once

#include <stdexcept>
#include <vector>

namespace binary_search {

inline auto find(std::vector<int> const& data, int value) -> std::size_t {
    size_t b = 0, e = data.size(); // Prioritizing readability :p

    for (auto s = e, m = s / 2; s > 0; s = e - b, m = b + s / 2) {
        if (data[m] == value) { return m; }
        if (data[m] < value) { b = m + 1; } else { e = m; }
    }

    throw std::domain_error("Item not found");
}

} // namespace binary_search
