#include "roman_numerals.h"

#include <deque>
#include <sstream>
#include <stdexcept>

namespace roman_numerals {

auto convert(unsigned i) -> std::string {
    if (0 == i || i > 3'999u) {
        throw std::domain_error{"i must be positive and less than 3,999"};
    }

    auto digits = std::vector<unsigned>{};
    digits.reserve(4u);

    while (digits.size() < 4u) {
        digits.emplace_back(i % 10u);
        i /= 10u;
    }
    std::reverse(digits.begin(), digits.end());

    //    constexpr auto roman_chars = std::array{"I", "V", "X", "L", "C", "D", "M"};
    constexpr auto roman_chars = std::array{'M', 'D', 'C', 'L', 'X', 'V', 'I'};

    auto roman_result = std::string{};

    auto offset = 1u;

    for (auto index = 0u, digit = digits[index]; index < digits.size();
         /* no-op */) {

        switch (digit) {
            case 3:
                roman_result += roman_chars.at(index * 2);
            case 2:
                roman_result += roman_chars.at(index * 2);
            case 1:
                roman_result += roman_chars.at(index * 2);
                break;

            case 4:
                roman_result += roman_chars.at(index * 2);
            case 5:
            case 6:
            case 7:
            case 8:
                roman_result += roman_chars.at(index * 2 - offset);
                break;

            default:
                break;
        }

        if (digit > 5) {
            digit -= 5;
            offset = 2;
        } else {
            ++index;
            digit  = (index < digits.size() ? digits.at(index) : 0);
            offset = 1;
        }
    }

    return roman_result;
}

} // namespace roman_numerals
