#pragma once

#include <string>
#include <vector>
#include <numeric>

namespace speedywagon {

struct pillar_men_sensor {
    int              activity = {};
    std::string      location = {};
    std::vector<int> data     = {};
};

inline auto uv_light_heuristic(std::vector<int> const* const data_array) {
    auto const sum = std::accumulate(data_array->begin(), data_array->end(), 0);
    auto const avg = static_cast<double>(sum) / static_cast<double>(data_array->size());

    return static_cast<int>(std::count_if(data_array->begin(), data_array->end(), [avg](auto const element) { return element > avg; })) + 1;
}

inline auto connection_check(pillar_men_sensor const* const sensor) { return nullptr != sensor; }

inline auto activity_counter(pillar_men_sensor const* const sensors, size_t const size){
    return std::accumulate(sensors, sensors + size, 0, [](auto total, auto const& sensor) { return total + sensor.activity;} );
}

inline auto alarm_control(pillar_men_sensor const* const sensor) { return sensor && (sensor->activity > 0); }

inline auto uv_alarm(pillar_men_sensor const* const sensor) { return sensor && (uv_light_heuristic(&sensor->data) > sensor->activity); }

} // namespace speedywagon
