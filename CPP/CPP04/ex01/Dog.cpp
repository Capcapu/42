/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:21:03 by csolari           #+#    #+#             */
/*   Updated: 2025/10/29 18:03:33 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include "colors.h"
#include <cstdio>
#include <cstdlib>

Dog::Dog() : Animal("dog")
{
	std::cout << GREEN_LIGHT << "Dog default constructor called" << RESET << std::endl;
	_type = "dog";
	_brain = new Brain();
	if (this->_brain == NULL)
	{
		perror("Dog Brain allocation failed");
		exit(1);
	}
}

Dog::Dog(const Dog& other) : Animal(other._type)
{
	std::cout << GREEN_LIGHT << "Dog copy constructor called" << RESET << std::endl;
	this->_type = other._type;
	this->_brain = new Brain(*other._brain);
	if (this->_brain == NULL)
	{
		perror("Dog Brain allocation failed");
		exit(1);
	}
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << GREEN_LIGHT << "Dog copy assignment operator called" << RESET << std::endl;
	if (this == &other)
		return(*this);
	this->_type = other._type;
	delete this->_brain;
	this->_brain = new Brain(*other._brain);
	if (this->_brain == NULL)
	{
		perror("Dog Brain allocation failed");
		exit(1);
	}
	return *this;
}

Dog::~Dog()
{
	delete _brain;
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

void	Dog::setIdeas(size_t i, std::string idea)
{
	this->_brain->setIdea(i, idea);
}

std::string	Dog::getIdeas(size_t i)
{
	return this->_brain->getIdea(i);
}
