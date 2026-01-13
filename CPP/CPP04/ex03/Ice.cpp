/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:06:21 by csolari           #+#    #+#             */
/*   Updated: 2025/10/30 15:58:31 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "colors.h"

Ice::Ice() : AMateria("ice")
{
	std::cout << GREEN_LIGHT << "Ice default constructor called" << RESET << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other)
{
	std::cout << GREEN_LIGHT << "Ice copy constructor called" << RESET << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
	std::cout << GREEN_LIGHT << "Ice copy assignment operator called" << RESET << std::endl;
	if (this == &other)
		return (*this);
	AMateria::operator=(other);
	return *this;
}

Ice::~Ice()
{
	std::cout << GREEN << "Ice destructor called" << RESET << std::endl;
}

Ice* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl ;
}
