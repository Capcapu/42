/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:44:40 by csolari           #+#    #+#             */
/*   Updated: 2025/10/28 15:02:14 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
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

FragTrap::FragTrap(void) : ClapTrap()
{
	_hitPts = 100;
	_energyPts = 100;
	_attackDamage = 30;
	_isDead = 0;
	std::cout << GREEN_LIGHT << "FragTrap default constructor called" << RESET <<std::endl;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPts = 100;
	_energyPts = 100;
	_attackDamage = 30;
	_isDead = 0;
	std::cout << GREEN_LIGHT << "FragTrap constructor, which initialize values, called" << RESET <<std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << GREEN << "FragTrap destructor called" << RESET <<std::endl;
	return ;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << GREEN_LIGHT << "FragTrap copy constructor called" << RESET <<std::endl;
	*this = copy;
}

FragTrap	&FragTrap::operator=(const FragTrap& other)
{
	std::cout << GREEN_LIGHT << "FragTrap copy assignement operator called" << RESET <<std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	if (_isDead)
		return;
	std::cout << BROWN << "FragTrap " << _name << " : Give me a high five !? \t*CLAAP*\t\tHere you go! " << RESET << std::endl ;
	return;
}

