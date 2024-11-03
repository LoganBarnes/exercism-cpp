#include "diamond.h"

#define CXX26 202600L
#define CXX23 202300L
#define CXX20 202002L

#if __cplusplus >= CXX20
#include <format>
#include <numeric>
#include <ranges>
#endif

namespace diamond {

using namespace std;

#if __cplusplus >= CXX20
auto mirror(auto v) {
#else
template <typename Container>
auto mirror(Container v) {
#endif

#if __cplusplus >= CXX26

    return views::concat(v, v | views::reverse | views::drop(1)) | ranges::to<decltype(v)>();

#elif __cplusplus >= CXX23

    using R = decltype(v);
    return views::join(vector{v, v | views::reverse | views::drop(1) | ranges::to<R>()})
         | ranges::to<R>();

#else // CXX17 (exercism)

v.insert(v.end(), next(v.rbegin()), v.rend());
return v;

#endif
}

auto rows(char const c) -> vector<string> {
    auto const n = static_cast<size_t>(c - 'A') + 1UL;

#if __cplusplus >= CXX23

    auto const to_row = [n](auto const row) {
        return mirror(format("{:>{}c}{}", 'A' + row, n - row, string(row, ' ')));
    };

    return mirror(views::iota(0UL, n) | views::transform(to_row) | ranges::to<vector>());

#else // CXX17 (exercism)

    auto rows = vector<string>(n);

    for (auto i = 0UL; i < n; ++i) {
        rows[i] = mirror(string(n - i - 1UL, ' ') + static_cast<char>('A' + i) + string(i, ' '));
    }
    return mirror(rows);

#endif
}

} // namespace diamond
