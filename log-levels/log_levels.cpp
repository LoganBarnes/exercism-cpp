#include <string>

namespace log_line {

auto message(std::string const& line) -> std::string {
    return line.substr(line.find(':') + 2);
}

auto log_level(std::string const& line) -> std::string {
    return line.substr(1, line.find(']') - 1);
}

auto reformat(std::string const& line) -> std::string {
    return message(line) + " (" + log_level(line) + ")";
}

} // namespace log_line
