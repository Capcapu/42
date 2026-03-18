/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:02:53 by csolari           #+#    #+#             */
/*   Updated: 2026/01/22 18:34:41 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Colors.hpp"

int	main()
{
	std::cout << BOLD_YELLOW << "\n--- " << "Valid constructions" << " ---" << RESET << std::endl;
	try
	{
		Bureaucrat ros(150);
		Bureaucrat jim("Jim", 12);
		Bureaucrat tom("Tom");
		Bureaucrat ema = jim;

		std::cout << &ros;
		std::cout << &jim;
		std::cout << &tom;
		std::cout << &ema;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	//---------------------------------

	std::cout << BOLD_YELLOW << "\n--- " << "Bureaucrat grade boundary checks" << " ---" << RESET << std::endl;
	try
	{
		Bureaucrat tooHigh("TooHigh", 0);
		std::cout << &tooHigh;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Grade 0 -> " << e.what() << RESET << std::endl;
	}
	try
	{
		Bureaucrat tooLow("TooLow", 151);
		std::cout << &tooLow;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Grade 151 -> " << e.what() << RESET << std::endl;
	}

	//---------------------------------

	std::cout << BOLD_YELLOW << "\n--- " << "SetGrade boundary checks" << " ---" << RESET << std::endl;
	try
	{
		Bureaucrat alice("Alice", 50);
		std::cout << &alice;
		alice.setGrade(1);
		std::cout << &alice;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "SetGrade -> " << e.what() << RESET << std::endl;
	}
	try
	{
		Bureaucrat bob("Bob", 75);
		bob.setGrade(151);
		std::cout << &bob;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "SetGrade -> " << e.what() << RESET << std::endl;
	}

	//---------------------------------

	std::cout << BOLD_YELLOW << "\n--- " << "Grade increment limits" << " ---" << RESET << std::endl;
	try
	{
		Bureaucrat carl("Carl", 2);
		std::cout << &carl;
		carl.incraseGrade();
		std::cout << &carl;
		carl.incraseGrade();
		std::cout << "THIS SHOULD NOT PRINT" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Increment -> " << e.what() << RESET << std::endl;
	}

	//---------------------------------

	std::cout << BOLD_YELLOW << "\n--- " << "Grade decrement limits" << " ---" << RESET << std::endl;
	try
	{
		Bureaucrat diana("Diana", 149);
		std::cout << &diana;
		diana.decreaseGrade();
		std::cout << &diana;
		diana.decreaseGrade();
		std::cout << "THIS SHOULD NOT PRINT" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Decrement -> " << e.what() << RESET << std::endl;
	}

	return (0);
}
