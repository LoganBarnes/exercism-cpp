#include "diamond.h"

#include <stdexcept>

namespace diamond {
namespace {

template <typename Container>
auto mirror(Container const& value) {
    auto copy = value;
    copy.insert(copy.end(), std::next(value.rbegin()), value.rend());
    return copy;
};

} // namespace

auto rows(char const c) -> std::vector<std::string> {
    if ((c < 'A') || ('Z' < c)) {
        throw std::domain_error("Invalid input");
    }

    auto const n = static_cast<size_t>(c - 'A') + 1UL;

    auto result = std::vector<std::string>(n, std::string(n, ' '));

    for (auto i = 0UL; i < n; ++i) {
        result[i][n - i - 1UL] = static_cast<char>('A' + i);
        result[i]              = mirror(result[i]);
    }

    return mirror(result);
}

} // namespace diamond
