#pragma once

#include <memory>
#include <stdexcept>

namespace linked_list {

template <typename T>
class List {
public:
    explicit List();

    /// \brief Adds an element to the end of the list.
    auto push(T element) -> void;

    /// \brief Removes and returns the last element of the list.
    /// \throws std::domain_error if the list is empty.
    auto pop() -> T;

    /// \brief Removes and returns the first element of the list.
    /// \throws std::domain_error if the list is empty.
    auto shift() -> T;

    /// \brief Adds an element to the start of the list.
    auto unshift(T element) -> void;

    /// \brief Returns the total number of elements in the current list.
    [[nodiscard]]
    auto count() const -> std::size_t;

    /// \brief Removes the first occurrence of the given value from the list.
    /// \returns true if the value was found and removed, false otherwise.
    auto erase(T const& value) -> bool;

private:
    struct Node {
        explicit Node(T node_data) : data{node_data} {};
        T                     data;
        std::shared_ptr<Node> next = nullptr;
        std::shared_ptr<Node> prev = nullptr;
    };

    // Dummy nodes to simplify the implementation.
    // T is assumed to be a simple type that can be default-constructed.
    // Otherwise, the implementation should be smarter about moves and copies.
    std::shared_ptr<Node> dummy_head_ = std::make_shared<Node>(T{});
    std::shared_ptr<Node> dummy_tail_ = std::make_shared<Node>(T{});
    size_t                size_       = 0UL;

    /// \brief Inserts a new node between two existing nodes.
    auto insert_between(
        T node_data, std::shared_ptr<Node> prev, std::shared_ptr<Node> next
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
auto List<T>::push(T element) -> void {
    insert_between(element, dummy_tail_->prev, dummy_tail_);
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
auto List<T>::unshift(T element) -> void {
    insert_between(element, dummy_head_, dummy_head_->next);
}

template <typename T>
auto List<T>::count() const -> std::size_t {
    return size_;
}

template <typename T>
auto List<T>::erase(T const& value) -> bool {
    auto node = dummy_head_->next;

    for (auto i = 0UL; i < size_; ++i) {
        if (node->data == value) {
            remove(node);
            return true;
        }

        node = node->next;
    }
    return false;
}

template <typename T>
auto List<T>::insert_between(
    T node_data, std::shared_ptr<Node> prev, std::shared_ptr<Node> next
) -> void {

    auto new_node  = std::make_shared<Node>(node_data);
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
    return node->data;
}

} // namespace linked_list
