#pragma once

#include <string>

namespace date_independent
{

class clock
{
public:
    explicit clock( int hours, int minutes );

    auto plus( int minutes ) const -> clock;

    static auto at( int hours, int minutes ) -> clock;

    explicit operator std::string( ) const;

    auto operator==( clock const& other ) const -> bool;
    auto operator!=( clock const& other ) const -> bool;

private:
    int hours_;
    int minutes_;
};

} // namespace date_independent
