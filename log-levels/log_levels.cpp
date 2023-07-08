#include <string>

namespace log_line {

static auto message(std::string const& line) -> std::string {
    return line.substr(line.find(':') + 2);
}

static auto log_level(std::string const& line) -> std::string {
    return line.substr(1, line.find(']') - 1);
}

static auto reformat(std::string const& line) -> std::string {
    return message(line) + " (" + log_level(line) + ")";
}

} // namespace log_line
