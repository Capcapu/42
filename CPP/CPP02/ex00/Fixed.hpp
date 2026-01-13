/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 23:20:02 by csolari           #+#    #+#             */
/*   Updated: 2025/10/27 14:54:27 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <stdlib.h>

class Fixed {

	private:

	int					_rawBits;
	static int const	_nb = 8;

	public:

	Fixed( void );
	Fixed(const Fixed& copy);
	Fixed &operator=(const Fixed& other);
	~Fixed( void );
	int					getRawBits() const;
	void				setRawBits( int const raw);
};

#endif