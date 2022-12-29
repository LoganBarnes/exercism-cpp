#include "binary_search.h"

#include <algorithm>
#include <stdexcept>

namespace binary_search {

auto find(std::vector<int> const& data, int value) -> std::size_t {
    // Cheating ;). lower_bound does the binary search.
    auto iter = std::lower_bound(data.begin(), data.end(), value);

    if (iter != data.end() && *iter == value) {
        return static_cast<size_t>(iter - data.begin());
    }
    throw std::domain_error("Item not found");
}

} // namespace binary_search
