#pragma once
#include <string>
#include <unordered_set>

namespace pangram {

inline auto is_pangram(std::string s) -> bool {
    auto set = std::unordered_set<int>{};

    transform(s.begin(), s.end(), s.begin(), [](char c) { return tolower(c); });
    copy_if(s.begin(), s.end(), inserter(set, set.begin()), [](char c) { return 'a' <= c && c <= 'z'; });

    return set.size() == 26;
}

}  // namespace pangram
