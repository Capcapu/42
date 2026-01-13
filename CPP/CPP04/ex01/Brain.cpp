/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:43:25 by csolari           #+#    #+#             */
/*   Updated: 2025/10/29 16:43:25 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "colors.h"

Brain::Brain()
{
	std::cout << GREEN_LIGHT << "Brain default constructor called" << RESET << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << GREEN_LIGHT << "Brain copy constructor called" << RESET << std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << GREEN_LIGHT << "Brain copy assignment operator called" << RESET << std::endl;
	if (this == &other)
		return (*this);
	for (int i = 0; i < 100; i++)
	{
		if (other._ideas[i].length() > 0)
			this->_ideas[i].assign(other._ideas[i]);
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << GREEN << "Brain destructor called" << RESET << std::endl;
}

void	Brain::setIdea(size_t i, std::string idea)
{
	if (i < 100)
		_ideas[i] = idea;
	else
		std::cout << "There is only 100 ideas per brain, " << i << "is too big" <<std::endl ;
}

std::string	Brain::getIdea(size_t i) const
{
	if (i < 100)
		return(this->_ideas[i]);
	else
		return( "There is only 100 ideas per brain\n");
}
