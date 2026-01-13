/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:48:56 by csolari           #+#    #+#             */
/*   Updated: 2025/10/29 15:48:56 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "colors.h"

WrongCat::WrongCat() : WrongAnimal("wrongCat")
{
	_type = "wrongCat";
	std::cout << GREEN_LIGHT << "WrongCat default constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
{
	std::cout << GREEN_LIGHT << "WrongCat copy constructor called" << RESET << std::endl;
	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << GREEN_LIGHT << "WrongCat copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << GREEN << "WrongCat destructor called" << RESET << std::endl;
}


void	WrongCat::makeSound(void)
{
	std::cout << BLUE << this->getType() << " says : WRONGMiaaaouuu" << RESET << std::endl ;
}

std::string	WrongCat::getType(void) const
{
	return (_type);
}
