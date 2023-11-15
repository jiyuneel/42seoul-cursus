#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) {
    this->_accountIndex = _nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout
        << "index:" << this->_accountIndex << ";"
        << "amount:" << this->_amount << ";"
        << "created" << std::endl;
}
Account::~Account( void ) {
    _nbAccounts--;
    _totalAmount -= this->_amount;
    _totalNbDeposits -= this->_nbDeposits;
    _totalNbWithdrawals -= this->_nbWithdrawals;

    _displayTimestamp();
    std::cout
        << "index:" << this->_accountIndex << ";"
        << "amount:" << this->_amount << ";"
        << "closed" << std::endl;
}

int Account::getNbAccounts( void ) {
    return _nbAccounts;
}
int Account::getTotalAmount( void ) {
    return _totalAmount;
}
int Account::getNbDeposits( void ) {
    return _totalNbDeposits;
}
int Account::getNbWithdrawals( void ) {
    return _totalNbWithdrawals;
}
int Account::checkAmount( void ) const {
    return this->_amount;
}

void Account::_displayTimestamp( void ) {
    std::time_t currentTime = std::time(NULL);
    std::tm* timeInfo = std::localtime(&currentTime);
    char timeString[18];
    std::strftime(timeString, 18, "[%Y%m%d_%H%M%S]", timeInfo);
    std::cout << timeString << ' ';
}

void Account::displayAccountsInfos( void ) {
    _displayTimestamp();
    std::cout
        << "accounts:" << _nbAccounts << ";"
        << "total:" << _totalAmount << ";"
        << "deposits:" << _totalNbDeposits << ";"
        << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit( int deposit ) {
    int p_amount = this->_amount;
    this->_amount += deposit;
    this->_nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;

    _displayTimestamp();
    std::cout
        << "index:" << this->_accountIndex << ";"
        << "p_amount:" << p_amount << ";"
        << "deposit:" << deposit << ";"
        << "amount:" << this->_amount << ";"
        << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int withdrawal ) {
    if (this->_amount < withdrawal) {
        _displayTimestamp();
        std::cout
            << "index:" << this->_accountIndex << ";"
            << "p_amount:" << this->_amount << ";"
            << "withdrawal:refused" << std::endl;
        return false;
    }

    int p_amount = this->_amount;
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    _displayTimestamp();
    std::cout
        << "index:" << this->_accountIndex << ";"
        << "p_amount:" << p_amount << ";"
        << "withdrawal:" << withdrawal << ";"
        << "amount:" << this->_amount << ";"
        << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return true;
}

void Account::displayStatus( void ) const {
    _displayTimestamp();
    std::cout
        << "index:" << this->_accountIndex << ";"
        << "amount:" << this->_amount << ";"
        << "deposits:" << this->_nbDeposits << ";"
        << "withdrawals:" << this->_nbWithdrawals << std::endl;
}