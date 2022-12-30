#include "darts.h"

#include <array>
#include <cmath>
#include <map>
#include <numeric>

namespace darts {

auto score(double x, double y) -> unsigned {
    auto const distance_to_points = std::map<double, unsigned>{
        {-1.0, 10U}, // any negative number will do.
        {1.0, 5U},
        {5.0, 1U},
        {10.0, 0U},
    };
    auto const point    = std::array<double, 2>{x, y};
    auto const distance = std::sqrt(
        std::inner_product(point.begin(), point.end(), point.begin(), 0.0)
    );

    return std::prev(distance_to_points.lower_bound(distance))->second;
}

} // namespace darts
