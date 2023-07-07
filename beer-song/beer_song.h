#pragma once

#include <string>

namespace beer_song
{

auto verse( int n ) -> std::string;

auto sing( int start, int end = 0 ) -> std::string;

} // namespace beer_song
