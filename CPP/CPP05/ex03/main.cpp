/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:02:53 by csolari           #+#    #+#             */
/*   Updated: 2026/01/26 14:28:45 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "Colors.hpp"

int	main()
{
	Intern		intern;
	Bureaucrat	boss("Boss", 1);
	Bureaucrat	mid("Mid", 100);

	std::cout << BOLD_YELLOW << "\n========== TEST 1: Robotomy via Intern ==========" << RESET << std::endl;
	try
	{
		AForm *robot = intern.makeForm("RoBoToMy Request", "Bender");
		if (robot)
		{
			robot->signForm(&boss);
			boss.executeForm(*robot);
			boss.executeForm(*robot);
			mid.executeForm(*robot);
			delete robot;
		}
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << BOLD_YELLOW << "\n========== TEST 2: Shrubbery via Intern ==========" << RESET << std::endl;
	try
	{
		AForm *shrub = intern.makeForm("shrubbery creation form", "home");
		if (shrub)
		{
			shrub->signForm(&mid);
			mid.executeForm(*shrub);
			delete shrub;
		}
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << BOLD_YELLOW << "\n========== TEST 3: Presidential via Intern ==========" << RESET << std::endl;
	try
	{
		AForm *pardon = intern.makeForm("PRESIDENTIAL PARDON", "Arthur");
		if (pardon)
		{
			pardon->signForm(&boss);
			boss.executeForm(*pardon);
			delete pardon;
		}
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << BOLD_YELLOW << "\n========== TEST 4: Invalid form name ==========" << RESET << std::endl;
	AForm *unknown = intern.makeForm("coffee break", "Nobody");
	if (unknown)
	{
		std::cout << RED << "Unexpected form created for invalid name" << RESET << std::endl;
		delete unknown;
	}

	std::cout << BOLD_YELLOW << "\n========== Done ==========" << RESET << std::endl;
	return (0);
}
