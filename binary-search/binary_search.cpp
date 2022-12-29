#include "binary_search.h"

#include <stdexcept>

namespace binary_search {

// Only requires the '<' operator to be implemented.
auto lower_bound(std::vector<int> const& data, int value) -> std::size_t {
    std::size_t begin = 0;
    std::size_t end   = data.size();

    auto get_size   = [&begin, &end] { return end - begin; };
    auto get_middle = [&begin, &end] { return (begin + end) / 2; };

    for (auto middle = get_middle(), size = get_size(); // init
         size > 0; // check
         middle = get_middle(), size = get_size() // update
    ) {
        if (data[middle] < value) {
            begin = middle + 1;
        } else {
            end = middle;
        }
    }

    return get_middle();
}

auto find(std::vector<int> const& data, int value) -> std::size_t {
    auto index = lower_bound(data, value);

    if (index < data.size() && data[index] == value) {
        return index;
    }

    throw std::domain_error("Item not found");
}

} // namespace binary_search
