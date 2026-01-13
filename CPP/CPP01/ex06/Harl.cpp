/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:19:02 by csolari           #+#    #+#             */
/*   Updated: 2025/10/24 18:31:07 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

Harl::Harl( void )
{
	// std::cout << "Harl constructor called" << std::endl;
	return ;
}

Harl::~Harl( void )
{
	// std::cout << "Harl destructor called" << std::endl;
	return ;

}

void	Harl::_debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl ;
	std::cout << "I really do!" << std::endl ;
}

void	Harl::_info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl  ;
	std::cout << "You didn't put enough bacon in my burger!"  << std::endl ;
	std::cout << "If you did, I wouldn't be asking for more!" << std::endl ;

}

void	Harl::_warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. " << std::endl ;
	std::cout << "I've been coming for years, whereas you started working" ;
	std::cout << " here just last month." << std::endl ;

}

void	Harl::_error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." ;
	std::cout << std::endl ;

}

void	Harl::complain( std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i;

	i = 0;
	while( i < 4)
	{
		if (level == levels[i])
		{
			break ;
		}
		i++;
	}
	switch(i)
	{
		case 4:
		std::cout <<  "[ Probably complaining about insignificant problems ]" << std::endl ;
		break;
		
		case 0:
		std::cout << "[ DEBUG ]" << std::endl;
		Harl::_debug();
		std::cout << std::endl ;

		case 1:
		std::cout << "[ INFO ]" << std::endl;
		Harl::_info();
		std::cout << std::endl ;

		case 2:
		std::cout << "[ WARNING ]" << std::endl;
		Harl::_warning();
		std::cout << std::endl ;

		case 3:
		std::cout << "[ ERROR ]" << std::endl;
		Harl::_error();
		std::cout << std::endl ;

		break;
	}

}
