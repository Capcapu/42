/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:19:02 by csolari           #+#    #+#             */
/*   Updated: 2025/10/24 15:48:09 by csolari          ###   ########.fr       */
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
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-" ;
	std::cout << "pickle-special-ketchup burger. I really do!" << std::endl ;
}

void	Harl::_info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You " ;
	std::cout << "didn't put enough bacon in my burger! If you did, I " ;
	std::cout << "wouldn't be asking for more!" << std::endl ;

}

void	Harl::_warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. " ;
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
	void	(Harl::*fonctionPtr[4])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*fonctionPtr[i])();
			return ;
		}
	}
	std::cout << "Invalid level entered" << std::endl ;
}
