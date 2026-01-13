/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:16:36 by csolari           #+#    #+#             */
/*   Updated: 2025/10/22 14:13:56 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <stdlib.h>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( void )
{
	return ;
}

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	
	_nbAccounts++;
	_totalAmount += initial_deposit;
	
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" <<std::endl;
	return ;
}

Account::~Account( void )
{
	_nbAccounts--;
	_totalAmount -= _amount;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" <<std::endl;
	return ;
}

int	Account::getNbAccounts( void )
{
	return(_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return(_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return(_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() <<std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount ;
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << ";deposit:" <<  deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits <<std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (_amount  - withdrawal > 0)
	{
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" <<  withdrawal ;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		std::cout << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return(1);
	}
	else
		std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
	return(0);
}

int		Account::checkAmount( void ) const
{
	return(1);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals <<std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t now = time(0);
	struct tm *timeinfo = localtime(&now);
	
	std::cout << "[";
	std::cout << (timeinfo->tm_year + 1900);  
	if (timeinfo->tm_mon + 1 < 10) std::cout << "0";
	std::cout << (timeinfo->tm_mon + 1);      
	if (timeinfo->tm_mday < 10) std::cout << "0";
	std::cout << timeinfo->tm_mday;           
	std::cout << "_";
	if (timeinfo->tm_hour < 10) std::cout << "0";
	std::cout << timeinfo->tm_hour;       
	if (timeinfo->tm_min < 10) std::cout << "0";
	std::cout << timeinfo->tm_min;
	if (timeinfo->tm_sec < 10) std::cout << "0";
	std::cout << timeinfo->tm_sec;   
	std::cout << "]";
}

