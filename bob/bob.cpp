#include "bob.h"

#if 0

#include <algorithm>
#include <string>

namespace bob {

namespace {

auto is_space(char const ch) {
    return static_cast<bool>(std::isspace(static_cast<unsigned char>(ch)));
}

auto is_alpha(char const ch) {
    return static_cast<bool>(std::isalpha(static_cast<unsigned char>(ch)));
}

auto is_upper(char const ch) {
    return static_cast<bool>(std::isupper(static_cast<unsigned char>(ch)));
}

auto remove_whitespace(std::string str) {
    str.erase(std::remove_if(str.begin(), str.end(), is_space), str.end());
    return str;
}

auto letters_only(std::string_view const str) {
    auto letters = std::string{};
    std::copy_if(str.begin(), str.end(), std::back_insert_iterator(letters), is_alpha);
    return letters;
}

} // namespace

auto hey(std::string_view const msg) -> std::string {
    auto const no_whitespace = remove_whitespace(std::string(msg));
    auto const letters       = letters_only(no_whitespace);

    auto const yelling  = !letters.empty() && std::all_of(begin(letters), end(letters), is_upper);
    auto const question = no_whitespace.back() == '?';
    auto const silence  = no_whitespace.empty();

    if (silence) {
        return "Fine. Be that way!";

    } else if (yelling && question) {
        return "Calm down, I know what I'm doing!";

    } else if (yelling) {
        return "Whoa, chill out!";

    } else if (question) {
        return "Sure.";

    } else {
        return "Whatever.";
    }
}

} // namespace bob

#else

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

namespace bob {
namespace {

constexpr char const* SILENCE       = "Fine. Be that way!";
constexpr char const* QUESTION_YELL = "Calm down, I know what I'm doing!";
constexpr char const* YELL          = "Whoa, chill out!";
constexpr char const* QUESTION      = "Sure.";
constexpr char const* ELSE          = "Whatever.";

auto is_space(char const ch) {
    return static_cast<bool>(std::isspace(static_cast<unsigned char>(ch)));
}

auto is_alpha(char const ch) {
    return static_cast<bool>(std::isalpha(static_cast<unsigned char>(ch)));
}

auto is_upper(char const ch) {
    return static_cast<bool>(std::isupper(static_cast<unsigned char>(ch)));
}

bool allUpper(std::string_view const str) {
    return std::all_of(str.begin(), str.end(), is_upper);
}

std::string trim(std::string str) {
    str.erase(std::remove_if(str.begin(), str.end(), is_space), str.end());
    return str;
}

std::string filterString(std::string_view const str) {
    std::string result;
    std::copy_if(str.begin(), str.end(), std::back_inserter(result), is_alpha);
    return result;
}

} // namespace

std::string hey(std::string_view const input) {
    auto const trimmed = trim(std::string(input));
    auto const letters = filterString(trimmed);

    std::cout << letters << " : " << trimmed;

    auto const silence  = trimmed.empty();
    auto const yelling  = !letters.empty() && allUpper(letters);
    auto const question = trimmed.back() == '?';

    if (silence) {
        return SILENCE;

    } else if (yelling && question) {
        return QUESTION_YELL;

    } else if (yelling) {
        return YELL;

    } else if (question) {
        return QUESTION;

    } else {
        return ELSE;
    }
}

} // namespace bob

#endif
