#include "high_scores.h"

#include <algorithm>

namespace arcade {

std::vector<int> HighScores::list_scores() {
    return scores_;
}

int HighScores::latest_score() {
    return scores_.empty() ? 0 : scores_.back();
}

int HighScores::personal_best() {
    return scores_.empty() ? 0
                           : *std::max_element(scores_.begin(), scores_.end());
}

std::vector<int> HighScores::top_three() {
    auto sorted_scores = scores_;

    std::sort(sorted_scores.begin(), sorted_scores.end(), std::greater<int>());
    sorted_scores.resize(std::min(sorted_scores.size(), 3ul));

    return sorted_scores;
}

} // namespace arcade
