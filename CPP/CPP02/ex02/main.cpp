/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:49:36 by csolari           #+#    #+#             */
/*   Updated: 2025/10/27 16:46:43 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed a;
	Fixed  b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b-- << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	if (a > b)
		std::cout <<"oui" << std::endl;
	else
		std::cout <<"non" << std::endl;

	Fixed c (5);
	Fixed d (2);

	std::cout << c - d <<std ::endl;

	
	
	return 0;
}
