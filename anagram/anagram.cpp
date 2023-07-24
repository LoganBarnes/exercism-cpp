#include "anagram.h"

#include <algorithm>

namespace anagram {
namespace {

auto to_lower(char c) {
    return static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
}

auto lowercase(std::string word) {
    std::transform(word.begin(), word.end(), word.begin(), to_lower);
    return word;
}

auto count_chars(std::string_view word) {
    auto occurrences = std::map<char, int>{};
    for (char c : word) {
        ++occurrences[c];
    }
    return occurrences;
}

} // namespace

anagram::anagram(std::string word)
    : word_(lowercase(std::move(word)))
    , occurrences_(count_chars(word_)) {}

auto anagram::matches(std::vector<std::string> words)
    -> std::vector<std::string> {

    auto iter = std::remove_if(words.begin(), words.end(), [this](auto word) {
        word = lowercase(word);
        return word == word_ || count_chars(word) != occurrences_;
    });
    words.erase(iter, words.end());

    return words;
}

} // namespace anagram
