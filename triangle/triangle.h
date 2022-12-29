#pragma once

#include <algorithm>
#include <numeric>
#include <vector>

namespace triangle {

enum class flavor { equilateral, isosceles, scalene };

inline auto kind(double a, double b, double c) -> flavor {
    auto t = std::vector<double>{a, b, c};

    auto const max_side_length  = *std::max_element(t.begin(), t.end());
    auto const sum_of_all_sides = std::accumulate(t.begin(), t.end(), 0.0);

    if (std::any_of(t.begin(), t.end(), [](auto s) { return s <= 0.0; })
        || sum_of_all_sides - max_side_length < max_side_length) {
        throw std::domain_error("Not a triangle.");
    }

    auto p = std::vector<std::pair<double, double>>{{b, c}, {c, a}, {a, b}};
    auto equal = [](auto sides) { return sides.first == sides.second; };

    if (std::all_of(p.begin(), p.end(), equal)) { return flavor::equilateral; }
    if (std::any_of(p.begin(), p.end(), equal)) { return flavor::isosceles; }
    return flavor::scalene;
}

} // namespace triangle
