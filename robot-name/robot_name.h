#pragma once

#include <string>

namespace robot_name {

class robot {
public:
    explicit robot();
    auto reset() -> void;
    auto name() const -> std::string const&;

private:
    std::string name_;
};

} // namespace robot_name
