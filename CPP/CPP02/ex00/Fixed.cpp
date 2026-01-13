/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 23:20:56 by csolari           #+#    #+#             */
/*   Updated: 2025/10/27 14:23:20 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
Fixed::Fixed(void): _rawBits(0)
{
	std::cout << "Default constructor called" <<std::endl;
	return;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" <<std::endl;
	return ;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" <<std::endl;
	*this = copy;
}

Fixed	&Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignement operator called" <<std::endl;
	if (this != &other)
		this->_rawBits = other.getRawBits();
	return (*this);
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" <<std::endl;
	return (_rawBits);
}

void	Fixed::setRawBits( int const raw)
{
	_rawBits = raw;
}
