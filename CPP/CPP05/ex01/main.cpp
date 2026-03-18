/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:02:53 by csolari           #+#    #+#             */
/*   Updated: 2026/01/22 18:29:28 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Colors.hpp"

int	main()
{
	std::cout << BOLD_YELLOW << "\n--- " << "Valid constructions and signature" << " ---" << RESET << std::endl;
	try
	{
		Form		passport("Passport", 50, 25);
		Bureaucrat	jim("Jim", 45);

		std::cout << &passport;
		std::cout << &jim;
		passport.signForm(&jim);
		std::cout << &passport;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	//---------------------------------

	std::cout << BOLD_YELLOW << "\n--- " << "Signature refused: grade too low" << " ---" << RESET << std::endl;
	try
	{
		Form		contract("Contract", 30, 10);
		Bureaucrat	bob("Bob", 80);

		std::cout << &contract;
		std::cout << &bob;
		contract.signForm(&bob);
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	//---------------------------------

	std::cout << BOLD_YELLOW << "\n--- " << "Already signed form" << " ---" << RESET << std::endl;
	try
	{
		Form		list("List", 70, 40);
		Bureaucrat	carl("Carl", 60);

		list.signForm(&carl);
		list.signForm(&carl);
		std::cout << &list;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	//---------------------------------

	std::cout << BOLD_YELLOW << "\n--- " << "Form grade boundary checks" << " ---" << RESET << std::endl;
	try
	{
		Form invalidHigh("InvalidHigh", 0, 10);
		std::cout << &invalidHigh;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "InvalidHigh -> " << e.what() << RESET << std::endl;
	}
	try
	{
		Form invalidLow("InvalidLow", 151, 200);
		std::cout << &invalidLow;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "InvalidLow -> " << e.what() << RESET << std::endl;
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
		std::cout << RED << "TooHigh -> " << e.what() << RESET << std::endl;
	}
	try
	{
		Bureaucrat tooLow("TooLow", 200);
		std::cout << &tooLow;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "TooLow -> " << e.what() << RESET << std::endl;
	}

	//---------------------------------

	std::cout << BOLD_YELLOW << "\n--- " << "Copy constructor" << " ---" << RESET << std::endl;
	try
	{
		Form base("IdentityCard", 45, 12);
		Form copy(base);
		std::cout << &base;
		std::cout << &copy;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}
