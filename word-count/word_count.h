#pragma once

#include <map>
#include <string>

namespace word_count {

auto words(std::string const& phrase) -> std::map<std::string, int>;

} // namespace word_count
