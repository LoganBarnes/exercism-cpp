#include "beer_song.h"

#include <array>
#include <sstream>

namespace beer_song {
namespace {

auto bottles(int bottles) -> std::string {
    switch (bottles) {
        case -1: return "No more bottles";
        case 0:  return "no more bottles";
        case 1:  return "1 bottle";
    }
    return std::to_string(bottles) + " bottles";
}

auto action(int bottles) -> std::string {
    switch (bottles) {
        case 0: return "Go to the store and buy some more";
        case 1: return "Take it down and pass it around";
    }
    return "Take one down and pass it around";
}

} // namespace

auto verse(int n) -> std::string {
    return (std::stringstream{} << bottles(n == 0 ? -1 : n)
                                << " of beer on the wall, " << bottles(n)
                                << " of beer.\n"
                                << action(n) << ", " << bottles(n ? n - 1 : 99)
                                << " of beer on the wall.\n")
        .str();
}

auto sing(int start, int end) -> std::string {
    auto stream = std::stringstream{};
    for (auto i = start; i >= end; --i) {
        stream << verse(i) << (i != end ? "\n" : "");
    }
    return stream.str();
}

} // namespace beer_song
