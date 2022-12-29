#include "all_your_base.h"

#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <string>

namespace all_your_base {

auto convert(
    unsigned                     input_base,
    std::vector<unsigned> const& input_digits,
    unsigned                     output_base
) -> std::vector<unsigned> {

    // All error/guard statements at the top.
    if (input_base <= 1) {
        throw std::invalid_argument("Input base is less than 1");
    }
    if (output_base <= 1) {
        throw std::invalid_argument("Output base is less than 1");
    }
    if (auto iter = std::find_if(
            input_digits.begin(),
            input_digits.end(),
            [input_base](auto digit) { return digit >= input_base; }
        );
        iter != input_digits.end()) {
        throw std::invalid_argument("Invalid digit: " + std::to_string(*iter));
    }

    // Convert to a "normal" base-10 value.
    auto value = std::accumulate(
        input_digits.begin(),
        input_digits.end(),
        0U,
        [input_base](auto value, auto digit) {
            return value * input_base + digit;
        }
    );

    // Create output digits, but backwards.
    auto output_digits = std::vector<unsigned>{};
    for (; value > 0U; value /= output_base) {
        output_digits.emplace_back(value % output_base);
    }

    // Fix the backwards ordering on return by reversing the output.
    return {output_digits.rbegin(), output_digits.rend()};
}

} // namespace all_your_base
