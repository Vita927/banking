#include <gtest/gtest.h>
#include "banking.hpp"

// ===== Тесты для Account =====

TEST(AccountTest, ConstructorAndGetters) {
    Account acc(1, 100);
    EXPECT_EQ(acc.getId(), 1);
    EXPECT_DOUBLE_EQ(acc.getBalance(), 100);
}

TEST(AccountTest, Deposit) {
    Account acc(1, 100);
    acc.deposit(50);
    EXPECT_DOUBLE_EQ(acc.getBalance(), 150);
}

TEST(AccountTest, DepositNegative) {
    Account acc(1, 100);
    EXPECT_THROW(acc.deposit(-10), std::invalid_argument);
}

TEST(AccountTest, Withdraw) {
    Account acc(1, 100);
    acc.withdraw(30);
    EXPECT_DOUBLE_EQ(acc.getBalance(), 70);
}

TEST(AccountTest, WithdrawNegative) {
    Account acc(1, 100);
    EXPECT_THROW(acc.withdraw(-10), std::invalid_argument);
}

TEST(AccountTest, WithdrawInsufficient) {
    Account acc(1, 100);
    EXPECT_THROW(acc.withdraw(150), std::runtime_error);
}

TEST(AccountTest, Transfer) {
    Account from(1, 100);
    Account to(2, 50);
    from.transfer(to, 40);
    EXPECT_DOUBLE_EQ(from.getBalance(), 60);
    EXPECT_DOUBLE_EQ(to.getBalance(), 90);
}

// ===== Тесты для Transaction =====

TEST(TransactionTest, ExecuteSuccess) {
    Account from(1, 100);
    Account to(2, 50);
    Transaction tx(1, 2, 30);
    EXPECT_TRUE(tx.execute(from, to));
    EXPECT_TRUE(tx.isCompleted());
    EXPECT_DOUBLE_EQ(from.getBalance(), 70);
    EXPECT_DOUBLE_EQ(to.getBalance(), 80);
}

TEST(TransactionTest, ExecuteWrongIds) {
    Account from(1, 100);
    Account to(2, 50);
    Transaction tx(3, 4, 30);
    EXPECT_FALSE(tx.execute(from, to));
    EXPECT_FALSE(tx.isCompleted());
}

TEST(TransactionTest, ExecuteInsufficientFunds) {
    Account from(1, 100);
    Account to(2, 50);
    Transaction tx(1, 2, 200);
    EXPECT_FALSE(tx.execute(from, to));
    EXPECT_FALSE(tx.isCompleted());
}
