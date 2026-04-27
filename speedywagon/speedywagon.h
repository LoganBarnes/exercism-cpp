#pragma once

#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <vector>

namespace speedywagon {

struct pillar_men_sensor {
    int              activity = {};
    std::string      location = {};
    std::vector<int> data     = {};
};

inline auto uv_light_heuristic(std::vector<int> const* const data) {
    auto const sum = std::accumulate(data->begin(), data->end(), 0);
    auto const avg = static_cast<double>(sum) / static_cast<double>(data->size());

    return static_cast<int>(std::ranges::count_if(*data, std::bind_front(std::less<double>{}, avg))) + 1;
}

inline auto connection_check(pillar_men_sensor const* const s) { return nullptr != s; }

inline auto activity_counter(pillar_men_sensor const* const s, size_t const len) {
    return std::accumulate(s, s + len, 0, [](auto tot, auto const& sen) { return tot + sen.activity; });
}

inline auto alarm_control(pillar_men_sensor const* const s) { return s && (s->activity > 0); }

inline auto uv_alarm(pillar_men_sensor const* const s) { return s && (uv_light_heuristic(&(s->data)) > s->activity); }

} // namespace speedywagon
