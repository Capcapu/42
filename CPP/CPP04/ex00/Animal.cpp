/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:39:08 by csolari           #+#    #+#             */
/*   Updated: 2025/10/29 16:12:24 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>
#include "colors.h"

Animal::Animal(void)
{
	_type = "animal default";
	std::cout << GREEN_LIGHT << "Animal default constructor called" << RESET <<std::endl;
	return;
}

Animal::~Animal(void)
{
	std::cout << GREEN << "Animal destructor called" << RESET <<std::endl;
	return ;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << GREEN_LIGHT << "Animal constructor, which initialize values, called" << RESET <<std::endl;
	return ;
}


Animal::Animal(const Animal &copy)
{
	std::cout << GREEN_LIGHT << "Animal copy constructor called" << RESET <<std::endl;
	*this = copy;
}

Animal	&Animal::operator=(const Animal& other)
{
	std::cout << GREEN_LIGHT << "Animal copy assignement operator called" << RESET <<std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return (*this);
}

void	Animal::makeSound(void)const
{
	std::cout << RED << "Animal sound!" << RESET << std::endl;
}

std::string	Animal::getType(void) const
{
	return (_type);
}
