#include "series.h"

#include <stdexcept>

namespace series {

auto slice(std::string const& input, int const length)
    -> std::vector<std::string> {

    if (input.empty() //
        || length <= 0 //
        || static_cast<unsigned>(length) > input.size()) {
        throw std::domain_error("length must be positive");
    }
    auto const len = static_cast<unsigned>(length);

    auto result = std::vector<std::string>{};
    result.reserve(input.size() - len + 1);

    for (auto i = 0u; i + len <= input.size(); ++i) {
        result.emplace_back(input.substr(i, len));
    }
    return result;
}

} // namespace series
