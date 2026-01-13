/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:25:04 by csolari           #+#    #+#             */
/*   Updated: 2025/10/23 17:57:35 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"

Weapon::Weapon( void )
{
	return;
}

Weapon::Weapon( std::string type )
{
	std::cout << "Weapon constructor called" <<std::endl;
	setType(type);
	return;
}

Weapon::~Weapon( void )
{
	std::cout << "Weapon destructor called" <<std::endl;
	return ;
}

std::string	Weapon::getType(void)const
{
	return (_type);
}

void	Weapon::setType(std::string type)
{
	_type = type;
}

