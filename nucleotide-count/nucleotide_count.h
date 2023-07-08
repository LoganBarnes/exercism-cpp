#pragma once

#include <map>
#include <string>

namespace nucleotide_count {

auto count(std::string const& dna) -> std::map<char, int>;

} // namespace nucleotide_count
