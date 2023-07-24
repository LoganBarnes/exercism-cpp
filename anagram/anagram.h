#pragma once

#include <map>
#include <string>
#include <vector>

namespace anagram {

class anagram {
public:
    explicit anagram(std::string word);

    auto matches(std::vector<std::string> words) -> std::vector<std::string>;

private:
    std::string         word_;
    std::map<char, int> occurrences_;
};

} // namespace anagram
