#include <ctime>
#include <iomanip>
#include <iostream>

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0),
      _nbWithdrawals(0) {
  this->_totalAmount += initial_deposit;

  _displayTimestamp();

  std::cout << " "
            << "index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";created";

  std::cout << std::endl;
}

Account::~Account() {
  _displayTimestamp();

  std::cout << " "
            << "index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";closed";
  std::cout << std::endl;
}

void Account::_displayTimestamp(void) {
  std::time_t time = std::time(0);
  std::tm *now = std::localtime(&time);

  std::cout << std::setfill('0');

  std::cout << "[" << now->tm_year + 1900 << std::setw(2) << now->tm_mon + 1
            << std::setw(2) << now->tm_mday << "_" << std::setw(2)
            << now->tm_hour << std::setw(2) << now->tm_min << std::setw(2)
            << now->tm_sec << "]";

  std::cout << std::setfill(' ');
}

void Account::displayAccountsInfos() {
  _displayTimestamp();

  std::cout << " "
            << "accounts:" << _nbAccounts << ";total:" << _totalAmount
            << ";deposits:" << _totalNbDeposits
            << ";withdrawals:" << _totalNbWithdrawals;

  std::cout << std::endl;
}

void Account::displayStatus() const {
  _displayTimestamp();

  std::cout << " "
            << "index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";deposits:" << this->_nbDeposits
            << ";withdrawals:" << this->_nbWithdrawals;

  std::cout << std::endl;
}

int Account::getNbAccounts() { return _nbAccounts; }

int Account::getTotalAmount() { return _totalAmount; }

int Account::getNbDeposits() { return _totalNbDeposits; }

int Account::getNbWithdrawals() { return _totalNbWithdrawals; }

void Account::makeDeposit(int deposit) {
  this->_amount += deposit;
  _totalAmount += deposit;

  this->_nbDeposits += 1;
  _totalNbDeposits += 1;

  _displayTimestamp();

  std::cout << " "
            << "index:" << this->_accountIndex
            << ";p_amount:" << this->_amount - deposit << ";deposit:" << deposit
            << ";amount:" << this->_amount
            << ";nb_deposits:" << this->_nbDeposits;

  std::cout << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  _displayTimestamp();

  std::cout << " "
            << "index:" << this->_accountIndex << ";p_amount:" << this->_amount
            << ";withdrawal:";

  if (withdrawal > this->_amount) {
    std::cout << "refused" << std::endl;

    return false;
  }

  this->_amount -= withdrawal;
  _totalAmount -= withdrawal;

  this->_nbWithdrawals += 1;
  _totalNbWithdrawals += 1;

  std::cout << withdrawal << ";amount:" << this->_amount
            << ";nb_withdrawals:" << this->_nbWithdrawals;

  std::cout << std::endl;

  return true;
}

int Account::checkAmount() const { return this->_amount; }
