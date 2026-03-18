/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:54:13 by csolari           #+#    #+#             */
/*   Updated: 2026/02/27 19:59:11 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "Colors.hpp"
#include <iostream>
#include <vector>
#include <iterator>

Span::Span() : _size(0), _pos(0) {}

Span::Span(unsigned int N) : _size(N), _pos(0)
{
	std::cout << ORANGE << "Span constructor for " << N << " elements called" << RESET << std::endl;
	_span.reserve(_size);
}

Span::Span(Span const &cpy)
{
	std::cout << ORANGE << "Span copy constructor called" << RESET << std::endl;
	*this = cpy;
}

Span::~Span()
{
	std::cout << ORANGE << "Span destructor called" << RESET << std::endl;
}

Span & Span::operator=(Span const &src)
{
	std::cout << ORANGE << "Span assignment operator called" << RESET << std::endl;
	if (this != &src)
	{
		_span = src._span;
		_size = src._size;
		_pos = src._pos;
	}
	return(*this);
}

unsigned int	Span::getPos()
{
	return _pos ;
}

unsigned int	Span::getSize()
{
	return _size ;
}

std::vector<int>	Span::getSpan()
{
	return _span ;
}	

void	Span::addNumber(int number)
{
	if (_pos < _size)
	{
		_span.push_back(number);
		_pos++;
	}
	else
		throw FullSpanException();
}

void	Span::addNumber(std::vector<int>::iterator rangeStart, std::vector<int>::iterator rangeEnd)
{
	int	distance = std::distance(rangeStart, rangeEnd);
	if (_pos + distance > _size)
		throw FullSpanException();
	_span.insert(_span.end(), rangeStart, rangeEnd);
	_pos += distance;
}

int	Span::shortestSpan()
{
	int	shortest = 2147483647;
	int	tmp = 2147483647;

	std::vector<int>::const_iterator tempIt;

	if (_pos < 2)
		throw NoSpanPossibleException();
	for (std::vector<int>::const_iterator it = _span.begin(); it != _span.end(); ++it)
	{
		tempIt = it;
		for (std::vector<int>::const_iterator sc = ++tempIt ; sc != _span.end(); ++sc)
		{
			tmp = (*it > *sc ? *it - *sc : *sc - *it);
			if (tmp < shortest)
				shortest = tmp;
		}
	}
	return (shortest);
}

int	Span::longestSpan()
{
	int	lowest = 2147483647;
	int	higher = -2147483648;

	if (_pos < 2)
		throw NoSpanPossibleException();
	for (std::vector<int>::const_iterator it = _span.begin(); it != _span.end(); ++it)
	{
		if (*it < lowest)
			lowest = *it;
		if (*it > higher)
			higher = *it;
	}
	return (higher - lowest);
}


const char *Span::FullSpanException::what() const throw()
{
	return "Span storage full : it can't store new element";
}

const char *Span::NoSpanPossibleException::what() const throw()
{
	return "Not enought number stored, span calcul is not possible";
}
