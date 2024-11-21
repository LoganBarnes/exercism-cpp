#pragma once

#include <string>

namespace say {

/// \brief Transform non-negative number less than one trillion
///        (1,000,000,000,000) into a plain string english.
/// \throws std::domain_error if number is outside the specified range.
auto in_english(int64_t input) -> std::string;

} // namespace say
