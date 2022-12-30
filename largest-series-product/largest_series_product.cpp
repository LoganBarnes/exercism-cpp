#include "largest_series_product.h"

#include <algorithm>
#include <numeric>
#include <optional>
#include <vector>

namespace largest_series_product {

auto largest_product(std::string const& digits, int span) -> unsigned {
    // Handle all errors as soon as possible.
    if (span < 0) {
        throw std::domain_error("Negative span");
    }

    auto span_size = static_cast<unsigned>(span);

    if (digits.size() < span_size) {
        throw std::domain_error("Span larger than digits");
    }

    auto actual_digits = std::vector<unsigned>(digits.size(), 0U);

    std::transform(
        digits.begin(),
        digits.end(),
        actual_digits.begin(),
        [](char c) {
            if ('0' > c || c > '9') {
                throw std::domain_error("Invalid digit: " + std::string{c});
            }
            return static_cast<unsigned>(c - '0');
        }
    );

    // Find the largest product now that all errors cases have been handled.
    auto biggest_product = 0U;

    for (auto i = span_size; i <= actual_digits.size(); ++i) {
        auto product = std::accumulate(
            actual_digits.data() + i - span_size,
            actual_digits.data() + i,
            1U,
            std::multiplies{}
        );

        biggest_product = std::max(biggest_product, product);
    }

    return biggest_product;
}

} // namespace largest_series_product
