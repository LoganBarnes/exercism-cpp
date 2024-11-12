#include "say.h"

#include <array>
#include <cassert>
#include <iterator>
#include <limits>
#include <ranges>
#include <regex>
#include <sstream>
#include <vector>

namespace say {
namespace {

using ull = unsigned long long;

auto join(std::vector<std::string> const& strings, char const* delim = "") {
    auto os = std::ostringstream{};
    std::ranges::copy(strings, std::ostream_iterator<std::string>(os, delim));
    return os.str();
}

auto ones_in_english(ull const number) -> std::string {
    assert(number < 10UL);

    return std::array{
        "",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
    }[number];
}

auto tens_in_english(ull const number) -> std::string {
    assert(number < 10UL);

    return std::array{
        "",
        "",
        "twenty",
        "thirty",
        "forty",
        "fifty",
        "sixty",
        "seventy",
        "eighty",
        "ninety",
    }[number];
}

auto below_1000_in_english(ull number) -> std::string {
    assert(number < 1'000UL);

    if (9UL < number && number < 20UL) {
        return std::array{
            "ten",
            "eleven",
            "twelve",
            "thirteen",
            "fourteen",
            "fifteen",
            "sixteen",
            "seventeen",
            "eighteen",
            "nineteen",
        }[number % 10UL];
    }

    enum Index {
        HundredsNumber = 0,
        HundredsWord   = 1,
        And            = 2,
        Tens           = 3,
        Hyphen         = 4,
        Ones           = 5,
    };

    auto words = std::vector<std::string>{
        "", // Index::HundredsNumber
        "", // Index::HundredsWord
        "", // Index::And
        "", // Index::Tens
        "", // Index::Hyphen
        "", // Index::Ones
    };

    words[Index::Ones] = ones_in_english(number % 10ULL);
    number /= 10ULL;

    if (number > 0ULL) {
        words[Index::Tens] = tens_in_english(number % 10ULL);
    }
    number /= 10ULL;

    if (number > 0ULL) {
        words[Index::HundredsNumber] = ones_in_english(number);
    }

    if (!words[Index::HundredsNumber].empty()) {
        words[Index::HundredsWord] = " hundred";
    }

    if (!words[Index::Tens].empty() || !words[Index::Ones].empty()) {
        words[Index::And] = " ";
    }

    if (!words[Index::Tens].empty() && !words[Index::Ones].empty()) {
        words[Index::Hyphen] = "-";
    }

    return join(words);
}

} // namespace

auto in_english(long long const input) -> std::string {
    constexpr auto upper_bound = 999'999'999'999LL;
    static_assert(upper_bound < std::numeric_limits<decltype(input)>::max());

    if (upper_bound < input || input < 0LL) {
        throw std::domain_error(std::format("in_english: {}", input));
    }

    if (input == 0LL) {
        return "zero";
    }

    enum Index {
        BillionsNumber  = 0,
        BillionsWord    = 1,
        MillionsNumber  = 2,
        MillionsWord    = 3,
        ThousandsNumber = 4,
        ThousandsWord   = 5,
        Hundreds        = 6,
    };

    auto words = std::vector<std::string>{
        "", // Index::BillionsNumber,
        "", // Index::BillionsWord,
        "", // Index::MillionsNumber,
        "", // Index::MillionsWord,
        "", // Index::ThousandsNumber,
        "", // Index::ThousandsWord,
        "", // Index::Hundreds,
    };

    auto number = static_cast<ull>(input);

    for (auto index :
         {Index::Hundreds,
          Index::ThousandsNumber,
          Index::MillionsNumber,
          Index::BillionsNumber}) {
        words[index] = below_1000_in_english(number % 1'000ULL);
        number /= 1'000ULL;
    }

    if (!words[Index::BillionsNumber].empty()) {
        words[Index::BillionsWord] = "billion";
    }
    if (!words[Index::MillionsNumber].empty()) {
        words[Index::MillionsWord] = "million";
    }
    if (!words[Index::ThousandsNumber].empty()) {
        words[Index::ThousandsWord] = "thousand";
    }

    return regex_replace(join(words, " "), std::regex("^ +| +$|( ) +"), "$1");
}

} // namespace say
