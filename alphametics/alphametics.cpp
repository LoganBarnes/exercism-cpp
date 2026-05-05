#include "alphametics.h"

#include <algorithm>
#include <numeric>
#include <string>
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

struct ToNumber {
    CharNumberMap const& key;

    auto operator()(std::string const& str) const {
        auto scale  = 1;
        auto result = 0;
        for (auto iter = str.crbegin(); iter != str.crend(); ++iter) {
            auto const ch = *iter;
            if (key.find(ch) == key.end()) {
                throw std::runtime_error("Key does not contain " + std::string{ch});
            }
            auto const digit = key.at(ch);
            result += digit * scale;
            scale *= 10;
        }
        return result;
    }
};

auto sum(std::vector<std::string> const& addends, CharNumberMap const& key) {
    auto numbers = std::vector<int>(addends.size(), 0);
    std::transform(addends.begin(), addends.end(), numbers.begin(), ToNumber{key});
    return std::accumulate(numbers.begin(), numbers.end(), 0);
}

auto check_solution(std::vector<std::string> const& addends, std::string const& sum_str, CharNumberMap const& key) {
#if defined(PRINT_STUFF)
    std::cout << "Key: ";
    for (auto const& [ch, i] : key) {
        std::cout << "{" << ch << ":" << i << "}";
    }
    std::cout << std::endl;
#endif
    auto const lhs = sum(addends, key);
    auto const rhs = sum({sum_str}, key);

    return lhs == rhs;
}

auto solve(
    CharNumberMap const&            key,
    std::vector<std::string> const& addends,
    std::string const&              sum_str,
    std::unordered_set<char> const& letters,
    std::unordered_set<int> const&  numbers,
    std::unordered_set<char> const& non_zero_letters
) -> std::optional<CharNumberMap> {

    if (letters.empty()) {
        if (check_solution(addends, sum_str, key)) {
            return key;
        }
        return std::nullopt;
    }

    for (auto i : numbers) {
        auto const ch = *letters.begin();

        if (0 == i && non_zero_letters.find(ch) != non_zero_letters.end()) {
            continue;
        }

        auto current_key       = key;
        auto remaining_letters = letters;
        auto remaining_numbers = numbers;
        current_key.try_emplace(ch, i);

        remaining_numbers.erase(i);
        remaining_letters.erase(ch);
        if (auto result
            = solve(current_key, addends, sum_str, remaining_letters, remaining_numbers, non_zero_letters)) {
            return result;
        }
    }

    return std::nullopt;
}

} // namespace

auto solve(std::string_view const str) -> std::optional<CharNumberMap> {
    bool new_number       = true;
    bool is_sum           = false;
    auto letters          = std::unordered_set<char>{};
    auto non_zero_letters = std::unordered_set<char>{};
    auto addends          = std::vector<std::string>{};
    auto sum              = std::string{};

    auto const char_count = str.size();
    for (auto i = 0UL; i < char_count; ++i) {
        auto const ch = str[i];

        if ('=' == ch) {
            is_sum     = true;
            new_number = true;

        } else if ('+' == ch) {
            new_number = true;

        } else if (is_alpha(ch)) {
            letters.insert(ch);

            if (is_sum) {
                sum.push_back(ch);

            } else {
                if (new_number) {
                    addends.emplace_back();
                }
                addends.back().push_back(ch);
            }

            if (new_number) {
                non_zero_letters.insert(ch);
                new_number = false;
            }

        } else {
            // whitespace can be ignored
        }
    }

    if (!is_sum) {
        return std::nullopt;
    }
    if (letters.size() > 10U) {
        return std::nullopt;
    }

#if defined(PRINT_STUFF)
    std::cout << str << std::endl;

    std::cout << "{ ";
    for (auto const ch : letters) {
        std::cout << ch << " ";
    }
    std::cout << "}" << std::endl;

    std::cout << sum << std::endl;
    for (auto const& addend : addends) {
        std::cout << "\t" << addend << std::endl;
    }

#endif

    auto ordered_numbers = std::vector<int>(10);
    std::iota(ordered_numbers.begin(), ordered_numbers.end(), 0);
    auto numbers = std::unordered_set<int>{ordered_numbers.begin(), ordered_numbers.end()};

    return solve(CharNumberMap{}, addends, sum, letters, numbers, non_zero_letters);
}

} // namespace alphametics
