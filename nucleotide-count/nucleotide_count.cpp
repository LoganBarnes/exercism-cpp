#include "nucleotide_count.h"

namespace nucleotide_count {

counter::counter(std::string const& dna)
    : nucleotide_counts_{{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}} {

    for (char c : dna) {
        auto iter = nucleotide_counts_.find(c);
        if (iter == nucleotide_counts_.end()) {
            throw std::invalid_argument(
                "Found invalid nucleotide: " + std::string{c}
            );
        }
        ++(iter->second);
    }
}

auto counter::nucleotide_counts() const -> std::map<char, int> const& {
    return nucleotide_counts_;
}

} // namespace nucleotide_count
