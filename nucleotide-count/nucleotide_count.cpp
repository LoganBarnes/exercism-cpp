#include "nucleotide_count.h"

namespace nucleotide_count {

auto count(std::string const& dna) -> std::map<char, int> {
    auto counts = std::map<char, int>{{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}};

    for (char c : dna) {
        counts[c]++;
        if (counts.size() > 4) {
            throw std::invalid_argument("Bad value: " + std::string{c});
        }
    }
    return counts;
}

} // namespace nucleotide_count
