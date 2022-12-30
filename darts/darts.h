#pragma once

#include <cmath>
#include <map>

namespace darts {

inline auto score(double x, double y) -> int { // Attempt at a "one-liner"
    return std::prev(std::map<double, int>{{-1, 10}, {1, 5}, {5, 1}, {10, 0}}.lower_bound(std::sqrt(x * x + y * y)))->second;
}

} // namespace darts
