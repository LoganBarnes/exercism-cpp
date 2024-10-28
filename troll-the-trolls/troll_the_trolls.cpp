#include <utility>

namespace hellmath {
namespace {

template <typename Enum>
constexpr auto to_underlying(Enum e) { // defined in C++23
    return static_cast<std::underlying_type_t<Enum>>(e);
}

} // namespace

// TODO: Task 1 - Define an `AccountStatus` enumeration to represent the four
// account types: `troll`, `guest`, `user`, and `mod`.
enum class AccountStatus {
    troll,
    guest,
    user,
    mod,
};

// TODO: Task 1 - Define an `Action` enumeration to represent the three
// permission types: `read`, `write`, and `remove`.
enum class Action {
    read,
    write,
    remove,
};

// TODO: Task 2 - Implement the `display_post` function, that gets two arguments
// of `AccountStatus` and returns a `bool`. The first argument is the status of
// the poster, the second one is the status of the viewer.
auto display_post(AccountStatus poster_status, AccountStatus viewer_status) {
    return poster_status != AccountStatus::troll
        || viewer_status == AccountStatus::troll;
}

// TODO: Task 3 - Implement the `permission_check` function, that takes an
// `Action` as a first argument and an `AccountStatus` to check against. It
// should return a `bool`.
auto permission_check(Action action, AccountStatus status) {
    bool has_permission = false;
    switch (status) {
        case AccountStatus::mod:
            has_permission = (action == Action::remove);
            // fallthrough
        case AccountStatus::user:
        case AccountStatus::troll:
            has_permission = has_permission || (action == Action::write);
            // fallthrough
        case AccountStatus::guest:
            has_permission = has_permission || (action == Action::read);
            break;
    }
    return has_permission;
}

// TODO: Task 4 - Implement the `valid_player_combination` function that
// checks if two players can join the same game. The function has two parameters
// of type `AccountStatus` and returns a `bool`.
auto valid_player_combination(AccountStatus player1, AccountStatus player2) {
    auto pair = std::make_pair(player1, player2);
    return pair == std::make_pair(AccountStatus::troll, AccountStatus::troll)
        || pair == std::make_pair(AccountStatus::user, AccountStatus::user)
        || pair == std::make_pair(AccountStatus::user, AccountStatus::mod)
        || pair == std::make_pair(AccountStatus::mod, AccountStatus::user)
        || pair == std::make_pair(AccountStatus::mod, AccountStatus::mod);
}

// TODO: Task 5 - Implement the `has_priority` function that takes two
// `AccountStatus` arguments and returns `true`, if and only if the first
// account has a strictly higher priority than the second.
auto has_priority(AccountStatus player1, AccountStatus player2) {
    return to_underlying(player1) > to_underlying(player2);
}

} // namespace hellmath
