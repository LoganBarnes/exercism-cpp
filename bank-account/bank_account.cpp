#include "bank_account.h"

#include <stdexcept>

namespace Bankaccount {
namespace {

enum ThrowIf { Closed, Open };

auto throw_if(std::optional<int> const& balance, ThrowIf should_throw) {
    if (should_throw == ThrowIf::Closed && !balance) {
        throw std::runtime_error("Bank account is closed");
    }
    if (should_throw == ThrowIf::Open && balance) {
        throw std::runtime_error("Bank account is open");
    }
}

// Atomically attempt to update the account.
template <typename UpdateCallback>
auto update_account(std::atomic<std::optional<int>>& balance,
                    ThrowIf                          should_throw,
                    UpdateCallback const&            update_callback) {
    // Get the existing state
    auto potential_balance = balance.load();

    // Attempt to update the balance if it hasn't changed since it was last accessed.
    // If it has changed, update the value of 'potential_balance' and try again.
    do {
        // Check for errors
        throw_if(potential_balance, should_throw);
    } while (!balance.compare_exchange_weak(potential_balance, update_callback(potential_balance)));
}

} // namespace

Bankaccount::Bankaccount() : balance_(std::nullopt) {}

auto Bankaccount::open() -> void {
    update_account(balance_, ThrowIf::Open, [](auto) { return std::make_optional(0); });
}

auto Bankaccount::close() -> void {
    update_account(balance_, ThrowIf::Closed, [](auto) { return std::nullopt; });
}

auto Bankaccount::deposit(int deposit_amount) -> void {
    if (deposit_amount < 1) {
        throw std::runtime_error("Deposit amount must be positive");
    }
    update_account(balance_, ThrowIf::Closed, [&](auto balance) { return balance.value() + deposit_amount; });
}

auto Bankaccount::withdraw(int withdraw_amount) -> void {
    if (withdraw_amount < 1) {
        throw std::runtime_error("Withdraw amount must be positive");
    }
    update_account(balance_, ThrowIf::Closed, [&](auto balance) {
        if (balance.value() < withdraw_amount) {
            throw std::runtime_error("Cannot withdraw more than the current balance");
        }
        return balance.value() - withdraw_amount;
    });
}

auto Bankaccount::balance() const -> int {
    auto balance = balance_.load();
    throw_if(balance, ThrowIf::Closed);
    return balance.value();
}

} // namespace Bankaccount
