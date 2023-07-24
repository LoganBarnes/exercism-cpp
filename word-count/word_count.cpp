#include "word_count.h"

namespace word_count {
namespace {

auto to_lower(char ch) {
    return static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
}

auto is_word(char ch) {
    auto const uch = static_cast<char>(ch);
    return !std::isspace(uch) && !std::ispunct(uch);
}

} // namespace

auto words(std::string const& phrase) -> std::map<std::string, int> {
    auto result = std::map<std::string, int>{};

    if (phrase.empty()) {
        return result;
    }

    struct CharState {
        char c       = '\0';
        bool is_word = false;
    };

    CharState curr = {phrase.front(), is_word(phrase.front())};
    CharState next;
    auto      word = std::string{};

    for (auto i = 1u; i < phrase.size(); ++i) {
        next = {phrase[i], is_word(phrase[i])};

        if (curr.is_word) {
            word += to_lower(curr.c);
        } else if (!word.empty()) {
            if (curr.c == '\'' && next.is_word) {
                word += curr.c;
            } else {
                ++result[word];
                word.clear();
            }
        }

        curr = next;
    }

    if (curr.is_word) {
        word += to_lower(curr.c);
    }

    if (!word.empty()) {
        ++result[word];
    }

    return result;
}

} // namespace word_count
