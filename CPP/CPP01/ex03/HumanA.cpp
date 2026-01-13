/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:32:46 by csolari           #+#    #+#             */
/*   Updated: 2025/10/23 18:28:03 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.h"

HumanA::HumanA( std::string name, Weapon& weapon ) : _name(name), _weapon(weapon)
{
	std::cout << "HumanA constructor called" <<std::endl;
	return;
}

HumanA::~HumanA( void )
{
	std::cout << "HumanA destructor called" <<std::endl;
	return ;
}

std::string	HumanA::getName(void)const
{
	return (_name);
}

void	HumanA::setName(std::string name)
{
	_name = name;
}

void	HumanA::attack(void)const
{
	std::cout << HumanA::getName() << " attacks with their " << HumanA::getWeaponType() << std::endl;
}

std::string HumanA::getWeaponType(void)const
{
	return(_weapon.getType());
}

void	HumanA::setWeapon(Weapon &weapon)
{
	_weapon = weapon;
}

