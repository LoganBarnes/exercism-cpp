#include "say.h"

#include <array>
#include <cassert>
#include <iterator>
#include <regex>
#include <sstream>
#include <vector>

#define REMOVE_AND

namespace say {
namespace {

constexpr auto words_below_twenty = std::array{
    "",         "one",     "two",     "three",     "four",     "five",     "six",
    "seven",    "eight",   "nine",    "ten",       "eleven",   "twelve",   "thirteen",
    "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
};

constexpr auto tens_words = std::array{
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
};

constexpr auto filler_words = std::array{
    "",
#if defined(REMOVE_AND)
    " ",
#else
    " and ",
#endif
    "-",
    " hundred",
    "thousand",
    "million",
    "billion",
};

constexpr auto and_index      = 1UZ;
constexpr auto hyphen_index   = 2UZ;
constexpr auto hundred_index  = 3UZ;
constexpr auto thousand_index = 4UZ;
constexpr auto million_index  = 5UZ;
constexpr auto billion_index  = 6UZ;

constexpr auto billion  = 1'000'000'000ULL;
constexpr auto million  = 1'000'000ULL;
constexpr auto thousand = 1'000ULL;
constexpr auto hundred  = 100ULL;
constexpr auto ten      = 10ULL;

/// \brief Join a collection of strings into a single string separated by the
///        provided delimiter.
template <template <typename...> typename Container, typename String>
auto join(Container<String> const& strings, std::string_view const delimiter) {
    auto os = std::ostringstream{};
    std::ranges::copy(strings, std::ostream_iterator<String>(os, delimiter.data()));
    return os.str();
}

/// \brief Remove any leading or trailing spaces and remove multiple space occurrences.
auto consolidate_spaces(std::string const& str) {
    return regex_replace(str, std::regex("^ +| +$|( ) +"), "$1");
}

/// \brief Transform a number below 1,000 into a plain english string.
auto below_1000_in_english(uint64_t const number) -> std::string {
    assert(number < 1'000UL);

    auto const ones     = number % ten;
    auto const tens     = (number / ten) % ten;
    auto const hundreds = (number / hundred) % ten;

    auto const has_hundreds = std::min(1ULL, hundreds);
    auto const has_tens     = std::min(1ULL, tens);
    auto const has_ones     = std::min(1ULL, ones);
    auto const is_teen      = static_cast<uint64_t>(1ULL == tens);

    auto const has_and    = (has_ones | has_tens);
    auto const has_hyphen = ((has_ones & has_tens) & (~is_teen));

    auto const words = std::vector<std::string_view>{
        // Hundreds number
        words_below_twenty[hundreds],
        // Hundreds word
        filler_words[has_hundreds * hundred_index],

        // "and" (if implemented)
        filler_words[has_and * and_index],

        // Tens number
        tens_words[tens],

        // Hyphen
        filler_words[has_hyphen * hyphen_index],

        // Teens or ones
        words_below_twenty[(is_teen * 10ULL) + ones],
    };

    return join(words, "");
}

} // namespace

auto in_english(int64_t const input) -> std::string {
    if (constexpr auto upper_bound = 999'999'999'999LL; (input < 0LL) || (upper_bound < input)) {
        throw std::domain_error("input out of range");
    }

    if (0LL == input) {
        return "zero";
    }

    auto const number = static_cast<uint64_t>(input);

    auto const hundreds  = number % thousand;
    auto const thousands = (number / thousand) % thousand;
    auto const millions  = (number / million) % thousand;
    auto const billions  = (number / billion) % thousand;

    auto const has_billions  = std::min(billions, 1ULL);
    auto const has_millions  = std::min(millions, 1ULL);
    auto const has_thousands = std::min(thousands, 1ULL);

    auto const words = std::vector<std::string>{
        // Billions number
        below_1000_in_english(billions),
        // Billions word
        filler_words[has_billions * billion_index],

        // Millions number
        below_1000_in_english(millions),
        // Millions word
        filler_words[has_millions * million_index],

        // Thousands number
        below_1000_in_english(thousands),
        // Thousands word
        filler_words[has_thousands * thousand_index],

        // Hundreds number and words
        below_1000_in_english(hundreds),
    };

    return consolidate_spaces(join(words, " "));
}

} // namespace say
