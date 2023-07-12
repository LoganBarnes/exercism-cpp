#include "simple_linked_list.h"

#include <stdexcept>

namespace simple_linked_list {

std::size_t List::size() const {
    return current_size_;
}

void List::push(int entry) {
    auto node  = new Element{entry};
    node->next = head_;
    head_      = node;
    ++current_size_;
}

int List::pop() {
    int entry = head_->data;

    auto head = head_;
    head_     = head_->next;
    delete head;
    --current_size_;

    return entry;
}

void List::reverse() {
    Element* prev = nullptr;
    Element* curr = head_;
    Element* next = nullptr;

    while (curr) {
        next       = curr->next;
        curr->next = prev;
        prev       = curr;
        curr       = next;
    }

    head_ = prev;
}

List::~List() {
    while (head_) {
        pop();
    }
}

} // namespace simple_linked_list
