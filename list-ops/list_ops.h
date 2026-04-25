#pragma once

#include <numeric>
#include <vector>

namespace list_ops {
namespace detail {

template <typename Iter, typename T, typename Pred>
auto fold(Iter begin, Iter end, T acc, Pred&& pred) {
    for (auto iter = begin; iter != end; ++iter) {
        acc = pred(acc, *iter);
    }
    return acc;
}

} // namespace detail

template <typename T>
auto append(std::vector<T>& list, std::vector<T> const& to_append) {
    list.insert(list.end(), to_append.begin(), to_append.end());
    return list;
}

template <typename T>
auto concat(std::vector<std::vector<T>> const& values) {
    auto all = std::vector<T>{};
    for (auto const& value : values) {
        append(all, value);
    }
    return all;
}

template <typename T, typename Pred>
auto filter(std::vector<T> values, Pred&& pred) {
    auto result = std::vector<T>{};
    for (auto const& value : values) {
        if (pred(value)) {
            result.emplace_back(value);
        }
    }
    return result;
}

template <typename T, typename Pred>
auto map(std::vector<T> const& values, Pred&& pred) {
    using ResultType = std::decay_t<decltype(pred(values.front()))>;
    auto result      = std::vector<ResultType>{};

    for (auto& value : values) {
        result.emplace_back(pred(value));
    }
    return result;
}

template <typename T, typename U, typename Pred>
auto foldl(std::vector<T> const& values, U acc, Pred&& pred) {
    return detail::
        fold(values.cbegin(), values.cend(), acc, std::forward<Pred>(pred));
}

template <typename T, typename U, typename Pred>
auto foldr(std::vector<T> const& values, U acc, Pred&& pred) {
    return detail::
        fold(values.crbegin(), values.crend(), acc, std::forward<Pred>(pred));
}

template <typename T>
auto length(std::vector<T> const& values) {
    return foldl(values, 0UL, [](size_t const& a, auto const&) {
        return a + 1UL;
    });
}

template <typename T>
auto reverse(std::vector<T> values) {
    auto const size      = values.size();
    auto const half_size = size / 2;

    for (auto i = 0U; i < half_size; ++i) {
        std::swap(values[i], values[size - 1U - i]);
    }
    return values;
}

} // namespace list_ops
