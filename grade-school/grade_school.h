#pragma once

#include <map>
#include <string>
#include <vector>

namespace grade_school {

class school {
public:
    using Grade           = int;
    using NameList        = std::vector<std::string>;
    using GradeToNamesMap = std::map<Grade, NameList>;

    auto add(std::string name, Grade grade) -> void;

    auto grade(Grade grade) const -> NameList;
    auto roster() const -> GradeToNamesMap const&;

private:
    GradeToNamesMap roster_;
};

} // namespace grade_school
