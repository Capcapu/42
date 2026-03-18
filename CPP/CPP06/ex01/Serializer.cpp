/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:38:09 by csolari           #+#    #+#             */
/*   Updated: 2026/02/04 12:23:22 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
	std::cout << "Default Serializer constructor" << std::endl;
}

Serializer::Serializer(Serializer &cpy)
{
	std::cout << "Serializer copy constructor" << std::endl;
	*this = cpy;
}

Serializer::~Serializer(void)
{
	std::cout << "Serializer destructor" << std::endl;

}

Serializer const Serializer::operator=(Serializer const &src)
{
	(void)src;
	std::cout << "Serializer copy assignment operator" << std::endl;
	//nothing to copy
	return *this;
}

//--------------------------------------------

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* 		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
