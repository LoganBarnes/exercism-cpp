#include "rna_transcription.h"

#include <algorithm>
#include <map>

namespace rna_transcription {

auto to_rna(char dna) -> char {
    auto static dna_to_rna = std::map{
        std::make_pair('G', 'C'),
        std::make_pair('C', 'G'),
        std::make_pair('T', 'A'),
        std::make_pair('A', 'U'),
    };
    if (auto iter = dna_to_rna.find(dna); iter != dna_to_rna.end()) {
        return iter->second;
    } else {
        throw std::invalid_argument("Invalid dna strand: " + std::string{dna});
    }
}

auto to_rna(std::string nucleotides) -> std::string {
    std::transform(
        nucleotides.begin(),
        nucleotides.end(),
        nucleotides.begin(),
        [](char c) { return to_rna(c); }
    );
    return nucleotides;
}

} // namespace rna_transcription
