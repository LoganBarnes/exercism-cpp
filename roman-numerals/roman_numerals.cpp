#include "roman_numerals.h"

#include <array>
#include <stdexcept>
#include <vector>

namespace roman_numerals {
namespace {

constexpr auto roman_chars = std::array{'I', 'V', 'X', 'L', 'C', 'D', 'M', ' '};

auto evaluate_digit(unsigned digit, char ones_char, char five_or_tens_char) {
    auto roman_number = std::string{};

    switch (digit) {
        case 3u:
            roman_number += ones_char;
        case 2u:
            roman_number += ones_char;
        case 1u:
            roman_number += ones_char;
            break;

        case 4u:
            roman_number += ones_char;
        case 5u:
        case 6u:
        case 7u:
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
    digits.reserve(4u);

    for (; i > 0; i /= 10) {
        digits.emplace_back(i % 10u);
    }

    auto roman_result = std::string{};
    roman_result.reserve(12u); // Longest is MMMCCCXXXIII.

    auto index  = (digits.size() - 1u) * 2u;
    auto offset = 1u;

    do {
        auto const digit = digits.back();
        digits.pop_back();

        roman_result += evaluate_digit(
            digit, roman_chars.at(index), roman_chars.at(index + offset)
        );

        if (digit > 5) {
            digits.emplace_back(digit - 5);
            offset = 2u;
        } else {
            index -= 2u; // This will underflow as the loop exits.
            offset = 1u;
        }
    } while (!digits.empty());

    return roman_result;
}

} // namespace roman_numerals
