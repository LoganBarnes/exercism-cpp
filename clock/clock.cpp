#include "clock.h"

namespace date_independent
{

clock::clock( int hours, int minutes )
{
    hours_   = ( hours + minutes / 60 ) % 24;
    minutes_ = minutes % 60;
    if ( minutes_ < 0 )
    {
        minutes_ += 60;
        hours_ -= 1;
    }
    if ( hours_ < 0 )
    {
        hours_ += 24;
    }
}

auto clock::plus( int minutes ) const -> clock
{
    return clock( hours_, minutes_ + minutes );
}

auto clock::at( int hours, int minutes ) -> clock
{
    return clock( hours, minutes );
}

clock::operator std::string( ) const
{
    auto digitize = []( int number ) -> std::string { return ( number < 10 ? "0" : "" ) + std::to_string( number ); };

    return digitize( hours_ ) + ":" + digitize( minutes_ );
}

auto clock::operator==( clock const& other ) const -> bool
{
    return std::tie( hours_, minutes_ ) == std::tie( other.hours_, other.minutes_ );
}

auto clock::operator!=( clock const& other ) const -> bool
{
    return !( *this == other );
}

} // namespace date_independent
