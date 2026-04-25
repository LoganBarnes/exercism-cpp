#include "yacht.h"

#include <iterator>
#include <numeric>
#include <unordered_set>
#include <vector>

namespace yacht {
namespace {

struct DiceAndCount {
    int value = 0;
    int count = 1;

    DiceAndCount(int dice) : value{dice} {}
};

auto operator<(DiceAndCount const& lhs, DiceAndCount const& rhs) {
    return std::tie(lhs.count, lhs.value) < std::tie(rhs.count, rhs.value);
}

struct Incrementer {
    auto operator()(DiceAndCount& count, DiceAndCount const& other) const {
        if (count.value == other.value) {
            count.count++;
            return true;
        }
        return false;
    }
};

auto dice_info(std::array<int, 5U> const& dices) -> std::vector<DiceAndCount> {
    auto counts = std::vector<DiceAndCount>{};
    std::copy(dices.begin(), dices.end(), std::back_inserter(counts));

    std::sort(counts.begin(), counts.end());

    auto const last = std::unique(counts.begin(), counts.end(), Incrementer{});
    counts.erase(last, counts.end());

    std::sort(counts.begin(), counts.end());
    return counts;
}

struct Contains {
    std::unordered_set<int> values = {};

    auto operator()(int const value) -> bool {
        return values.find(value) != values.end();
    }
};

template <typename Container>
auto sum(Container const& dices) {
    return std::accumulate(std::begin(dices), std::end(dices), 0);
}

template <typename Pred>
auto sum_if(std::array<int, 5U> const& dices, Pred const& predicate) {
    auto to_sum = std::vector<int>{};

    std::copy_if(
        std::begin(dices),
        std::end(dices),
        std::back_inserter(to_sum),
        predicate
    );

    return sum(to_sum);
}

} // namespace

auto score(std::array<int, 5U> const& dices, std::string_view const category)
    -> int {

    if ("ones" == category) {
        return sum_if(dices, Contains{{1}});
    }
    if ("twos" == category) {
        return sum_if(dices, Contains{{2}});
    }
    if ("threes" == category) {
        return sum_if(dices, Contains{{3}});
    }
    if ("fours" == category) {
        return sum_if(dices, Contains{{4}});
    }
    if ("fives" == category) {
        return sum_if(dices, Contains{{5}});
    }
    if ("sixes" == category) {
        return sum_if(dices, Contains{{6}});
    }
    if ("choice" == category) {
        return sum(dices);
    }

    auto const info = dice_info(dices);

    if (("full house" == category) && (2U == info.size())
        && (2 == info.front().count)) {
        return sum(dices);
    }
    if (("four of a kind" == category) && (info.size() <= 2U)
        && (info.back().count >= 4)) {
        return info.back().value * 4;
    }
    if (("little straight" == category) && (5U == info.size())
        && (1 == info.front().value) && (5 == info.back().value)) {
        return 30;
    }
    if (("big straight" == category) && (5U == info.size())
        && (2 == info.front().value) && (6 == info.back().value)) {
        return 30;
    }
    if (("yacht" == category) && (1 == info.size())) {
        return 50;
    }

    return 0;
}

} // namespace yacht
