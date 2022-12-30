#pragma once
#include <algorithm>
#include <string>
#include <unordered_set>

namespace pangram {

inline auto is_pangram(std::string s) { // the scrunched version
  auto l = std::unordered_set<int>{};

  transform(s.begin(),s.end(),s.begin(),[](char c){return tolower(c);});
  copy_if(s.begin(),s.end(),inserter(l,l.begin()),[](char c){return isalpha(c);});

  return l.size() == 26;
}

}  // namespace pangram
