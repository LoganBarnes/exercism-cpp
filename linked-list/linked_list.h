#pragma once

#include <memory>
#include <stdexcept>

namespace linked_list {

template <typename T>
class List {
public:
    explicit List();

    /// \brief Adds an element to the end of the list.
    template <typename... Args>
    auto push(Args&&... args) -> void;

    /// \brief Removes and returns the last element of the list.
    /// \throws std::domain_error if the list is empty.
    auto pop() -> T;

    /// \brief Removes and returns the first element of the list.
    /// \throws std::domain_error if the list is empty.
    auto shift() -> T;

    /// \brief Adds an element to the start of the list.
    template <typename... Args>
    auto unshift(Args&&... args) -> void;

    /// \brief Returns the total number of elements in the current list.
    [[nodiscard]]
    auto count() const -> std::size_t;

    /// \brief Removes the first occurrence of the given value from the list.
    /// \returns true if the value was found and removed, false otherwise.
    auto erase(T const& value) -> bool;

private:
    struct Node {
        std::unique_ptr<T>    data = nullptr;
        std::shared_ptr<Node> next = nullptr;
        std::shared_ptr<Node> prev = nullptr;
    };

    // Dummy nodes to simplify the implementation.
    std::shared_ptr<Node> dummy_head_ = std::make_shared<Node>();
    std::shared_ptr<Node> dummy_tail_ = std::make_shared<Node>();
    size_t                size_       = 0UL;

    /// \brief Inserts a new node between two existing nodes.
    template <typename... Args>
    auto insert_between(
        std::shared_ptr<Node> prev, std::shared_ptr<Node> next, Args&&... args
    ) -> void;

    /// \brief Removes a node from the list and returns its data.
    auto remove(std::shared_ptr<Node> node) -> T;
};

template <typename T>
List<T>::List() {
    dummy_head_->next = dummy_tail_;
    dummy_tail_->prev = dummy_head_;
}

template <typename T>
template <typename... Args>
auto List<T>::push(Args&&... args) -> void {
    insert_between(dummy_tail_->prev, dummy_tail_, std::forward<Args>(args)...);
}

template <typename T>
auto List<T>::pop() -> T {
    return remove(dummy_tail_->prev);
}

template <typename T>
auto List<T>::shift() -> T {
    return remove(dummy_head_->next);
}

template <typename T>
template <typename... Args>
auto List<T>::unshift(Args&&... args) -> void {
    insert_between(dummy_head_, dummy_head_->next, std::forward<Args>(args)...);
}

template <typename T>
auto List<T>::count() const -> std::size_t {
    return size_;
}

template <typename T>
auto List<T>::erase(T const& value) -> bool {
    auto node = dummy_head_->next;

    for (auto i = 0UL; i < size_; ++i) {
        if (*(node->data) == value) {
            remove(node);
            return true;
        }

        node = node->next;
    }
    return false;
}

template <typename T>
template <typename... Args>
auto List<T>::insert_between(
    std::shared_ptr<Node> prev, std::shared_ptr<Node> next, Args&&... args
) -> void {

    auto new_node  = std::make_shared<Node>();
    new_node->data = std::make_unique<T>(std::forward<Args>(args)...);
    new_node->prev = prev;
    new_node->next = next;

    prev->next = new_node;
    next->prev = new_node;

    ++size_;
}

template <typename T>
auto List<T>::remove(std::shared_ptr<Node> const node) -> T {
    if (0UL == size_) {
        throw std::domain_error{"Cannot remove from an empty list"};
    }

    node->prev->next = node->next;
    node->next->prev = node->prev;

    --size_;
    return *(node->data);
}

} // namespace linked_list
