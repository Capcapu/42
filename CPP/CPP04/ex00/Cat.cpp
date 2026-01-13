/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:48:13 by csolari           #+#    #+#             */
/*   Updated: 2025/10/29 16:11:46 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "colors.h"

Cat::Cat(void) : Animal("cat")
{
	_type = "cat";
	std::cout << GREEN_LIGHT << "Cat default constructor called" << RESET <<std::endl;
	return;
}

Cat::~Cat(void)
{
	std::cout << GREEN << "Cat destructor called" << RESET <<std::endl;
	return ;
}

Cat::Cat(const Cat &copy)
{
	std::cout << GREEN_LIGHT << "Cat copy constructor called" << RESET <<std::endl;
	*this = copy;
}

Cat	&Cat::operator=(const Cat& other)
{
	std::cout << GREEN_LIGHT << "Cat copy assignement operator called" << RESET <<std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << YELLOW << this->getType() << " says : Miaaaouuu" << RESET << std::endl ;
}

std::string	Cat::getType(void) const
{
	return (_type);
}
