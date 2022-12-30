#include "largest_series_product.h"

#include <algorithm>
#include <cctype>
#include <numeric>
#include <optional>
#include <vector>

namespace largest_series_product {

using namespace std;

auto mult(unsigned i, char c) {
    if (!isdigit(c)) { throw std::domain_error("Invalid digit"); }
    return i * static_cast<unsigned>(c - '0');
}

auto largest_product(string const& d, int n) -> unsigned {
    if (n < 0 || static_cast<int>(d.size()) < n) { throw domain_error("n"); }

    // Find the largest product now that all errors cases have been handled.
    auto p = 0U;

    for (auto i = n; i <= static_cast<int>(d.size()); ++i) {
        p = max(p, accumulate(d.data() + i - n, d.data() + i, 1U, mult));
    }

    return p;
}

} // namespace largest_series_product
