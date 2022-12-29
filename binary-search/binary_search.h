#pragma once

#include <vector>

namespace binary_search {

/// \brief A simple replacement for std::lower_bound.
/// \details Returns an iterator pointing to the first element
///          in the range [first, last) that does not satisfy
///          element < value (i.e. greater or equal to), or
///          last if no such element is found.
template <typename Iter, typename T>
auto lower_bound(Iter first, Iter last, T value) -> Iter {
    auto get_size   = [&] { return last - first; };
    auto get_middle = [&] { return first + get_size() / 2; };

    auto middle = get_middle();

    for (auto size = get_size(); size > 0;
         middle = get_middle(), size = get_size()) {
        if (*middle < value) {
            first = middle + 1;
        } else {
            last = middle;
        }
    }

    return middle;
}

/// \brief Finds the index of the first occurrence
///        of 'value' in the sorted list 'data'.
/// \throws std::domain_error if 'value' is not found.
auto find(std::vector<int> const& data, int value) -> std::size_t;

} // namespace binary_search
