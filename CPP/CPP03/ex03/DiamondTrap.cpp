/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:04:19 by csolari           #+#    #+#             */
/*   Updated: 2025/10/28 16:24:52 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
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


DiamondTrap::DiamondTrap(void) : ClapTrap("Default_clap_name")
{
	_name = "Default";
	_hitPts = 100;
	_energyPts = 50; 
	_attackDamage = 30;
	_isDead = 0;
	std::cout << GREEN_LIGHT << "DiamondTrap default constructor called" << RESET <<std::endl;
	return ;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	_name = name;
	_hitPts = 100;
	_energyPts = 50;
	_attackDamage = 30;
	_isDead = 0;
	std::cout << GREEN_LIGHT << "DiamondTrap constructor, which initialize values, called" << RESET <<std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << GREEN << "DiamondTrap destructor called" << RESET <<std::endl;
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy)
{
	std::cout << GREEN_LIGHT << "DiamondTrap copy constructor called" << RESET <<std::endl;
	*this = copy;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << GREEN_LIGHT << "DiamondTrap copy assignement operator called" << RESET <<std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		_name = other._name;
	}
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name is " << _name << " and he is originated from ClapTrap, whose name is " << ClapTrap::_name << "!" << std::endl ;
}
