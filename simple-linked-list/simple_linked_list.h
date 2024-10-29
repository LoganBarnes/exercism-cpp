#pragma once

#include <algorithm>
#include <memory>

namespace simple_linked_list {

template <typename T = int>
class List {
public:
    [[nodiscard]]
    auto size() const -> std::size_t;
    auto push(T entry) -> void;
    auto pop() -> T;
    auto reverse() -> void;

private:
    struct Element {
        explicit Element(T element_data);
        T                        data;
        std::unique_ptr<Element> next = nullptr;
    };

    std::unique_ptr<Element> head_ = nullptr;
    std::size_t              size_ = 0UL;
};

template <typename T>
List<T>::Element::Element(T element_data) : data{std::move(element_data)} {}

template <typename T>
auto List<T>::size() const -> std::size_t {
    return size_;
}

template <typename T>
auto List<T>::push(T entry) -> void {
    auto node  = std::make_unique<Element>(std::move(entry));
    node->next = std::move(head_);
    head_      = std::move(node);
    ++size_;
}

template <typename T>
auto List<T>::pop() -> T {
    auto const entry = std::move(head_->data);

    auto const head = std::move(head_);
    head_           = std::move(head->next);
    --size_;

    return entry;
}

template <typename T>
auto List<T>::reverse() -> void {
    auto           curr = std::move(head_);
    decltype(curr) prev = nullptr;

    while (curr) {
        std::swap(curr->next, prev);
        std::swap(prev, curr);
    }

    head_ = std::move(prev);
}

} // namespace simple_linked_list
