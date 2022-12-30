#pragma once

#include <vector>

namespace circular_buffer {

template <typename T>
class circular_buffer {
public:
    explicit circular_buffer(size_t size) : buffer_(size) {}

    auto read() -> T {
        if (size_ == 0) {
            throw std::domain_error("Buffer is empty");
        }
        auto&& result = std::move(buffer_[read_head_]);
        read_head_ = safe_index(read_head_ + 1);
        --size_;
        return result;
    }

    auto write(T data) -> void {
        if (size_ == buffer_.size()) {
            throw std::domain_error("Buffer is full");
        }
        overwrite(std::move(data));
    }

    auto overwrite(T data) -> void {
        buffer_[safe_index(read_head_ + size_)] = std::move(data);
        if (size_ == buffer_.size()) {
            read_head_ = safe_index(read_head_ + 1);
        } else {
            ++size_;
        }
    }

    auto clear() -> void {
        read_head_ = 0;
        size_      = 0;
    }

private:
    std::vector<T> buffer_;
    size_t         read_head_ = 0;
    size_t         size_      = 0;

    auto safe_index(size_t index) const { return index % buffer_.size(); }
};

} // namespace circular_buffer
