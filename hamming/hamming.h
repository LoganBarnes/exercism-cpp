#pragma once

#include <numeric>
#include <stdexcept>
#include <string>

namespace hamming {

inline auto compute(std::string const& l, std::string const& r) -> int {
    if (l.size() != r.size()) { throw std::domain_error("Mismatched sizes"); }

    return std::inner_product(l.begin(), l.end(), r.begin(), 0, std::plus{}, std::not_equal_to{});
}

} // namespace hamming
