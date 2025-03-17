/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:46:32 by gnyssens          #+#    #+#             */
/*   Updated: 2025/03/17 17:23:53 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

class BankAccount {
private:
    std::string owner;
    double balance;

public:
    // Constructor
    BankAccount(const std::string& ownerName, double initialBalance)
        : owner(ownerName), balance(initialBalance)
    {
        // Could do validation, e.g., no negative balance
        if (balance < 0) {
            balance = 0;
        }
    }

    // Destructor
    ~BankAccount() {
        // We don't have anything special to clean up here,
        // but if we had allocated memory or resources, we'd free them now.
    }

    // Member function to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    // Member function to withdraw money
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    // Getter for balance
    double getBalance() const {
        return balance;
    }

    // Getter for owner name
    std::string getOwnerName() const {
        return owner;
    }
};

int main() {
    // Create a BankAccount object on the stack
    BankAccount myAccount("Alice", 1000.0);

    std::cout << "Owner: " << myAccount.getOwnerName()
              << ", Balance: " << myAccount.getBalance() << "\n";

    myAccount.deposit(500.0);
    std::cout << "After deposit, balance: " << myAccount.getBalance() << "\n";

    if (myAccount.withdraw(200.0)) {
        std::cout << "Withdraw successful.\n";
    } else {
        std::cout << "Withdraw failed.\n";
    }

    std::cout << "Final balance: " << myAccount.getBalance() << "\n";

    return 0; // destructor for myAccount called automatically here
}
