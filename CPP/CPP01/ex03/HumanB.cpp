/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:32:37 by csolari           #+#    #+#             */
/*   Updated: 2025/10/23 18:42:46 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.h"

HumanB::HumanB( std::string name ) : _name(name), _weapon(NULL)
{
	std::cout << "HumanB constructor called" <<std::endl;
	return;
}

HumanB::~HumanB( void )
{
	std::cout << "HumanB destructor called" <<std::endl;
	return ;
}

std::string	HumanB::getName(void)const
{
	return (_name);
}

void	HumanB::setName(std::string name)
{
	_name = name;
}

void	HumanB::attack(void)const
{
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " attacks without weapon" << std::endl;
}

std::string HumanB::getWeaponType(void)const
{
	if (_weapon)
		return(_weapon->getType());
	return("no weapon");
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}
