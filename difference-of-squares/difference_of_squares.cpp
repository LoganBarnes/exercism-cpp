#include "difference_of_squares.h"

#include <numeric>
#include <type_traits>

namespace difference_of_squares {
namespace {

template <typename T>
class counting_iterator {
public:
    static_assert(std::is_integral_v<T>);

    explicit counting_iterator(T value) : value_(value) {}

    auto operator++() -> void { ++value_; }

    auto operator*() -> T& { return value_; }

    bool operator!=(counting_iterator const& other) const {
        return value_ != other.value_;
    }

private:
    T value_;
};

} // namespace

auto square_of_sum(int x) -> int {
    auto sum
        = std::accumulate(counting_iterator(1), counting_iterator(x + 1), 0);
    return sum * sum;
}

auto sum_of_squares(int x) -> int {
    return std::inner_product(
        counting_iterator(1), counting_iterator(x + 1), counting_iterator(1), 0
    );
}

auto difference(int x) -> int {
    return square_of_sum(x) - sum_of_squares(x);
}

} // namespace difference_of_squares
