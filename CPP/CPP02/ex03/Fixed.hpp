/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 23:20:02 by csolari           #+#    #+#             */
/*   Updated: 2025/10/27 14:23:39 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <stdlib.h>

class Fixed {

	private:

	int					_intC;
	static int const	_nb = 8;

	public:

	Fixed( void );
	Fixed(const Fixed& copy);
	Fixed(int	nb);
	Fixed(float nbf);
	~Fixed( void );
	int					getRawBits() const;
	void				setRawBits( int const raw);
	int					toInt( void ) const;
	float				toFloat( void ) const;
	Fixed				&operator=(const Fixed& other);
	bool 				operator>(const Fixed& other);
	bool 				operator<(const Fixed& other);
	bool 				operator>=(const Fixed& other);
	bool 				operator<=(const Fixed& other);
	bool 				operator==(const Fixed& other);
	bool 				operator!=(const Fixed& other);
	Fixed				operator+(const Fixed& other) const;
	Fixed				operator-(const Fixed& other) const;
	Fixed				operator*(const Fixed& other) const;
	Fixed				operator/(const Fixed& other) const;
	Fixed				operator++( void );
	Fixed				operator--( void );
	Fixed				operator++( int );
	Fixed				operator--( int );
	static Fixed		&min(Fixed& first, Fixed& second);
	static Fixed		&max(Fixed& first, Fixed& second);
	static const Fixed	&min(const Fixed& first, const Fixed& second);
	static const Fixed	&max(const Fixed& first, const Fixed& second);
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);


#endif