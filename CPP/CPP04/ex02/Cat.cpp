/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:48:13 by csolari           #+#    #+#             */
/*   Updated: 2025/10/29 18:03:20 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "colors.h"
#include <cstdio>
#include <cstdlib>

Cat::Cat(void) : Animal("cat")
{
	std::cout << GREEN_LIGHT << "Cat default constructor called" << RESET <<std::endl;
	_type = "cat";
	_brain = new Brain();
	if (this->_brain == NULL)
	{
		perror("Cat Brain allocation failed");
		exit(1);
	}
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << GREEN << "Cat destructor called" << RESET <<std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy._type)
{
	std::cout << GREEN_LIGHT << "Cat copy constructor called" << RESET <<std::endl;
	this->_type = copy._type;
	this->_brain = new Brain(*copy._brain);
	if (this->_brain == NULL)
	{
		perror("Cat Brain allocation failed");
		exit(1);
	}
}

Cat	&Cat::operator=(const Cat& other)
{
	std::cout << GREEN_LIGHT << "Cat copy assignement operator called" << RESET <<std::endl;
	if (this == &other)
		return (*this);

	_type = other._type;
	delete this->_brain;
	this->_brain = new Brain(*other._brain);
	if (this->_brain == NULL)
	{
		perror("Cat Brain allocation failed");
		exit(1);
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

void	Cat::setIdeas(size_t i, std::string idea)
{
	this->_brain->setIdea(i, idea);
}

std::string	Cat::getIdeas(size_t i)
{
	return this->_brain->getIdea(i);
}
