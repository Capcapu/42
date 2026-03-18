/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:54:19 by csolari           #+#    #+#             */
/*   Updated: 2026/02/27 19:58:32 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "Colors.hpp"
#include <iostream>
#include <vector>

int main()
{
	//-------------------------------------------------------------
	try
	{
		std::cout << BOLD_YELLOW << "===== TEST 1 : basic usage =====" << RESET << std::endl;

		Span sp = Span(-5);
		sp.addNumber(-6);
		sp.addNumber(-3);
		sp.addNumber(-17);
		sp.addNumber(-9);
		sp.addNumber(-11);

		std::cout << PINK << "shortestSpan : " << sp.shortestSpan() << RESET << std::endl;
		std::cout << PINK << "longestSpan  : " << sp.longestSpan() << RESET << std::endl;
		std::cout << CYAN << "getPos()     : " << sp.getPos() << RESET << std::endl;
		std::cout << CYAN << "getSize()    : " << sp.getSize() << RESET << std::endl;
		std::cout << CYAN << "span.size()  : " << sp.getSpan().size() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED << "exception (TEST 1) : " << e.what() << RESET << std::endl;
	}

	//-------------------------------------------------------------
	try
	{
		std::cout << BOLD_YELLOW << "\n===== TEST 2 : FullSpan with addNumber() =====" << RESET << std::endl;

		Span sp(3);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		// Doit déclencher FullSpanException
		sp.addNumber(4);
	}
	catch (std::exception &e)
	{
		std::cerr << RED << "exception (TEST 2) : " << e.what() << RESET << std::endl;
	}

	//-------------------------------------------------------------
	try
	{
		std::cout << BOLD_YELLOW << "\n===== TEST 3 : NoSpanPossible =====" << RESET << std::endl;

		Span sp(5);
		sp.addNumber(42);
		// Pas assez de nombres pour calculer un span
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED << "exception (TEST 3) : " << e.what() << RESET << std::endl;
	}

	//-------------------------------------------------------------
	try
	{
		std::cout << BOLD_YELLOW << "\n===== TEST 4 : range addNumber() + overflow =====" << RESET << std::endl;

		Span spRange(3);
		std::vector<int> values;
		values.push_back(10);
		values.push_back(20);
		values.push_back(30);
		values.push_back(40);

		// On remplit correctement avec 2 éléments
		spRange.addNumber(values.begin(), values.begin() + 2);
		std::cout << CYAN << "shortestSpan : " << spRange.shortestSpan() << RESET << std::endl;
		std::cout << CYAN << "longestSpan  : " << spRange.longestSpan() << RESET << std::endl;

		// Ici on essaie d'en ajouter trop -> FullSpanException
		spRange.addNumber(values.begin() + 2, values.end());
	}
	catch (std::exception &e)
	{
		std::cerr << RED << "exception (TEST 4) : " << e.what() << RESET << std::endl;
	}

	//-------------------------------------------------------------
	try
	{
		std::cout << BOLD_YELLOW << "\n===== TEST 5 : large Span (10 000 numbers) =====" << RESET << std::endl;

		const unsigned int bigSize = 10000;
		Span bigSpan(bigSize);
		std::vector<int> bigVector;
		bigVector.reserve(bigSize);

		for (unsigned int i = 0; i < bigSize; ++i)
			bigVector.push_back(i);

		bigSpan.addNumber(bigVector.begin(), bigVector.end());

		std::cout << CYAN << "shortestSpan (expected 1) : "
				  << bigSpan.shortestSpan() << RESET << std::endl;
		std::cout << CYAN << "longestSpan  (expected 9999) : "
				  << bigSpan.longestSpan() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED << "exception (TEST 5) : " << e.what() << RESET << std::endl;
	}

	return 0;
}