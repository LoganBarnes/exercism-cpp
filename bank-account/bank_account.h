#pragma once

#include <atomic>
#include <optional>

namespace Bankaccount {

class Bankaccount {
public:
    Bankaccount();

    auto open() -> void;
    auto close() -> void;
    auto deposit(int deposit_amount) -> void;
    auto withdraw(int withdraw_amount) -> void;

    [[nodiscard]] auto balance() const -> int;

private:
    std::atomic<std::optional<int>> balance_;

}; // class Bankaccount

} // namespace Bankaccount
