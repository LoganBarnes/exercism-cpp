#include "largest_series_product.h"

#include <algorithm>
#include <cctype>
#include <numeric>

namespace largest_series_product {

auto multiply(unsigned i, char c) -> unsigned {
    if (!std::isdigit(c)) {
        throw std::domain_error("Invalid digit");
    }
    return i * static_cast<unsigned>(c - '0');
}

auto largest_product(std::string const& digits, int n) -> unsigned {
    if (n < 0 || static_cast<int>(digits.size()) < n) {
        throw std::domain_error("Invalid span length");
    }

    return std::transform_reduce(
        digits.begin(),
        digits.end() - n + 1,
        0U,
        [](auto l, auto r) { return std::max(l, r); },
        [&](char const& c) { return std::accumulate(&c, &c + n, 1U, multiply); }
    );
}

} // namespace largest_series_product
