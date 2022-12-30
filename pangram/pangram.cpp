#include "pangram.h"

#include <unordered_set>

namespace pangram {

auto is_pangram(std::string const& pangram) -> bool {
    auto set = std::unordered_set<char>{};
    for (char c : pangram) {
        auto lower = std::tolower(c);
        if ('a' <= lower && lower <= 'z') {
            set.emplace(lower);
        }
    }

    return set.size() == 26;
}

}  // namespace pangram
