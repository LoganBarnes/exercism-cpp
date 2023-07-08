#include "bob.h"

#include <algorithm>

namespace bob {

auto hey(std::string msg) -> std::string {
    msg.erase(std::remove_if(msg.begin(), msg.end(), isspace), msg.end());

    auto chars = std::string{};
    std::copy_if(msg.begin(), msg.end(), std::back_insert_iterator(chars), isalpha);

    auto const yelling  = !chars.empty() && std::all_of(begin(chars), end(chars), isupper);
    auto const question = msg.back() == '?';
    auto const silence  = msg.empty();

    if (silence) {
        return "Fine. Be that way!";
    } else if (yelling && question) {
        return "Calm down, I know what I'm doing!";
    } else if (yelling) {
        return "Whoa, chill out!";
    } else if (question) {
        return "Sure.";
    } else {
        return "Whatever.";
    }
}

} // namespace bob
