/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 01:27:24 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/15 03:25:19 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

static void    printInfo(std::string item, int val, bool semi_c) {
    std::cout << item << ":" << val;
    if (semi_c) {
        std::cout << ";";
    } else {
        std::cout << std::endl;
    }
    return ;
}

Account::Account(int initial_deposit): _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
    _displayTimestamp();
    printInfo("index", _accountIndex, true);
    printInfo("amount", checkAmount(), true);
    std::cout << "created" << std::endl;
    _nbAccounts += 1;
    _totalAmount += _amount;

    return ;
}

Account::~Account(void) {
    _displayTimestamp();
    printInfo("index", _accountIndex, true);
    printInfo("amount", checkAmount(), true);
    std::cout << "closed" << std::endl;
    _nbAccounts -= 1;
    _totalAmount -= _amount;
    _totalNbDeposits -= _nbDeposits;
    _totalNbWithdrawals -= _nbWithdrawals;
    return ;
}

int  Account::getNbAccounts(void) {
    return (_nbAccounts);
}

int  Account::getTotalAmount(void) {
    return (_totalAmount);
}

int  Account::getNbDeposits(void) {
    return (_totalNbDeposits);
}

int  Account::getNbWithdrawals(void) {
    return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    printInfo("accounts", getNbAccounts(), true);
    printInfo("total", getTotalAmount(), true);
    printInfo("deposits", getNbDeposits(), true);
    printInfo("withdrawals", getNbWithdrawals(), false);

    return ;
}

void    Account::makeDeposit(int deposit) {
    _displayTimestamp();
    printInfo("index", _accountIndex, true);
    printInfo("p_amount", checkAmount(), true);
    printInfo("deposit", deposit, true);
    _amount += deposit;
    _nbDeposits += 1;
    _totalAmount += deposit;
    _totalNbDeposits += 1;
    printInfo("amount", checkAmount(), true);
    printInfo("nb_deposits", _nbDeposits, false);

    return;
}

bool    Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    printInfo("index", _accountIndex, true);
    printInfo("p_amount", checkAmount() , true);
    std::cout << "withdrawal:";
    if (_amount - withdrawal < 0) {
        std::cout << "refused" << std::endl;
        return (false);
    } else {
        std::cout << withdrawal << ";";
        _amount -= withdrawal;
        _nbWithdrawals += 1;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals +=1 ;
        printInfo("amount", checkAmount(), true);
        printInfo("nb_withdrawals", _nbWithdrawals, false);
        return (true);
    }
}

int Account::checkAmount(void) const {
    return (_amount);
}

void    Account::displayStatus(void) const {
    _displayTimestamp();
    printInfo("index", _accountIndex, true);
    printInfo("amount", checkAmount() , true);
    printInfo("deposits", _nbDeposits, true);
    printInfo("withdrawals", _nbWithdrawals, false);

    return;
}

void Account::_displayTimestamp(void) {
    std::cout << "[19920104_091532] ";
    return ;
}


Account::Account(void) {
    return ;
}
