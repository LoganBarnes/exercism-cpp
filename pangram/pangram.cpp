#include "pangram.h"

#include <range/v3/view.hpp>
#include <unordered_set>

namespace pangram {

auto is_pangram(std::string const& pangram) -> bool {
    using namespace ranges;

    auto unique_letters  = pangram
        | views::transform([] (char c) { return std::tolower(c); })
        | views::filter([] (char c) { return 'a' <= c && c <= 'z'; })
        | to<std::unordered_set>();

    return unique_letters.size() == 26;
}

} // namespace pangram
