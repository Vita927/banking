#include "banking.hpp"

// Account
Account::Account(int id, double initial_balance) : id(id), balance(initial_balance) {}

int Account::getId() const { return id; }
double Account::getBalance() const { return balance; }

void Account::deposit(double amount) {
    if (amount < 0) throw std::invalid_argument("Amount cannot be negative");
    balance += amount;
}

void Account::withdraw(double amount) {
    if (amount < 0) throw std::invalid_argument("Amount cannot be negative");
    if (amount > balance) throw std::runtime_error("Insufficient funds");
    balance -= amount;
}

void Account::transfer(Account& to, double amount) {
    withdraw(amount);
    to.deposit(amount);
}

// Transaction
Transaction::Transaction(int fromId, int toId, double amount) 
    : fromId(fromId), toId(toId), amount(amount), completed(false) {}

bool Transaction::execute(Account& from, Account& to) {
    if (from.getId() != fromId || to.getId() != toId) return false;
    try {
        from.transfer(to, amount);
        completed = true;
        return true;
    } catch (...) {
        return false;
    }
}

bool Transaction::isCompleted() const { return completed; }
