/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:00:00 by csolari           #+#    #+#             */
/*   Updated: 2025/10/30 16:05:53 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "colors.h"

MateriaSource::MateriaSource()
{
	std::cout << GREEN_LIGHT << "MateriaSource constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		_learned[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	std::cout << GREEN_LIGHT << "MateriaSource copy constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other._learned[i])
		{
			_learned[i] = other._learned[i]->clone();
			if (!this->_learned[i])
			{
				perror("MateriaSource learned clone failed");
				exit(1);
			}
		}
		else
			_learned[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	std::cout << GREEN_LIGHT << "MateriaSource copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_learned[i])
			{
				delete _learned[i];
				_learned[i] = NULL;
			}
		}
		
		for (int i = 0; i < 4; i++)
		{
			if (other._learned[i])
				_learned[i] = other._learned[i]->clone();
			if (!this->_learned[i])
			{
				perror("MateriaSource learned clone failed");
				exit(1);
			}
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << GREEN << "MateriaSource destructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_learned[i])
			delete _learned[i];
	}
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (!materia)
		return;
	
	for (int i = 0; i < 4; i++)
	{
		if (!_learned[i])
		{
			_learned[i] = materia;
			std::cout << "MateriaSource learned " << materia->getType() << std::endl;
			return;
		}
	}
	std::cout << "MateriaSource inventory full, cannot learn more materias" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_learned[i] && _learned[i]->getType() == type)
		{
			std::cout << "MateriaSource creating " << type << std::endl;
			return _learned[i]->clone();
		}
	}
	std::cout << "MateriaSource cannot create " << type << " (not learned)" << std::endl;
	return NULL;
}