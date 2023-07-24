#include "isogram.h"

#include <cctype>
#include <unordered_set>

namespace isogram {
namespace {

auto is_punct(char c) {
    return std::ispunct(static_cast<unsigned char>(c));
}

auto is_space(char c) {
    return std::isspace(static_cast<unsigned char>(c));
}

auto to_lower(char c) {
    return static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
}

} // namespace

auto is_isogram(std::string_view word) -> bool {
    auto chars = std::unordered_set<char>{};

    return !std::any_of(word.begin(), word.end(), [&chars](char c) {
        return !is_punct(c) && !is_space(c)
            && !chars.emplace(to_lower(c)).second;
    });
}

} // namespace isogram
