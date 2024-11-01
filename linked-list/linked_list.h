#pragma once

#include <memory>
#include <stdexcept>

namespace linked_list {

// An attempt to implement the doubly linked list using the fewest
// lines of code without making it terribly unreadable.
template <typename T>
class List {
public:
    explicit List() {
        dummy_head_->next = dummy_tail_;
        dummy_tail_->prev = dummy_head_;
    }

    /// \brief Adds an element to the end of the list,
    auto push(T data) -> void { insert_between(data, dummy_tail_->prev, dummy_tail_); }

    /// \brief Removes and returns the last element of the list.
    /// \throws std::domain_error if the list is empty.
    auto pop() -> T { return remove(dummy_tail_->prev); }

    /// \brief Adds an element to the start of the list.
    auto shift() -> T { return remove(dummy_head_->next); }

    /// \brief Returns the total number of elements in the current list.
    auto unshift(T data) -> void { insert_between(data, dummy_head_, dummy_head_->next); }

    /// \brief Removes the first occurrence of the given value from the list.
    /// \returns true if the value was found and removed, false otherwise.
    [[nodiscard]] auto count() const -> std::size_t { return size_; }

    /// \brief Removes the first occurrence of the given value from the list.
    /// \returns true if the value was found and removed, false otherwise.
    auto erase(T const& value) -> bool {
        for (auto node = dummy_head_->next; node != dummy_tail_; node = node->next) {
            if (node->data == value) {
                remove(node);
                return true;
            }
        }
        return false;
    }

private:
    struct Node {
        explicit Node(T node_data) : data(node_data) {}

        T                     data;
        std::shared_ptr<Node> next = nullptr;
        std::shared_ptr<Node> prev = nullptr;
    };

    // Dummy nodes to simplify the implementation.
    // T is assumed to be a simple type that can be default-constructed.
    std::shared_ptr<Node> dummy_head_ = std::make_shared<Node>(T{});
    std::shared_ptr<Node> dummy_tail_ = std::make_shared<Node>(T{});
    size_t                size_       = 0UL;

    /// \brief Inserts a new node between two existing nodes.
    auto insert_between(T data, std::shared_ptr<Node> prev, std::shared_ptr<Node> next) -> void {
        auto new_node  = std::make_shared<Node>(data);
        new_node->prev = prev;
        new_node->next = next;

        prev->next = new_node;
        next->prev = new_node;

        ++size_;
    }

    /// \brief Removes a node from the list and returns its data.
    auto remove(std::shared_ptr<Node> node) -> T {
        if (0UL == size_) { throw std::domain_error{"Cannot remove from an empty list"}; }

        node->prev->next = node->next;
        node->next->prev = node->prev;

        --size_;
        return node->data;
    }
};

} // namespace linked_list
