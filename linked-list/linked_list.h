#pragma once

#include <cstddef>
#include <stdexcept>
#include <string>

namespace linked_list {

template <typename T>
class List {
public:
    /// \brief Adds an element to the end of the list,
    auto push(T&& element) -> void;

    /// \brief Removes and returns the last element of the list.
    /// \throws std::domain_error if the list is empty.
    auto pop() -> T;

    /// \brief Removes and returns the first element of the list.
    /// \throws std::domain_error if the list is empty.
    auto shift() -> T;

    /// \brief Adds an element to the start of the list.
    auto unshift(T&& element) -> void;

    /// \brief Returns the total number of elements in the current list.
    [[nodiscard]]
    auto count() const -> std::size_t;

    /// \brief Removes the first occurrence of the given element from the list.
    /// \returns true if the element was found and removed, false otherwise.
    auto erase(T const& element) -> bool;
};

template <typename T>
auto List<T>::push(T&&) -> void {
    throw std::runtime_error(
        std::string{__FUNCTION__} + " not yet implemented"
    );
}

template <typename T>
auto List<T>::pop() -> T {
    throw std::runtime_error(
        std::string{__FUNCTION__} + " not yet implemented"
    );
}

template <typename T>
auto List<T>::shift() -> T {
    throw std::runtime_error(
        std::string{__FUNCTION__} + " not yet implemented"
    );
}

template <typename T>
auto List<T>::unshift(T&&) -> void {
    throw std::runtime_error(
        std::string{__FUNCTION__} + " not yet implemented"
    );
}

template <typename T>
auto List<T>::count() const -> std::size_t {
    throw std::runtime_error(
        std::string{__FUNCTION__} + " not yet implemented"
    );
}

template <typename T>
auto List<T>::erase(T const&) -> bool {
    throw std::runtime_error(
        std::string{__FUNCTION__} + " not yet implemented"
    );
}

} // namespace linked_list
