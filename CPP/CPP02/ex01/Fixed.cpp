/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 23:20:56 by csolari           #+#    #+#             */
/*   Updated: 2025/10/25 17:45:53 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "math.h"
#include <iostream>
Fixed::Fixed(void): _intC(0)
{
	std::cout << "Default constructor called" <<std::endl;
	return;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" <<std::endl;
	return ;
}

Fixed::Fixed(int nb)
{
	std::cout << "Int constructor called" <<std::endl;

	_intC = nb << _nb;
	return ;
}

Fixed::Fixed( float nbf)
{
	std::cout << "Float constructor called" <<std::endl;

	_intC = roundf((nbf * (1 << _nb)));
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
		_intC = other._intC;
	return (*this);
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
