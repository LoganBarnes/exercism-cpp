#include "roman_numerals.h"

#include <sstream>
#include <stdexcept>

namespace roman_numerals {

auto convert(int i) -> std::string {
    if (0 >= i || i > 3'999) {
        throw std::domain_error{"i must be positive and less than 3,999"};
    }

    constexpr auto chars = std::array{"I", "V", "X", "L", "C", "D", "M"};

    auto result = std::vector<std::string>{};

    auto offset = 1u;

    auto digit = i % 10;
    result.emplace_back();

    while (i > 0) {
        auto const index = (result.size() - 1u) * 2u;

        switch (digit) {
            case 3:
                result.back() += chars.at(index);
            case 2:
                result.back() += chars.at(index);
            case 1:
                result.back() += chars.at(index);
                break;

            case 4:
                result.back() += chars.at(index);
            case 5:
            case 6:
            case 7:
            case 8:
                result.back() += chars.at(index + offset);
                break;

            default:
                break;
        }

        if (digit > 5) {
            digit -= 5;
            offset = 2;
        } else {
            i /= 10;
            digit  = i % 10;
            offset = 1;
            result.emplace_back();
        }
    }

    std::stringstream res;
    std::copy(
        result.rbegin(),
        result.rend(),
        std::ostream_iterator<std::string>(res, "")
    );
    return res.str();
}

} // namespace roman_numerals
