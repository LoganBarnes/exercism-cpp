#include "food_chain.h"

#include <sstream>
#include <type_traits>

namespace food_chain {
namespace {

enum class Animal { Fly, Spider, Bird, Cat, Dog, Goat, Cow, Horse };

template <Animal A>
constexpr auto previous() {
    static_assert(A != Animal::Fly, "Fly has no previous animal");
    return static_cast<Animal>( static_cast<std::underlying_type_t<Animal>>(A) - 1 );
}

// Using SFINAE here just for fun.
template <Animal A>
struct AnimalAction;

template<>
struct AnimalAction<Animal::Spider> {
    static constexpr auto action = " that wriggled and jiggled and tickled inside her";
};

template <Animal A>
auto animal_action(int) -> decltype(AnimalAction<A>::action, std::string{}) {
    return AnimalAction<A>::action;
}

template <Animal A>
auto animal_action(unsigned ) -> std::string {
    return "";
}

template <Animal A>
auto animal() -> std::string {
    switch (A) {
        case Animal::Fly:    return "fly";
        case Animal::Spider: return "spider";
        case Animal::Bird:   return "bird";
        case Animal::Cat:    return "cat";
        case Animal::Dog:    return "dog";
        case Animal::Goat:   return "goat";
        case Animal::Cow:    return "cow";
        case Animal::Horse:  return "horse";
    }
    throw std::invalid_argument("Invalid animal type");
}

template <Animal A>
auto exclamation() -> std::string {
    switch (A) {
        case Animal::Fly:    return "";
        case Animal::Spider: return "It wriggled and jiggled and tickled inside her.\n";
        case Animal::Bird:   return "How absurd to swallow a bird!\n";
        case Animal::Cat:    return "Imagine that, to swallow a cat!\n";
        case Animal::Dog:    return "What a hog, to swallow a dog!\n";
        case Animal::Goat:   return "Just opened her throat and swallowed a goat!\n";
        case Animal::Cow:    return "I don't know how she swallowed a cow!\n";
        case Animal::Horse:  return "";
    }
    throw std::invalid_argument("Invalid animal type");
}

template <Animal A>
auto phrases() -> std::string {
    return "She swallowed the " + animal<A>() + " to catch the "
         + animal<previous<A>()>() + animal_action<previous<A>()>(0) + ".\n"
         + phrases<previous<A>()>();
}

template <>
auto phrases<Animal::Fly>() -> std::string {
    return "I don't know why she swallowed the fly. Perhaps she'll die.\n";
}

template <>
auto phrases<Animal::Horse>() -> std::string {
    return "She's dead, of course!\n";
}

template <Animal A>
auto verse() -> std::string {
    return "I know an old lady who swallowed a " + animal<A>() + ".\n"
           + exclamation<A>()
           + phrases<A>();
}

} // namespace

auto verse(int const n) -> std::string {
    switch (n) {
        case 1: return verse<Animal::Fly>();
        case 2: return verse<Animal::Spider>();
        case 3: return verse<Animal::Bird>();
        case 4: return verse<Animal::Cat>();
        case 5: return verse<Animal::Dog>();
        case 6: return verse<Animal::Goat>();
        case 7: return verse<Animal::Cow>();
        case 8: return verse<Animal::Horse>();
    }
    throw std::invalid_argument("Invalid verse number [1-8]");
}

auto verses(int start, int end) -> std::string {
    auto stream = std::stringstream{};

    for (auto i = start; i <= end; ++i) {
        stream << verse(i) << "\n";
    }

    return stream.str();
}

auto sing() -> std::string {
    return verses(1, 8);
}

} // namespace food_chain
