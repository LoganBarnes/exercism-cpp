#include "grade_school.h"

namespace grade_school {

auto school::add(std::string name, Grade grade) -> void {
    auto& names = roster_[grade];
    names.insert(std::lower_bound(names.begin(), names.end(), name), name);
}

auto school::grade(Grade grade) const -> NameList const& {
    if (auto iter = roster_.find(grade); iter != roster_.end()) {
        return iter->second;
    } else {
        return empty_names_;
    }
}

auto school::roster() const -> GradeToNamesMap const& {
    return roster_;
}

} // namespace grade_school
