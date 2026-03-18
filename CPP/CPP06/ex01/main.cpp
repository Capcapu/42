/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:38:12 by csolari           #+#    #+#             */
/*   Updated: 2026/02/03 16:15:51 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int	main()
{
	Data	*ptr = new Data;
	uintptr_t raw;

	// std::cout << ptr <<std::endl;
	std::cout << "\"" << ptr->getContent() << "\" is data content !" << std::endl;

	raw = Serializer::serialize(ptr);

	std::cout << raw <<std::endl;

	Data	*other;
	other = Serializer::deserialize(raw);
	
	// std::cout << other <<std::endl;
	std::cout << "\"" << other->getContent() << "\" is data content !" << std::endl;

	delete ptr;
	return 0;
}