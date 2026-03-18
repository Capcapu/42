/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:03:58 by csolari           #+#    #+#             */
/*   Updated: 2026/02/26 14:35:16 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "Colors.hpp"
#include <list>

int	main(void)
{
	std::list<int> test;
	test.push_back(6);
	test.push_back(12);
	test.push_back(42);
	
	std::list<int>::const_iterator	it;

	try
	{
		it = ::easyfind(test, 12);
		if (it != test.end())
			std::cout << *it << std::endl;

	}
	catch (std::exception &e)
	{
		std::cerr << RED << "Exception : " << e.what() << RESET << std::endl;
	}


	try
	{
		it = ::easyfind(test, 15);
		if (it != test.end())
			std::cout << *it << std::endl;

	}
	catch (std::exception &e)
	{
		std::cerr << RED << "Exception : " << e.what() << RESET << std::endl;
	}


	try
	{
		it = ::easyfind(test, 42);
		if (it != test.end())
			std::cout << *it << std::endl;

	}
	catch (std::exception &e)
	{
		std::cerr << RED << "Exception : " << e.what() << RESET << std::endl;
	}

}
