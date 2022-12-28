#include "bank_account.h"

#include <stdexcept>

namespace Bankaccount {
namespace {

enum ThrowIf { Closed, Open };

auto throw_if(
    std::optional<Currency> const& balance,
    ThrowIf                        should_throw
) {
    if (should_throw == ThrowIf::Closed && !balance) {
        throw std::runtime_error("Bank account is closed");
    }
    if (should_throw == ThrowIf::Open && balance) {
        throw std::runtime_error("Bank account is open");
    }
}

template <typename UpdateCallback>
auto safely_update_account(
    std::atomic<std::optional<Currency>>& balance,
    ThrowIf                               should_throw,
    UpdateCallback const&                 update_callback
) {
    // Get the existing state.
    auto last_known_value = balance.load();

    decltype(last_known_value) new_value;
    do {
        // Check for errors.
        throw_if(last_known_value, should_throw);

        // Get the value that should replace 'last_known_value'.
        new_value = update_callback(last_known_value);

        // Attempt to update the balance if it hasn't changed since
        // it was last accessed. If it has changed, 'last_known_value'
        // will be updated and the above changes can be applied again.
    } while (
        !balance.compare_exchange_weak(last_known_value, new_value)
    );
}

} // namespace

Bankaccount::Bankaccount() : balance_(std::nullopt) {}

auto Bankaccount::open() -> void {
    safely_update_account(
        balance_,
        ThrowIf::Open,
        [](auto) { return std::make_optional(0); }
    );
}

auto Bankaccount::close() -> void {
    safely_update_account(
        balance_,
        ThrowIf::Closed,
        [](auto) { return std::nullopt; }
    );
}

auto Bankaccount::deposit(Currency deposit_amount) -> void {
    if (deposit_amount < 1) {
        throw std::runtime_error("Deposit amount must be positive");
    }
    safely_update_account(
        balance_,
        ThrowIf::Closed,
        [&](auto balance) { return balance.value() + deposit_amount; }
    );
}

auto Bankaccount::withdraw(Currency withdraw_amount) -> void {
    if (withdraw_amount < 1) {
        throw std::runtime_error("Withdraw amount must be positive");
    }
    safely_update_account(
        balance_,
        ThrowIf::Closed,
        [&](auto balance) {
            if (balance.value() < withdraw_amount) {
                throw std::runtime_error("Cannot withdraw more than balance");
            }
            return balance.value() - withdraw_amount;
        }
    );
}

auto Bankaccount::balance() const -> Currency {
    auto balance = balance_.load();
    throw_if(balance, ThrowIf::Closed);
    return balance.value();
}

} // namespace Bankaccount
