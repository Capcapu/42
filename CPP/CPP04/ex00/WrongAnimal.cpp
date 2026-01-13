/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:41:36 by csolari           #+#    #+#             */
/*   Updated: 2025/10/29 15:41:36 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "colors.h"

WrongAnimal::WrongAnimal()
{
	_type = "wrongAnimal default";
	std::cout << GREEN_LIGHT << "WrongAnimal default constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << GREEN_LIGHT << "Animal constructor, which initialize values, called" << RESET <<std::endl;
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << GREEN_LIGHT << "WrongAnimal copy constructor called" << RESET << std::endl;
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << GREEN_LIGHT << "WrongAnimal copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << GREEN << "WrongAnimal destructor called" << RESET << std::endl;
}


void	WrongAnimal::makeSound(void)const
{
	std::cout << RED << "WrongAnimal sound!" << RESET << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (_type);
}
