/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:56:15 by csolari           #+#    #+#             */
/*   Updated: 2026/02/21 17:58:36 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Colors.hpp"
#include <exception>
#include <cstdio>
#include <iostream>

template <typename T>
class	Array
{
	public :
		Array(void) : _size(0) // creates empty array
		{
			std::cout << ORANGE << "Default Array constructor called" << RESET << std::endl;
			this->_a = new T[this->_size];
		};

		Array(unsigned int n) : _size(n) //creates array n elements initialized by default
		{
			std::cout << ORANGE << "Array constructor for n elements called" << RESET << std::endl;
			this->_a = new T[this->_size];
		}; 

		Array(Array const & cpy) : _a(NULL), _size(0) //cpy constructor
		{
			std::cout << ORANGE << "Array copy constructor called" << RESET << std::endl;
			*this = cpy;
		};
		
		T	&operator[](unsigned int index)
		{
			if (index >= this->_size)
				throw Array<T>::InvalidIndexException();
			return (this->_a[index]);
		};

		const T &operator[](unsigned int index) const
		{
			if (index >= this->_size )
				throw Array<T>::InvalidIndexException();
			return (this->_a[index]);
		};

		Array 	&operator=(Array const & src) //assignment operator
		{
			std::cout << ORANGE << "Array assignment operator called" << RESET << std::endl;
			if (this == &src)
				return *this;
			
			delete [] this->_a;
			this->_size = src.size();
			if (_size > 0)	
				this->_a = new T[this->_size];
			else
				this->_a = NULL; // pour que _a soit tj initialisé
			for (unsigned int i = 0; i < _size; i++)
				this->_a[i] = src._a[i];
			return *this;
		};

		~Array(void)
		{
			std::cout << ORANGE << "Array destructor called" << RESET << std::endl;
			if (this->_a != NULL)
				delete [] this->_a;
		};

		T	*getA(void) const {return _a;};
		unsigned int	size(void) const {return _size;};

		class InvalidIndexException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
	
	private :
		T				*_a;
		unsigned int	_size;
};


template <typename T>
const char	*Array<T>::InvalidIndexException::what() const throw()
{
	return ("Error : Invalid index");
}
// ici Array ne serait pas un type complet mais juste un template de classe,
// je mets Array<T> qui est le type reel, c est une instanciation du 
// template avec le parametre T.