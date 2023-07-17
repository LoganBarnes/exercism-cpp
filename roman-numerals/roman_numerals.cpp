#include "roman_numerals.h"

#include <array>
#include <stdexcept>

namespace roman_numerals {
namespace {

constexpr auto roman_chars = std::array{'I', 'V', 'X', 'L', 'C', 'D', 'M'};

auto convert_digit(char digit, char ones_char, char five_or_tens_char) {
    auto roman_number = std::string{};

    switch (digit) {
        case '3':
            roman_number += ones_char; // fallthrough
        case '2':
            roman_number += ones_char; // fallthrough
        case '1':
            roman_number += ones_char;
            break;

        case '4':
            roman_number += ones_char; // fallthrough
        case '5': // fallthrough
        case '6': // fallthrough
        case '7': // fallthrough
        case '8':
            roman_number += five_or_tens_char;
            break;

        default:
            break;
    }

    return roman_number;
}

} // namespace

auto convert(unsigned i) -> std::string {
    if (0u == i || i > 3'999u) {
        throw std::domain_error{"i must be positive and less than 3,999"};
    }

    auto digits = std::to_string(i);
    std::reverse(digits.begin(), digits.end());

    auto roman_number = std::string{};

    auto* ones_iter          = roman_chars.data() + ((digits.size() - 1u) * 2u);
    auto* fives_or_tens_iter = ones_iter + 1u;

    do {
        auto const digit = digits.back();
        digits.pop_back();

        roman_number += convert_digit(digit, *ones_iter, *fives_or_tens_iter);

        if (digit > '5') {
            digits += digit - 5;
            fives_or_tens_iter = ones_iter + 2u;
        } else {
            ones_iter -= 2u;
            fives_or_tens_iter = ones_iter + 1u;
        }
    } while (!digits.empty());

    return roman_number;
}

} // namespace roman_numerals
