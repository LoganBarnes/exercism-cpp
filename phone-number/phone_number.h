#pragma once

#include <string>

namespace phone_number {

class phone_number {
public:
    explicit phone_number(std::string const& number);

    auto number() const -> std::string const&;
    auto area_code() const -> std::string const&;

    explicit operator std::string() const;

private:
    std::string local_number_;
    std::string area_code_;
};

} // namespace phone_number
