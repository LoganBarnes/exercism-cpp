#pragma once

namespace triangle {

enum class flavor {
    equilateral,
    isosceles,
    scalene,
};

auto kind(double a, double b, double c) -> flavor;

} // namespace triangle
