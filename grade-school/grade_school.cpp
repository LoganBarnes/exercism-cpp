#include "grade_school.h"

namespace grade_school {

auto school::add(std::string name, Grade grade) -> void {
    auto& names = roster_[grade];
    if (auto iter = std::lower_bound(names.begin(), names.end(), name);
        iter != names.end()) {
        names.insert(iter, name);
    } else {
        names.emplace_back(name);
    }
}

auto school::grade(Grade grade) const -> NameList {
    if (auto iter = roster_.find(grade); iter != roster_.end()) {
        return iter->second;
    } else {
        return {};
    }
}

auto school::roster() const -> GradeToNamesMap const& {
    return roster_;
}

} // namespace grade_school
