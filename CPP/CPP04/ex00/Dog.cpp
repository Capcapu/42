/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:21:03 by csolari           #+#    #+#             */
/*   Updated: 2025/10/29 16:12:03 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include "colors.h"

Dog::Dog() : Animal("dog")
{
	_type = "dog";
	std::cout << GREEN_LIGHT << "Dog default constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog& other)
{
	std::cout << GREEN_LIGHT << "Dog copy constructor called" << RESET << std::endl;
	*this = other;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << GREEN_LIGHT << "Dog copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << GREEN << "Dog destructor called" << RESET << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << PURPLE << this->getType() << " says : Ouuuaaff" << RESET << std::endl ;
}

std::string	Dog::getType(void) const
{
	return (_type);
}
