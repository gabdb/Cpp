#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <string>

// 4 static variables of Class Account

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Getters

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

// Constructors

Account::Account(int initial_deposit) : 
_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	_totalAmount += initial_deposit;
    std::cout << "index:" << this->_accountIndex << ";amount:"
        << this->_amount << ";created" << std::endl;
	_nbAccounts++;
}

Account::~Account()
{
	_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:"
              << this->_amount << ";closed" << std::endl;
}

