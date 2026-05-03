#include "alphametics.h"

#include <algorithm>
#include <unordered_set>
#include <vector>

// #define PRINT_STUFF

#if defined(PRINT_STUFF)
#include <iostream>
#endif

namespace alphametics {
namespace {

auto is_alpha(char const ch) {
    return static_cast<bool>(std::isalpha(static_cast<unsigned char>(ch)));
}

auto is_space(char const ch) {
    return static_cast<bool>(std::isspace(static_cast<unsigned char>(ch)));
}

auto remove_whitespace(std::string str) {
    auto const last = std::remove_if(str.begin(), str.end(), is_space);
    str.erase(last, str.end());
    return str;
}

struct NumbersAndSum {
    std::vector<std::string> numbers = {};
    std::string              sum     = {};
};

auto split(std::string_view const str, char const delim) {
    auto splits = std::vector<std::string_view>();

    auto start     = size_t{0U};
    auto delim_pos = std::string::npos;
    do {
        delim_pos = str.find(delim, start);
        splits.push_back(str.substr(start, delim_pos - start));
        start = delim_pos + 1U;
    } while (delim_pos != std::string::npos);

    return splits;
}

} // namespace

auto solve(std::string str) -> std::optional<std::unordered_map<char, int>> {

#if defined(PRINT_STUFF)
    std::cout << str << std::endl;
#endif

    str = remove_whitespace(str);

#if defined(PRINT_STUFF)
    std::cout << str << std::endl;
#endif

    auto const equals = str.find("==");
    if (equals == std::string_view::npos) {
        return std::nullopt;
    }

    auto const numbers_string = str.substr(0, equals);
    auto const sum_string     = str.substr(equals + 2);
    auto const number_strings = split(numbers_string, '+');
    auto       letters        = std::unordered_set<char>{};
    std::copy_if(str.begin(), str.end(), std::inserter(letters, letters.end()), is_alpha);

#if defined(PRINT_STUFF)
    std::cout << sum_string << std::endl;
    std::cout << numbers_string << std::endl;
    for (auto const& number : number_strings) {
        std::cout << "\t" << number << std::endl;
    }
#endif

    return std::nullopt;
}

} // namespace alphametics
