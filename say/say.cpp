#include "say.h"

#include <array>
#include <iterator>
#include <limits>
#include <regex>
#include <sstream>
#include <vector>

namespace say {
namespace {

auto join(std::vector<std::string> const& strings, char const* delim = "") {
    auto os = std::ostringstream{};
    std::copy(
        strings.begin(),
        strings.end(),
        std::ostream_iterator<std::string>(os, delim)
    );
    return os.str();
}

auto ones_in_english(unsigned long long number) -> std::string {
    if (number > 9) {
        throw std::domain_error("ones_in_english: " + std::to_string(number));
    }

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
        "nine"
    }[number];
}

auto tens_in_english(unsigned long long number) -> std::string {
    if (9 < number) {
        throw std::domain_error("tens_in_english: " + std::to_string(number));
    }

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
        "ninety"
    }[number];
}

auto below_1000_in_english(unsigned long long number) -> std::string {
    if (999 < number) {
        throw std::domain_error(
            "below_1000_in_english: " + std::to_string(number)
        );
    }

    if (9 < number && number < 17) {
        return std::array{
            "ten",
            "eleven",
            "twelve",
            "thirteen",
            "fourteen",
            "fifteen",
            "sixteen"
        }[number % 10];
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

    words[Index::Ones] = ones_in_english(number % 10);
    number /= 10;
    words[Index::Tens] = number > 0 ? tens_in_english(number % 10) : "";
    number /= 10;
    words[Index::HundredsNumber] = number > 0 ? ones_in_english(number) : "";

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

auto in_english(long long input) -> std::string {
    constexpr auto upper_bound = 999'999'999'999LL;
    static_assert(std::numeric_limits<long long>::max() > upper_bound);

    if (upper_bound < input || input < 0) {
        throw std::domain_error("in_english: " + std::to_string(input));
    }

    auto number = static_cast<unsigned long long>(input);

    if (number == 0ULL) {
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

    for (auto index :
         {Index::Hundreds,
          Index::ThousandsNumber,
          Index::MillionsNumber,
          Index::BillionsNumber}) {
        words[index] = below_1000_in_english(number % 1'000ULL);
        number /= 1'000ULL;

        if (number == 0) {
            break;
        }
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
