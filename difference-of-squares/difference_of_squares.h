#pragma once

#include <numeric>

namespace difference_of_squares {

struct I {
    int value;
    void operator++() { ++value; }
    int& operator*() { return value; }
    bool operator!=(I const& other) const { return value != other.value; }
};

inline int square_of_sum(int x) { return std::pow(std::accumulate(I{1}, I{x + 1}, 0), 2); }

inline int sum_of_squares(int x) { return std::inner_product(I{1}, I{x + 1}, I{1}, 0); }

inline int difference(int x) { return square_of_sum(x) - sum_of_squares(x); }

} // namespace difference_of_squares
