#pragma once

#include <atomic>
#include <optional>

namespace Bankaccount {

using Currency = int;

class Bankaccount {
public:
    Bankaccount();

    auto open() -> void;
    auto close() -> void;

    auto deposit(int deposit_amount) -> void;
    auto withdraw(int withdraw_amount) -> void;

    [[nodiscard]] auto balance() const -> Currency;

private:
    // nullopt implies a closed account.
    std::atomic<std::optional<Currency>> balance_;

}; // class Bankaccount

} // namespace Bankaccount
