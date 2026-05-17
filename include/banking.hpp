#ifndef BANKING_HPP
#define BANKING_HPP

#include <string>
#include <vector>
#include <stdexcept>

class Account {
private:
    int id;
    double balance;
public:
    Account(int id, double initial_balance = 0);
    int getId() const;
    double getBalance() const;
    void deposit(double amount);
    void withdraw(double amount);
    void transfer(Account& to, double amount);
};

class Transaction {
private:
    int fromId;
    int toId;
    double amount;
    bool completed;
public:
    Transaction(int fromId, int toId, double amount);
    bool execute(Account& from, Account& to);
    bool isCompleted() const;
};

#endif
