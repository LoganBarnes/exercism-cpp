#pragma once

#include <memory>
#include <stdexcept>

namespace linked_list {

// An attempt to implement the doubly linked list using the fewest
// lines of code without making it terribly unreadable
// (and without using an existing std implementation).
template <typename T>
class List {
public:
    explicit List() { dummy_->prev_node = dummy_->next_node = dummy_; }

    /// \brief Adds an element to the end of the list,
    auto push(T data) -> void { insert_between(data, dummy_->prev_node, dummy_); }

    /// \brief Removes and returns the last element of the list.
    /// \throws std::domain_error if the list is empty.
    auto pop() -> T { return remove(dummy_->prev_node); }

    /// \brief Adds an element to the start of the list.
    auto shift() -> T { return remove(dummy_->next_node); }

    /// \brief Returns the total number of elements in the current list.
    auto unshift(T data) -> void { insert_between(data, dummy_, dummy_->next_node); }

    /// \brief Removes the first occurrence of the given value from the list.
    /// \returns true if the value was found and removed, false otherwise.
    [[nodiscard]] auto count() const -> std::size_t { return size_; }

    /// \brief Removes the first occurrence of the given value from the list.
    /// \returns true if the value was found and removed, false otherwise.
    auto erase(T const& value) -> bool {
        for (auto node = dummy_->next_node; node != dummy_; node = node->next_node) {
            if (node->data == value) {
                remove(node);
                return true;
            }
        }
        return false;
    }

private:
    /// \brief The core node structure for the doubly linked list with
    ///        references to the previous and next nodes.
    struct Node {
        explicit Node(T node_data, std::shared_ptr<Node> prev, std::shared_ptr<Node> next)
            : data(node_data), prev_node(std::move(prev)), next_node(std::move(next)) {}

        T                     data;
        std::shared_ptr<Node> prev_node;
        std::shared_ptr<Node> next_node;
    };

    // Dummy node to simplify the implementation.
    // T is assumed to be a simple type that can be default-constructed.
    std::shared_ptr<Node> dummy_ = std::make_shared<Node>(T{}, nullptr, nullptr);
    size_t                size_  = 0UL;

    /// \brief Inserts a new node between two existing nodes.
    auto insert_between(T data, std::shared_ptr<Node> prev, std::shared_ptr<Node> next) -> void {
        auto new_node   = std::make_shared<Node>(data, prev, next);
        prev->next_node = new_node;
        next->prev_node = new_node;
        ++size_;
    }

    /// \brief Removes a node from the list and returns its data.
    /// \throws std::domain_error if the list is empty.
    auto remove(std::shared_ptr<Node> node) -> T {
        size_ = (size_ > 0UL) ? size_ - 1UL : throw std::domain_error{"List empty"};

        node->prev_node->next_node = node->next_node;
        node->next_node->prev_node = node->prev_node;

        return node->data;
    }
};

} // namespace linked_list
