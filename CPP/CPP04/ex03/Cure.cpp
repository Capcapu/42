/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:06:26 by csolari           #+#    #+#             */
/*   Updated: 2025/10/30 14:06:26 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "colors.h"

Cure::Cure() : AMateria("cure")
{
	std::cout << GREEN_LIGHT << "Cure default constructor called" << RESET << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other)
{
	std::cout << GREEN_LIGHT << "Cure copy constructor called" << RESET << std::endl;
	*this = other;
}

Cure& Cure::operator=(const Cure& other) 
{
	std::cout << GREEN_LIGHT << "Cure copy assignment operator called" << RESET << std::endl;
	AMateria::operator=(other);
	return *this;
}

Cure::~Cure()
{
	std::cout << GREEN << "Cure destructor called" << RESET << std::endl;
}

Cure* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl ;
}




