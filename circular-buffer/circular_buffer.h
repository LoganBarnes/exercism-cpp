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
        advance_head(read_head_);
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
        buffer_[write_head_] = std::move(data);
        if (size_ == buffer_.size()) {
            advance_head(read_head_);
        } else {
            ++size_;
        }
        advance_head(write_head_);
    }

    auto clear() -> void {
        read_head_  = 0;
        write_head_ = 0;
        size_       = 0;
    }

private:
    std::vector<T> buffer_;
    size_t         read_head_  = 0;
    size_t         write_head_ = 0;
    size_t         size_       = 0;

    auto advance_head(size_t& head) { head = (head + 1) % buffer_.size(); }
};

} // namespace circular_buffer
