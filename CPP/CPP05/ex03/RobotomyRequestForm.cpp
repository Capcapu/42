/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:19:08 by csolari           #+#    #+#             */
/*   Updated: 2026/01/26 11:34:37 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Colors.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << ORANGE << "Default Robotomy Request Form constructor, won't be called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << ORANGE << "Robotomy Request Form constructor 1 called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &cpy) : AForm("RobotomyRequestForm", 72, 45), _target(cpy.getTarget())
{
	std::cout << ORANGE << "Robotomy Request Form copy constructor called" << RESET << std::endl;
	*this = cpy;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << ORANGE << "Robotomy Request Form destructor called" << RESET << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	std::cout << ORANGE << "Robotomy Request Form Assignation operator called" << RESET << std::endl;
	if (this == &src)
		return *this;
	// que des constantes, rien a assigner
	return *this;
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (_target);
}

static int robotFail = 0;

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecuteGrade())
		throw Bureaucrat::GradeTooLowException();
	else if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	else if (robotFail++ % 2)
		std::cout << LIGHT_BLUE << "BGRRRRBRGRBRBGRRBRRRRRRR " << _target << " was robotomize" << RESET << std::endl;
	else
		std::cout << LIGHT_BLUE << "Robotomy failed" << RESET << std::endl;
}

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm *a)
{
	o << "Robotomy Request Form " << a->getName() << ", which target is " << a->getTarget() << ", has :\nSign grade :" << a->getSignGrade() << "\nExecute grade :" << a->getExecuteGrade() << "\nIs signed : " << a->getIsSignedString() << std::endl;
	return(o);
}
