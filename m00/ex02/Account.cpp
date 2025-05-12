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

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();

    std::cout << "accounts:" << _nbAccounts  << ";total:" 
              << _totalAmount << ";deposits:" << _totalNbDeposits 
              << ";withdrawal:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)

{
    _displayTimestamp();
    this->_amount += deposit;
    this->_nbDeposits += 1;
    _totalAmount += deposit;
    _totalNbDeposits += 1;
    std::cout << "index:" << this->_accountIndex << ";p_amount:"
              << this->_amount - deposit << ";deposits:" << deposit
              << ";amount:" << this->_amount 
              << ";nb_deposits:" << this->_nbDeposits << std::endl; 
}

// static private

void Account::_displayTimestamp(void)
{
    std::time_t now = std::time(nullptr);
    std::tm *local_time = std::localtime(&now);

    std::cout << '[' <<  (local_time->tm_year + 1900);
    if (local_time->tm_mon + 1 < 10)  
        std::cout << '0' << (local_time->tm_mon + 1);
    else
        std::cout << (local_time->tm_mon + 1);
    if (local_time->tm_mday < 10)
        std::cout << '0' << local_time->tm_mday << '_';
    else
        std::cout << local_time->tm_mday << '_';
    if (local_time->tm_hour < 10)
        std::cout << '0' << local_time->tm_hour;
    else
        std::cout << local_time->tm_hour;
    if (local_time->tm_min < 10)
        std::cout << '0' << local_time->tm_min;
    else
        std::cout << local_time->tm_min;
    if (local_time->tm_sec < 10)
        std::cout << '0' << local_time->tm_sec << "] ";
    else
        std::cout << local_time->tm_sec << "] ";
}

// normal functions

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    if (this->_amount < withdrawal)
    {
        std::cout << "index:" << this->_accountIndex <<";p_amount:" << this->_amount
                  << ";withdrawals:refused" << std::endl; 
        return false;
    }
    this->_amount -= withdrawal;
    this->_nbWithdrawals += 1;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals += 1;
    std::cout << "index:" << this->_accountIndex << ";p_amount:"
              << this->_amount + withdrawal << ";withdrawals:" << withdrawal
              << ";amount:" << this->_amount 
              << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl; 
    return true;
}

int Account::checkAmount(void) const {
    return this->_amount;
}

void Account::displayStatus(void) const
{
    _displayTimestamp();

    std::cout << "index:" << this->_accountIndex << ";amount:"
              << this->_amount << ";deposits:" << this->_nbDeposits
              << ";withdrawals:" << this->_nbWithdrawals << std::endl; 
}
