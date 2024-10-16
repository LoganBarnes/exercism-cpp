#pragma once

#include <numeric>
#include <stdexcept>
#include <vector>

namespace all_your_base {

using digits = std::vector<unsigned>;

inline auto convert(unsigned ib, digits const& ds, unsigned ob) -> digits {
    if (ib <= 1 || ob <= 1) { throw std::invalid_argument("Low base"); }

    auto val = std::accumulate(ds.begin(), ds.end(), 0U, [ib](auto v, auto d) {
        return d >= ib ? throw std::invalid_argument("High digit") : v * ib + d;
    });

    auto output_digits = digits{};
    for (; val > 0U; val /= ob) { output_digits.emplace_back(val % ob); }

    return {output_digits.rbegin(), output_digits.rend()};
}

} // namespace all_your_base
