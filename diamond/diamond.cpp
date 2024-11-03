#include "diamond.h"

#include <algorithm>
#include <numeric>
#include <stdexcept>

namespace diamond {

using namespace std;

template <typename Container>
auto mirror(Container const& value) {
    auto copy = value;
    copy.insert(copy.end(), std::next(value.rbegin()), value.rend());
    return copy;
};

auto rows(char const c) -> vector<string> {
    if ((c < 'A') || ('Z' < c)) {
        throw std::domain_error("Invalid input");
    }

    auto const n = static_cast<size_t>(c - 'A') + 1UL;

    auto const to_row = [n](auto const row) {
        return mirror(
            std::string(n - row - 1UL, ' ')
            + static_cast<char>('A' + row)
            + std::string(row, ' ')
        );
    };

    auto indices = std::vector<size_t>(n);
    auto result  = std::vector<std::string>(n);

    std::iota(indices.begin(), indices.end(), 0UL);
    std::transform(indices.begin(), indices.end(), result.begin(), to_row);

    return mirror(result);
}

} // namespace diamond
