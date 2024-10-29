#pragma once

#include <cstddef>
#include <memory>
#include <stdexcept>
#include <string>

namespace linked_list {

template <typename T>
class List {
public:
    /// \brief Adds an element to the end of the list,
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
        std::unique_ptr<Node> next = nullptr;
        Node*                 prev = nullptr;
    };

    std::unique_ptr<Node> head_ = nullptr;
    Node*                 tail_ = nullptr;
    size_t                size_ = 0UL;
};

template <typename T>
auto List<T>::push(T element) -> void {
    if (nullptr == head_) {
        head_ = std::make_unique<Node>(std::move(element));
        tail_ = head_.get();

    } else {
        tail_->next       = std::make_unique<Node>(std::move(element));
        tail_->next->prev = tail_;
        tail_             = tail_->next.get();
    }

    ++size_;
}

template <typename T>
auto List<T>::pop() -> T {
    if (0UL == size_) {
        throw std::domain_error{"Cannot pop from an empty list"};
    }

    auto data = std::move(tail_->data);

    tail_ = tail_->prev;

    if (nullptr == tail_) {
        head_ = nullptr;
    } else {
        tail_->next = nullptr;
    }

    --size_;
    return data;
}

template <typename T>
auto List<T>::shift() -> T {
    if (0UL == size_) {
        throw std::domain_error{"Cannot shift from an empty list"};
    }

    auto data = std::move(head_->data);

    head_ = std::move(head_->next);

    if (nullptr == head_) {
        tail_ = nullptr;
    } else {
        head_->prev = nullptr;
    }

    --size_;
    return data;
}

template <typename T>
auto List<T>::unshift(T element) -> void {
    if (nullptr == head_) {
        head_ = std::make_unique<Node>(std::move(element));
        tail_ = head_.get();

    } else {
        auto new_head  = std::make_unique<Node>(std::move(element));
        head_->prev    = new_head.get();
        new_head->next = std::move(head_);
        head_          = std::move(new_head);
    }

    ++size_;
}

template <typename T>
auto List<T>::count() const -> std::size_t {
    return size_;
}

template <typename T>
auto List<T>::erase(T const& value) -> bool {

    auto* node = head_.get();

    for (auto i = 0UL; i < size_; ++i) {
        if (node->data == value) {
            if (node->next) {
                node->next->prev = node->prev;
            } else {
                tail_ = node->prev;
            }

            if (node->prev) {
                node->prev->next = std::move(node->next);
            } else {
                head_ = std::move(node->next);
            }

            --size_;
            return true;
        }

        node = node->next.get();
    }

    return false;
}

} // namespace linked_list
