/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 23:20:02 by csolari           #+#    #+#             */
/*   Updated: 2025/10/25 17:45:43 by csolari          ###   ########.fr       */
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
	Fixed &operator=(const Fixed& other);
	~Fixed( void );
	int					toInt( void ) const;
	float				toFloat( void ) const;

};

std::ostream &operator<<(std::ostream &out, const Fixed &f);


#endif