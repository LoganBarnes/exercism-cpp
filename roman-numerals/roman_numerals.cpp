#include "roman_numerals.h"

#include <array>
#include <stdexcept>
#include <vector>

namespace roman_numerals {
namespace {

constexpr auto roman_chars = std::array{'I', 'V', 'X', 'L', 'C', 'D', 'M'};

auto convert_digit(unsigned digit, char ones_char, char five_or_tens_char) {
    auto roman_number = std::string{};

    switch (digit) {
        case 3u:
            roman_number += ones_char; // fallthrough
        case 2u:
            roman_number += ones_char; // fallthrough
        case 1u:
            roman_number += ones_char;
            break;

        case 4u:
            roman_number += ones_char; // fallthrough
        case 5u: // fallthrough
        case 6u: // fallthrough
        case 7u: // fallthrough
        case 8u:
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

    auto digits = std::vector<unsigned>{};

    for (; i > 0; i /= 10) {
        digits.emplace_back(i % 10u);
    }

    auto roman_number = std::string{};

    auto* ones_iter          = roman_chars.data() + ((digits.size() - 1u) * 2u);
    auto* fives_or_tens_iter = ones_iter + 1u;

    do {
        auto const digit = digits.back();
        digits.pop_back();

        roman_number += convert_digit(digit, *ones_iter, *fives_or_tens_iter);

        if (digit > 5) {
            digits.emplace_back(digit - 5);
            fives_or_tens_iter = ones_iter + 2u;
        } else {
            ones_iter -= 2u;
            fives_or_tens_iter = ones_iter + 1u;
        }
    } while (!digits.empty());

    return roman_number;
}

} // namespace roman_numerals
