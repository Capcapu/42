/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:59:02 by csolari           #+#    #+#             */
/*   Updated: 2025/10/28 14:20:07 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

#define GREEN_LIGHT "\033[92m"
#define GREEN       "\033[32m"
#define PURPLE	   "\033[95m"
#define RED         "\033[31m"
#define YELLOW      "\033[93m"
#define BLUE        "\033[94m"
#define RESET       "\033[0m"

ClapTrap::ClapTrap(void) : _name("default"), _hitPts(10),_energyPts(10),_attackDamage(0),_isDead(0)
{
	std::cout << GREEN_LIGHT << "ClapTrap default constructor called" << RESET <<std::endl;
	return;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << GREEN << "ClapTrap destructor called" << RESET <<std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPts(10),_energyPts(10),_attackDamage(0),_isDead(0)
{
	std::cout << GREEN_LIGHT << "ClapTrap constructor, which initialize values, called" << RESET <<std::endl;
	return ;
}


ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << GREEN_LIGHT << "ClapTrap copy constructor called" << RESET <<std::endl;
	*this = copy;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << GREEN_LIGHT << "ClapTrap copy assignement operator called" << RESET <<std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hitPts = other._hitPts;
		_energyPts = other._energyPts;
		_attackDamage = other._attackDamage;
		_isDead = other._isDead;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (_isDead || _energyPts <= 0) 
		return;
	std::cout << PURPLE << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << RESET << std::endl ;
	_energyPts--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_isDead)
		return;
	_hitPts -= amount;
	std::cout << YELLOW << "ClapTrap " << _name << " got damaged" << ", representing " << amount << " points lost!" << RESET << std::endl ;
	if (_hitPts <= 0)
	{
		_isDead = 1;
		std::cout << RED << _name << " is dead..." << RESET << std::endl ;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_isDead || _energyPts <= 0)
		return;
	_hitPts += amount;
	std::cout << BLUE << "ClapTrap " << _name << " got repaired" << ", representing " << amount << " points regained!" << RESET << std::endl ;
	_energyPts--;
}

