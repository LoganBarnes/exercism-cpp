#include "difference_of_squares.h"

#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>

namespace difference_of_squares {

auto square_of_sum(int x) -> int {
    auto values = std::vector<int>(static_cast<unsigned>(x));
    std::iota(values.begin(), values.end(), 1);
    auto sum = std::accumulate(values.begin(), values.end(), 0);
    return sum * sum;
}

auto sum_of_squares(int x) -> int {
    return 0;
}

auto difference(int x) -> int {
    return 0;
}

} // namespace difference_of_squares
