#include "say.h"

#include <array>
#include <cassert>
#include <iterator>
#include <regex>
#include <sstream>
#include <vector>

namespace say {
namespace {

constexpr auto low_words = std::array{
    "",         "one",     "two",     "three",     "four",     "five",     "six",
    "seven",    "eight",   "nine",    "ten",       "eleven",   "twelve",   "thirteen",
    "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
};

constexpr auto tens_words = std::
    array{"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

constexpr auto filler_words
    = std::array{"", " ", "-", " hundred", " thousand", " million", " billion"};

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

template <typename... Args>
auto ignore(Args&&...) {
    // Used to explicitly ignore unused return values.
}

template <template <typename...> typename Container, typename String>
auto join(Container<String> const& strings, std::string_view const delim) {
    auto os = std::ostringstream{};
    ignore(std::ranges::copy(strings, std::ostream_iterator<String>(os, delim.data())));
    return os.str();
}

auto consolidate_spaces(std::string const& str) {
    return regex_replace(str, std::regex("^ +| +$|( ) +"), "$1");
}

auto below_1000_in_english(uint64_t const number) -> std::string {
    assert(number < 1'000UL);

    auto const ones     = number % ten;
    auto const tens     = (number / ten) % ten;
    auto const hundreds = (number / hundred) % ten;

    auto const has_hundreds = std::min(1ULL, hundreds);
    auto const has_tens     = std::min(1ULL, tens);
    auto const has_ones     = std::min(1ULL, ones);
    auto const is_teen      = static_cast<uint64_t>(1ULL == tens);

    auto const words = std::vector<std::string_view>{
        low_words[hundreds],
        filler_words[has_hundreds * hundred_index],
        filler_words[(has_ones | has_tens) * and_index],
        tens_words[tens],
        filler_words[((has_ones & has_tens) & (~is_teen)) * hyphen_index],
        low_words[(is_teen * 10ULL) + ones],
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

    auto const words = std::vector<std::string>{
        below_1000_in_english(billions),
        filler_words[std::min(billions, 1ULL) * billion_index],
        below_1000_in_english(millions),
        filler_words[std::min(millions, 1ULL) * million_index],
        below_1000_in_english(thousands),
        filler_words[std::min(thousands, 1ULL) * thousand_index],
        below_1000_in_english(hundreds),
    };

    return consolidate_spaces(join(words, " "));
}

} // namespace say
