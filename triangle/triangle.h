#pragma once

#include <algorithm>
#include <array>
#include <numeric>

namespace triangle {

enum class flavor { equilateral, isosceles, scalene };

inline auto kind(double a, double b, double c) -> flavor {
    auto t = std::array{a, b, c};

    if (std::any_of(t.begin(), t.end(), [](auto s) { return s <= 0.0; })) {
        throw std::domain_error("Triangle has a zero length size");
    }

    auto const max_side_length  = *std::max_element(t.begin(), t.end());
    auto const sum_of_all_sides = std::accumulate(t.begin(), t.end(), 0.0);

    if (sum_of_all_sides - max_side_length < max_side_length) {
        throw std::domain_error("Some sides of the triangle are too short");
    }

    auto sides = std::array{b == c, c == a, a == b};
    auto equal = [](auto b) { return b; };

    if (std::all_of(sides.begin(), sides.end(), equal)) {
        return flavor::equilateral;
    }
    if (std::any_of(sides.begin(), sides.end(), equal)) {
        return flavor::isosceles;
    }
    return flavor::scalene;
}

} // namespace triangle
