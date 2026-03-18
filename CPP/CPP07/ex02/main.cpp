/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:02:14 by csolari           #+#    #+#             */
/*   Updated: 2026/02/11 11:16:58 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	try {
	std::cout << BOLD_YELLOW << "\n=== Test 1: Constructeur par défaut ===" << RESET << std::endl;
	{
		Array<int> emptyArray;
		std::cout << "Size: " << emptyArray.size() << std::endl;
	}
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception : " << e.what() << RESET << std::endl;
	}

	//--------------------------------------

	try {
	std::cout << BOLD_YELLOW << "\n=== Test 2: Constructeur avec n éléments ===" << RESET << std::endl;
	{
		Array<int> intArray(5);
		std::cout << "Size: " << intArray.size() << std::endl;
		
		// Remplissage du tableau
		for (unsigned int i = 0; i < intArray.size(); i++)
			intArray[i] = i * 10;
		
		// Affichage
		std::cout << "Values: ";
		for (unsigned int i = 0; i < intArray.size(); i++)
			std::cout << intArray[i] << " ";
		std::cout << std::endl;
	}
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception : " << e.what() << RESET << std::endl;
	}

	//--------------------------------------

	try {
	std::cout << BOLD_YELLOW << "\n=== Test 3: Copy constructor ===" << RESET << std::endl;
	{
		Array<int> original(3);
		original[0] = 42;
		original[1] = 21;
		original[2] = 84;
		
		Array<int> copy(original);
		std::cout << "Original: ";
		for (unsigned int i = 0; i < original.size(); i++)
			std::cout << original[i] << " ";
		std::cout << std::endl << "Copy: ";
		for (unsigned int i = 0; i < copy.size(); i++)
			std::cout << copy[i] << " ";
		std::cout << std::endl;
		
		// Modification de la copie
		copy[0] = 999;
		std::cout << "After modifying copy[0] to 999:" << std::endl;
		std::cout << "Original[0]: " << original[0] << std::endl;
		std::cout << "Copy[0]: " << copy[0] << std::endl;
	}
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception : " << e.what() << RESET << std::endl;
	}

	//--------------------------------------

	try {
	std::cout << BOLD_YELLOW << "\n=== Test 4: Assignment operator ===" << RESET << std::endl;
	{
		Array<int> a(3);
		a[0] = 1;
		a[1] = 2;
		a[2] = 3;
		
		Array<int> b(5);
		b = a;
		
		std::cout << "After b = a:" << std::endl;
		std::cout << "b size: " << b.size() << std::endl;
		std::cout << "b values: ";
		for (unsigned int i = 0; i < b.size(); i++)
			std::cout << b[i] << " ";
		std::cout << std::endl;
	}
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception : " << e.what() << RESET << std::endl;
	}

	//--------------------------------------

	std::cout << BOLD_YELLOW << "\n=== Test 5: Exception - index invalide ===" << RESET << std::endl;
	{
		Array<int> arr(5);
		try
		{
			std::cout << "Tentative d'accès à arr[10]..." << std::endl;
			arr[10] = 42;
		}
		catch (std::exception & e)
		{
			std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
		}
		
		try
		{
			std::cout << "Tentative d'accès à arr[-1]..." << std::endl;
			arr[-1] = 42;
		}
		catch (std::exception & e)
		{
			std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
		}
	}

	//--------------------------------------

	try {
	std::cout << BOLD_YELLOW << "\n=== Test 6: Array de strings ===" << RESET << std::endl;
	{
		Array<std::string> strArray(3);
		strArray[0] = "Hello";
		strArray[1] = "World";
		strArray[2] = "!";
		
		std::cout << "String array: ";
		for (unsigned int i = 0; i < strArray.size(); i++)
			std::cout << strArray[i] << " ";
		std::cout << std::endl;
	}
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception : " << e.what() << RESET << std::endl;
	}

	//--------------------------------------

	try {
	std::cout << BOLD_YELLOW << "\n=== Test 7: Array de doubles ===" << RESET << std::endl;
	{
		Array<double> doubleArray(4);
		doubleArray[0] = 3.14;
		doubleArray[1] = 2.71;
		doubleArray[2] = 1.41;
		doubleArray[3] = 1.73;
		
		std::cout << "Double array: ";
		for (unsigned int i = 0; i < doubleArray.size(); i++)
			std::cout << doubleArray[i] << " ";
		std::cout << std::endl;
	}
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception : " << e.what() << RESET << std::endl;
	}

	return 0;
}
