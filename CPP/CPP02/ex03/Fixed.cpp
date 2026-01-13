/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 23:20:56 by csolari           #+#    #+#             */
/*   Updated: 2025/10/27 15:25:12 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "math.h"
#include <iostream>
Fixed::Fixed(void): _intC(0)
{
	// std::cout << "Default constructor called" <<std::endl;
	return;
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" <<std::endl;
	return ;
}

Fixed::Fixed(int nb)
{
	// std::cout << "Int constructor called" <<std::endl;
	_intC = nb << _nb;
	return ;
}

Fixed::Fixed( float nbf)
{
	// std::cout << "Float constructor called" <<std::endl;
	_intC = roundf((nbf * (1 << _nb)));
	return ;
}

Fixed::Fixed(const Fixed &copy)
{
	// std::cout << "Copy constructor called" <<std::endl;
	*this = copy;
}

int	Fixed::getRawBits() const
{
	// std::cout << "getintC member function called" <<std::endl;
	return (_intC);
}

void	Fixed::setRawBits( int const raw)
{
	_intC = raw;
}

int	Fixed::toInt( void ) const
{
	return( _intC >> _nb);
}

float	Fixed::toFloat( void ) const
{
	return(static_cast<float>(_intC)/ ( 1 << _nb));
}

std::ostream &operator<<(std::ostream &out, const Fixed &f)
{
	out << f.toFloat();
	return (out);
}

Fixed	&Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		_intC = other._intC;
	return (*this);
}

bool	Fixed::operator>(const Fixed& other)
{
	return (this->toFloat() > other.toFloat());
}

bool	Fixed::operator<(const Fixed& other)
{
	return (this->toFloat() < other.toFloat());
}

bool	Fixed::operator>=(const Fixed& other)
{
	return (this->toFloat() >= other.toFloat());
}

bool	Fixed::operator<=(const Fixed& other)
{
	return (this->toFloat() <= other.toFloat());
}

bool	Fixed::operator==(const Fixed& other)
{
	return (this->toFloat() == other.toFloat());
}

bool	Fixed::operator!=(const Fixed& other)
{
	return (this->toFloat() != other.toFloat());
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	return (Fixed(toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	return (Fixed(toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	return (Fixed(toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	return (Fixed(toFloat() / other.toFloat()));
}

//pre-incrementation
Fixed	Fixed::operator++( void )
{
	_intC++;
	return (*this);
}

Fixed	Fixed::operator--( void )
{
	_intC--;
	return (*this);
}

//post-incrementation
Fixed	Fixed::operator++( int )
{
	Fixed	temp = *this;
	_intC++;
	return (temp);
}

Fixed	Fixed::operator--( int )
{
	Fixed	temp = *this;
	_intC--;
	return (temp);
}

Fixed	&Fixed::min(Fixed& first, Fixed& second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

Fixed	&Fixed::max(Fixed& first, Fixed& second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::min(const Fixed& first, const Fixed& second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::max(const Fixed& first, const Fixed& second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}
