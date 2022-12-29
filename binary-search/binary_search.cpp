#include "binary_search.h"

#include <stdexcept>

namespace binary_search {

auto find(std::vector<int> const& data, int value) -> std::size_t {
    auto iter = binary_search::lower_bound(data.begin(), data.end(), value);

    if (iter != data.end() && *iter == value) {
        return static_cast<std::size_t>(iter - data.begin());
    }

    throw std::domain_error("Item not found");
}

} // namespace binary_search
