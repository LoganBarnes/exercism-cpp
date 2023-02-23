#pragma once

#include <string>

namespace rna_transcription {

auto to_rna(char dna) -> char;

auto to_rna(std::string dna) -> std::string;

} // namespace rna_transcription
