#include "triangle.h"

#include <algorithm>
#include <array>
#include <numeric>
#include <string>
#include <utility>

namespace triangle {

struct Triangle {
    std::array<double, 3>                    sides;
    std::array<std::pair<double, double>, 3> opposites;

    static auto make_or_throw(double a, double b, double c) -> Triangle {
        auto tri = Triangle{a, b, c};

        // Check all sides are positive.
        if (auto iter = std::find_if(
                tri.sides.begin(),
                tri.sides.end(),
                [](auto side) { return side <= 0.0; }
            );
            iter != tri.sides.end()) {

            throw std::domain_error(
                "Not a triangle. Found a non-positive side: "
                + std::to_string(*iter)
            );
        }

        // Check the largest side is smaller than the sum of the remaining sides.
        auto const max_side_length
            = *std::max_element(tri.sides.begin(), tri.sides.end());

        auto const sum_of_all_sides
            = std::accumulate(tri.sides.begin(), tri.sides.end(), 0.0);

        if (sum_of_all_sides - max_side_length < max_side_length) {
            throw std::domain_error(
                "Not a triangle. "
                "Largest side is larger than remaining sides"
            );
        }

        return tri;
    }

private:
    Triangle(double a, double b, double c)
        : sides{a, b, c}
        , opposites{
              std::make_pair(b, c),
              std::make_pair(c, a),
              std::make_pair(a, b)} {}
};

auto kind(double a, double b, double c) -> flavor {
    auto triangle = Triangle::make_or_throw(a, b, c);

    auto sides_equal = [](auto sides) { return sides.first == sides.second; };

    if (std::all_of( // All sides equal
            triangle.opposites.begin(),
            triangle.opposites.end(),
            sides_equal
        )) {
        return flavor::equilateral;

    } else if (std::any_of( // At least two sides equal
                   triangle.opposites.begin(),
                   triangle.opposites.end(),
                   sides_equal
               )) {
        return flavor::isosceles;

    } else {
        // No sides equal
        return flavor::scalene;
    }
}

} // namespace triangle
