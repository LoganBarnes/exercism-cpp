#pragma once

#include <cstddef>

namespace simple_linked_list {

class List {
public:
    List() = default;
    ~List();

    // Moving and copying is not needed to solve the exercise.
    // If you want to change these, make sure to correctly
    // free / move / copy the allocated resources.
    List(List const&)            = delete;
    List& operator=(List const&) = delete;
    List(List&&)                 = delete;
    List& operator=(List&&)      = delete;

    std::size_t size() const;
    void        push(int entry);
    int         pop();
    void        reverse();

private:
    struct Element {
        explicit Element(int data_in) : data{data_in} {};
        int      data = 0;
        Element* next = nullptr;
    };

    Element*    head_         = nullptr;
    std::size_t current_size_ = 0;
};

} // namespace simple_linked_list
