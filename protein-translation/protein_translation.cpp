#include "protein_translation.h"

#include <unordered_map>

namespace protein_translation {

auto proteins(std::string const& rna) -> std::vector<std::string> {
    static auto const codons = std::unordered_map<std::string, std::string>{
        {"AUG", "Methionine"},
        {"UUU", "Phenylalanine"},
        {"UUC", "Phenylalanine"},
        {"UUA", "Leucine"},
        {"UUG", "Leucine"},
        {"UCU", "Serine"},
        {"UCC", "Serine"},
        {"UCA", "Serine"},
        {"UCG", "Serine"},
        {"UAU", "Tyrosine"},
        {"UAC", "Tyrosine"},
        {"UGU", "Cysteine"},
        {"UGC", "Cysteine"},
        {"UGG", "Tryptophan"},
        {"UAA", "STOP"},
        {"UAG", "STOP"},
        {"UGA", "STOP"},
    };

    auto result = std::vector<std::string>{};

    for (auto i = 3ul; i <= rna.size(); i += 3) {
        auto const codon = rna.substr(i - 3u, 3u);

        auto iter = codons.find(codon);

        if (iter == codons.end()) {
            throw std::domain_error("Invalid codon: " + codon + ".");
        }

        if (iter->second == "STOP") {
            break;
        }

        result.emplace_back(iter->second);
    }

    return result;
}

} // namespace protein_translation
