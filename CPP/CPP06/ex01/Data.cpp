/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:33:04 by csolari           #+#    #+#             */
/*   Updated: 2026/02/03 16:08:55 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void) : _content("default")
{
	std::cout << "Default Data constructor" << std::endl;
}

Data::Data(Data &cpy)
{
	std::cout << "Data copy constructor" << std::endl;
	*this = cpy;
}

Data::~Data(void)
{
	std::cout << "Data destructor" << std::endl;
}

Data& Data::operator=(Data const &src)
{
	std::cout << "Data copy assignment operator" << std::endl;
	
	if (this != &src)
	{
		_content = src.getContent();
	}
	return *this;
}

std::string	Data::getContent(void) const
{
	return( _content);
}
