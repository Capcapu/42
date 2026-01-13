/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:58:45 by csolari           #+#    #+#             */
/*   Updated: 2025/10/29 12:33:24 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <stdlib.h>

#define GREEN_LIGHT "\033[92m"
#define GREEN       "\033[32m"
#define PURPLE	   "\033[95m"
#define RED         "\033[31m"
#define YELLOW      "\033[93m"
#define BLUE        "\033[94m"
#define BROWN       "\033[38;2;139;69;19m"
#define RESET       "\033[0m"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	_hitPts = 100;
	_energyPts = 50;
	_attackDamage = 20;
	_isDead = 0;
	_gateKeeper = 0;
	std::cout << GREEN_LIGHT << "ScavTrap default constructor called" << RESET <<std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPts = 100;
	_energyPts = 50;
	_attackDamage = 20;
	_isDead = 0;
	_gateKeeper = 0;
	std::cout << GREEN_LIGHT << "ScavTrap constructor, which initialize values, called" << RESET <<std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << GREEN << "ScavTrap destructor called" << RESET <<std::endl;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << GREEN_LIGHT << "ScavTrap copy constructor called" << RESET <<std::endl;
	*this = copy;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << GREEN_LIGHT << "ScavTrap copy assignement operator called" << RESET <<std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}

void	ScavTrap::guardGate(void)
{
	if (_isDead || _energyPts <= 0)
		return;
	if (_gateKeeper == 1)
	{
		_gateKeeper = 0;
		std::cout << BROWN << "ScavTrap " << _name << " is not in Gate keeper mode anymore!" << RESET << std::endl ;
		return;
	}
	_energyPts--;
	_gateKeeper = 1;
	std::cout << BROWN << "ScavTrap " << _name << " is now in Gate keeper mode!" << RESET << std::endl ;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_isDead || _energyPts <= 0) 
		return;
	std::cout << PURPLE << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << RESET << std::endl ;
	_energyPts--;
}