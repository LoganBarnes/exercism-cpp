#pragma once
#include <algorithm>
#include <cctype>
#include <numeric>
#include <string>

namespace largest_series_product {

inline auto multiply(unsigned i, char c) -> unsigned {
    if (!std::isdigit(c)) { throw std::domain_error("Invalid digit"); }
    return i * static_cast<unsigned>(c - '0');
}

inline auto largest_product(std::string const& d, int n) -> unsigned {
    if (n < 0 || static_cast<int>(d.size()) < n) { throw std::domain_error("n"); }

    return transform_reduce(d.begin(), d.end() - n + 1, 0U,
        [](auto l, auto r) { return std::max(l, r); },
        [&](char const& c) { return std::accumulate(&c, &c + n, 1U, multiply); }
    );
}

} // namespace largest_series_product
