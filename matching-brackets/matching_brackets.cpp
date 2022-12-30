#include "matching_brackets.h"

#include <stack>

namespace matching_brackets {

auto check(std::string const& input) -> bool {
    auto s = std::stack<char>{};

    for (char c : input) {
        switch (c) { // Attempting to format like rust :/
        case '{': s.push('}'); break;
        case '[': s.push(']'); break;
        case '(': s.push(')'); break;
        case '}': case ']': case ')':
            if (s.empty() || s.top() != c) { return false; } else { s.pop(); }
            break;
        }
    }
    return s.empty();
}

} // namespace matching_brackets
