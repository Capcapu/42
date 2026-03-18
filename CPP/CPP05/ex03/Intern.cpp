/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 11:47:31 by csolari           #+#    #+#             */
/*   Updated: 2026/01/26 14:12:59 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Colors.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void)
{
	std::cout << ORANGE << "Intern default constructor called" << RESET << std::endl; 
}

Intern::Intern(Intern &cpy)
{
	std::cout << ORANGE << "Intern copy constructor called" << RESET << std::endl; 
	*this = cpy;
}

Intern::~Intern(void)
{
	std::cout << ORANGE << "Intern destructor called" << RESET << std::endl; 

}

Intern	Intern::operator=(Intern const &src)
{
	std::cout << ORANGE << "Intern copy assignment operator called" << RESET << std::endl; 
	if (this == &src)
		return *this;
	//rien a assigner dans cette class, que des constantes
	return *this;
}

static AForm *makePresident(const std::string target)
{
	return(new PresidentialPardonForm(target));
}

static AForm *makeRobotomy(const std::string target)
{
	return(new RobotomyRequestForm(target));
}

static AForm *makeShrubbery(const std::string target)
{
	return(new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm(const std::string formName, const std::string formTarget)
{
	AForm *(*all_forms[])(const std::string target) = {&makePresident, &makeRobotomy, &makeShrubbery};
	std::string form[] = {"presidentialpardon", "presidentialpardonform", "presidential pardon", "presidential pardon form",
	"robotomyrequest", "robotomyrequestform", "robotomy request", "robotomy request form",
	"shrubberycreation", "shrubberycreationform", "shrubbery creation", "shrubbery creation form"};

	std::string cpyName = formName;
	std::string lower = "";
	for (size_t i = 0; i < cpyName.length(); i++)
	{
		lower += std::tolower(cpyName[i]);
	}

	for (int i = 0; i < 12; i++)
	{
		if (lower == form[i])
		{
			std::cout << CYAN << "Intern creates " << formName << RESET << std::endl;
			return(all_forms[i / 4](formTarget));
		}
	}
	std::cout << CYAN << "Intern couldn't create the form named " << formName << std::endl;
	return(NULL);
}
