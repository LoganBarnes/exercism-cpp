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

    auto word = std::string{};

    for (auto ch : phrase) {
        auto c = to_lower(ch);

        if (is_word(c)) {
            word += c;
        } else if (!word.empty()) {
            if (c == '\'') {
                word += c;
            } else {
                ++result[word.substr(0, word.size() - (word.back() == '\''))];
                word.clear();
            }
        }
    }

    if (!word.empty()) {
        ++result[word.substr(0, word.size() - (word.back() == '\''))];
    }

    return result;
}

} // namespace word_count
