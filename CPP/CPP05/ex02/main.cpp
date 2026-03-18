/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:02:53 by csolari           #+#    #+#             */
/*   Updated: 2026/01/26 11:42:18 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Colors.hpp"

int	main()
{
	std::cout << BOLD_YELLOW << "\n========== TEST 1: ShrubberyCreationForm ==========" << RESET << std::endl;
	std::cout << BOLD_YELLOW << "Required grades: sign 145, exec 137" << RESET << std::endl;
	try
	{
		ShrubberyCreationForm	shrub("home");
		Bureaucrat				lowGrade("LowGuy", 150);
		Bureaucrat				midGrade("MidGuy", 140);
		Bureaucrat				highGrade("HighGuy", 130);

		std::cout << "\n--- Attempt execution without signature ---" << std::endl;
		highGrade.executeForm(shrub);
		
		// std::cout << "\n--- Signature attempt by low grade bureaucrat ---" << std::endl;
		// shrub.signForm(&lowGrade);

		std::cout << "\n--- Signature by adequate grade bureaucrat ---" << std::endl;
		shrub.signForm(&midGrade);
		
		std::cout << "\n--- Execution by high grade bureaucrat ---" << std::endl;
		highGrade.executeForm(shrub);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << BOLD_YELLOW << "\n========== TEST 2: RobotomyRequestForm ==========" << RESET << std::endl;
	std::cout << BOLD_YELLOW << "Required grades: sign 72, exec 45" << RESET << std::endl;
	try
	{
		RobotomyRequestForm	robot("Bender");
		Bureaucrat			lowGrade("Intern", 80);
		Bureaucrat			highGrade("Manager", 40);

		// std::cout << "\n--- Signature attempt by low grade ---" << std::endl;
		// robot.signForm(&lowGrade);

		std::cout << "\n--- Signature by high grade ---" << std::endl;
		robot.signForm(&highGrade);

		std::cout << "\n--- Execution attempt by low grade ---" << std::endl;
		lowGrade.executeForm(robot);

		std::cout << "\n--- Multiple executions by high grade (50% success rate) ---" << std::endl;
		highGrade.executeForm(robot);
		highGrade.executeForm(robot);
		highGrade.executeForm(robot);
		highGrade.executeForm(robot);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << BOLD_YELLOW << "\n========== TEST 3: PresidentialPardonForm ==========" << RESET << std::endl;
	std::cout << BOLD_YELLOW << "Required grades: sign 25, exec 5" << RESET << std::endl;
	try
	{
		PresidentialPardonForm	pardon("Arthur");
		Bureaucrat				midGrade("Deputy", 20);
		Bureaucrat				veryHigh("President", 1);

		std::cout << "\n--- Signature by mid-high grade ---" << std::endl;
		pardon.signForm(&midGrade);

		std::cout << "\n--- Execution attempt by mid-high grade (should fail) ---" << std::endl;
		midGrade.executeForm(pardon);

		std::cout << "\n--- Execution by very high grade ---" << std::endl;
		veryHigh.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << BOLD_YELLOW << "\n========== TEST 4: Multiple forms with same bureaucrat ==========" << RESET << std::endl;
	try
	{
		Bureaucrat				boss("TheBoss", 1);
		ShrubberyCreationForm	garden("garden");
		RobotomyRequestForm		robot("R2D2");
		PresidentialPardonForm	pardon("Prefect");

		std::cout << "\n--- Boss signs all forms ---" << std::endl;
		garden.signForm(&boss);
		robot.signForm(&boss);
		pardon.signForm(&boss);

		std::cout << "\n--- Boss executes all forms ---" << std::endl;
		boss.executeForm(garden);
		boss.executeForm(robot);
		boss.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << BOLD_YELLOW << "\n========== All tests completed ==========" << RESET << std::endl;
	return (0);
}
