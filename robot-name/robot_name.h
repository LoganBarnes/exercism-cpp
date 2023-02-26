#pragma once

#include <list>
#include <string>

namespace robot_name {

class robot {
public:
    explicit robot();
    auto reset() -> void;
    auto name() const -> std::string const&;

private:
    // std::list<std::string> potential_names_;
    std::string            name_;
};

} // namespace robot_name
