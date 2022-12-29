#pragma once

#include <vector>

namespace all_your_base {

auto convert(
    unsigned                     input_base,
    std::vector<unsigned> const& input_digits,
    unsigned                     output_base
) -> std::vector<unsigned>;

} // namespace all_your_base
