#pragma once

#include <cmath>
#include <numeric>
#include <string>

namespace armstrong_numbers {

inline auto is_armstrong_number(int n) -> bool {
    auto const s = std::to_string(n);
    auto const l = static_cast<int>(s.length());
    auto const convert = [l](char c) { return static_cast<int>(std::pow(c - '0', l)); };

    return std::transform_reduce(s.begin(), s.end(), 0, std::plus<>{}, convert) == n;
}

} // namespace armstrong_numbers
