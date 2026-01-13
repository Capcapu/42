/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:45:51 by csolari           #+#    #+#             */
/*   Updated: 2025/10/30 14:45:51 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "colors.h"
#include <cstdio>
#include <cstdlib>

Character::Character(std::string const name) : _name(name)
{
	std::cout << GREEN_LIGHT << "Character constructor called with name: " << name << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character& copy) : _name(copy._name)
{
	std::cout << GREEN_LIGHT << "Character copy constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	
	for(int i = 0; i < 4; i++)
	{
		if (copy._inventory[i])
		{
			this->_inventory[i] = copy._inventory[i]->clone(); //j'utilise clone car AMateria est abstraite
			if (!this->_inventory[i])
			{
				perror("Character AMateria inventory clone failed");
				exit(1);
			}
		}
	}
}

Character& Character::operator=(const Character& other)
{
	std::cout << GREEN_LIGHT << "Character copy assignment operator called" << RESET << std::endl;
	if (this == &other)
		return(*this);
	this->_name = other._name;
	for(int i = 0; i < 4; i++)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
	for(int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
		{
			this->_inventory[i] = other._inventory[i]->clone();
			if (!this->_inventory[i])
			{
				perror("Character AMateria inventory clone failed");
				exit(1);
			}
		}
		else 
			this->_inventory[i] = NULL;
	}
	return *this;
}

Character::~Character()
{
	std::cout << GREEN << "Character destructor called for " << _name << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
}

std::string const & Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0 ; i < 4 ; i++)
	{
		if (! _inventory[i])
		{
			_inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		if (_inventory[idx])
			_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
	{
		_inventory[idx]->use(target);
	}
}


