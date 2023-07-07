#include "beer_song.h"

#include <array>
#include <sstream>

namespace beer_song
{
namespace
{

auto bottle_string( int n ) -> std::string
{
    if ( n == 0 )
    {
        return "no more bottles";
    }
    else if ( n == 1 )
    {
        return "1 bottle";
    }
    else
    {
        return std::to_string( n ) + " bottles";
    }
}

auto action_string( int n ) -> std::string
{
    if ( n == 0 )
    {
        return "Go to the store and buy some more";
    }
    else if ( n == 1 )
    {
        return "Take it down and pass it around";
    }
    else
    {
        return "Take one down and pass it around";
    }
}

} // namespace

auto verse( int n ) -> std::string
{
    auto current_bottles   = bottle_string( n );
    auto action            = action_string( n );
    auto remaining_bottles = bottle_string( n ? n - 1 : 99 );

    auto buf = std::array< char, 256 >{ };

    std::snprintf(
        buf.data( ),
        sizeof( buf ),
        "%s of beer on the wall, %s of beer.\n"
        "%s, %s of beer on the wall.\n",
        current_bottles.c_str( ),
        current_bottles.c_str( ),
        action.c_str( ),
        remaining_bottles.c_str( )
    );

    // Capitalize the first letter of the verse.
    buf[ 0 ] = std::toupper( buf[ 0 ] );

    return buf.data( );
}

auto sing( int start, int end ) -> std::string
{
    auto stream = std::stringstream{ };
    for ( auto i = start; i >= end; --i )
    {
        stream << verse( i ) << ( i != end ? "\n" : "" );
    }

    return stream.str( );
}

} // namespace beer_song
