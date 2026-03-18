/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:19:14 by csolari           #+#    #+#             */
/*   Updated: 2026/01/26 11:38:44 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include "Colors.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
	std::cout << ORANGE << "Default Shrubbery Creation Form constructor, won't be called" << RESET << std::endl;

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << ORANGE << "Shrubbery Creation Form constructor 1 called" << RESET << std::endl;

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &cpy) : AForm("ShrubberyCreationForm", 145, 137), _target(cpy.getTarget())
{
	std::cout << ORANGE << "Shrubbery Creation Form copy constructor called" << RESET << std::endl;
	*this = cpy;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << ORANGE << "Shrubbery Creation Form destructor called" << RESET << std::endl;

}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	std::cout << ORANGE << "Shrubbery Creation Form Assignation operator called" << RESET << std::endl;
	if (this == &src)
		return *this;
	// que des constantes, rien a assigner
	return *this;
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecuteGrade())
		throw Bureaucrat::GradeTooLowException();
	else if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	else
	{
		std::string filename = this->getTarget() + "_shrubbery";
		std::ofstream outfile(filename.c_str());
		if (!outfile.is_open())
		{
			std::cerr << "Failed to create file: " << filename << std::endl;
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			outfile <<
			"ii  i  i i  i   ii" << std::endl <<
			" i  ii  i    i ii ii" << std::endl <<
			"  iii   ii   iii ii" << std::endl <<
			"   iii  ii  iiiiii" << std::endl <<
			" ii iii iii iii   ii" << std::endl <<
			"   iiiiiiiiiiii ii" << std::endl <<
			"       iiiiiiiii" << std::endl <<
			"    i  ii"<< i << "ii" << std::endl <<
			"     i ii"<< i << "ii i" << std::endl <<
			"      iii"<< i << "iii" << std::endl <<
			"       ii"<< i << "ii" << std::endl <<
			"       ii"<< i << "ii" << std::endl <<
			"       ii"<< i << "ii" << std::endl <<
			std::endl;
		}
		outfile.close();
	}
}


std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm *a)
{
	o << "Shrubbery Creatin Form " << a->getName() << ", which target is " << a->getTarget() << ", has :\nSign grade :" << a->getSignGrade() << "\nExecute grade :" << a->getExecuteGrade() << "\nIs signed : " << a->getIsSignedString() << std::endl;
	return(o);
}
