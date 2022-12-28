#pragma once

#include <memory>

namespace binary_search_tree {

template <typename T>
class binary_tree {
public:
    using owned_node = std::unique_ptr<binary_tree<T>>;
    using raw_node   = binary_tree<T> const*;

    explicit binary_tree(T data, raw_node parent = nullptr)
        : data_(data)
        , left_(nullptr)
        , right_(nullptr)
        , parent_(parent) {}

    auto data() const -> T const& { return data_; }

    auto left() const -> owned_node const& { return left_; }

    auto right() const -> owned_node const& { return right_; }

    auto insert(T data) -> void {
        if (data_ < data) {
            insert_or_create(right_, data);
        } else {
            insert_or_create(left_, data);
        }
    }

    struct iterator;

    auto begin() const -> iterator { return left_ ? left_->begin() : this; }

    auto end() const -> iterator { return nullptr; }

private:
    T          data_;
    owned_node left_;
    owned_node right_;
    raw_node   parent_;

    auto insert_or_create(owned_node& node, T data) -> void {
        if (node) {
            node->insert(data);
        } else {
            node = std::make_unique<binary_tree<T>>(data, this);
        }
    }

    auto get_next_parent() const -> raw_node {
        if (!parent_ || parent_->left().get() == this) {
            return parent_;
        }
        return parent_->get_next_parent();
    }
};

// The most minimal, read-only iterator.
template <typename T>
struct binary_tree<T>::iterator {
    iterator(raw_node node) : node_(node) {}

    auto operator*() const -> T const& { return node_->data(); }

    auto operator++() -> void {
        if (node_->right()) {
            *this = node_->right()->begin();
        } else {
            node_ = node_->get_next_parent();
        }
    }

    auto operator!=(iterator const& o) const { return node_ != o.node_; };

private:
    raw_node node_;
};

} // namespace binary_search_tree
