#pragma once

#include <map>
#include <string>

namespace nucleotide_count {

class counter {
public:
    explicit counter(std::string const& dna);
    auto nucleotide_counts() const -> std::map<char, int> const&;

private:
    std::map<char, int> nucleotide_counts_;
};

} // namespace nucleotide_count
