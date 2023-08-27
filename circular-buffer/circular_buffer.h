#pragma once

#include <stdexcept>
#include <vector>

namespace circular_buffer {

template <typename T>
class circular_buffer {
public:
    explicit circular_buffer(size_t size);

    auto read() -> T;
    auto write(T data) -> void;

    auto overwrite(T data) -> void;
    auto clear() -> void;

    auto full() const -> bool;
    auto empty() const -> bool;

private:
    std::vector<T> buffer_;
    size_t         read_head_ = 0;
    size_t         size_      = 0;

    auto wrapped_index(size_t index) const -> size_t;
};

template <typename T>
circular_buffer<T>::circular_buffer(size_t size) : buffer_(size) {}

template <typename T>
auto circular_buffer<T>::read() -> T {
    if (empty()) {
        throw std::domain_error("Cannot read: buffer is empty.");
    }
    auto&& result = std::move(buffer_[read_head_]);
    read_head_    = wrapped_index(read_head_ + 1);
    --size_;
    return result;
}

template <typename T>
auto circular_buffer<T>::write(T data) -> void {
    if (full()) {
        throw std::domain_error("Cannot write: buffer is full.");
    }
    overwrite(std::move(data));
}

template <typename T>
auto circular_buffer<T>::overwrite(T data) -> void {
    buffer_[wrapped_index(read_head_ + size_)] = std::move(data);

    // 1 if not full, 0 otherwise
    auto const offset = std::min<size_t>(1ul, buffer_.size() - size_);

    // Increment read_head if buffer is full.
    read_head_ = wrapped_index(read_head_ + 1ul - offset);
    // Otherwise increment size.
    size_ += offset;
}

template <typename T>
auto circular_buffer<T>::clear() -> void {
    read_head_ = 0;
    size_      = 0;
}

template <typename T>
auto circular_buffer<T>::full() const -> bool {
    return size_ == buffer_.size();
}

template <typename T>
auto circular_buffer<T>::empty() const -> bool {
    return size_ == 0;
}

template <typename T>
auto circular_buffer<T>::wrapped_index(size_t index) const -> size_t {
    return index % buffer_.size();
}

} // namespace circular_buffer
