/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:49:22 by csolari           #+#    #+#             */
/*   Updated: 2025/10/30 11:49:22 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "colors.h"

AMateria::AMateria()
{
	_type = "default";
	std::cout << GREEN_LIGHT << "AMateria default constructor called" << RESET << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
	std::cout << GREEN_LIGHT << "AMateria copy constructor called" << RESET << std::endl;
	*this = other;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	std::cout << GREEN_LIGHT << "AMateria copy assignment operator called" << RESET << std::endl;
	if (this == &other)
		return(*this);
	this->_type = other._type;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << GREEN << "AMateria destructor called" << RESET << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << BLUE << "AMateria constructor, which initialize type, called" << RESET <<std::endl;
	return ;
}


std::string const & AMateria::getType() const 
{
	return (_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Amateria use() called, but does nothing to " << target.getName() << std::endl ;
	return;
}
