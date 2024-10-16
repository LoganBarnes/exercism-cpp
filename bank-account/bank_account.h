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

    auto deposit(Currency deposit_amount) -> void;
    auto withdraw(Currency withdraw_amount) -> void;

    [[nodiscard]] auto balance() const -> Currency;

private:
    // nullopt implies a closed account.
    std::atomic<std::optional<Currency>> balance_;

}; // class Bankaccount

} // namespace Bankaccount
