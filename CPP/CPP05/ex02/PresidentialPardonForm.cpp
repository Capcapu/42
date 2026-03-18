/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:18:58 by csolari           #+#    #+#             */
/*   Updated: 2026/01/26 11:37:26 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Colors.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), _target("Default")
{
	std::cout << ORANGE << "Default Presidential Pardon Form constructor, won't be called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << ORANGE << "Presidential Pardon Form constructor 1 called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &cpy) : AForm("PresidentialPArdonForm", 25, 5), _target(cpy.getTarget())
{
	std::cout << ORANGE << "Presidential Pardon Form copy constructor called" << RESET << std::endl;
	*this = cpy;
}

PresidentialPardonForm::~PresidentialPardonForm(void) 
{
	std::cout << ORANGE << "Presidential Pardon Form destructor called" << RESET << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	std::cout << ORANGE << "Presidential Pardon Form Assignation operator called" << RESET << std::endl;
	if (this == &src)
		return *this;
	//rien a assigner dans cette class, que des constantes
	return *this;
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecuteGrade())
		throw Bureaucrat::GradeTooLowException();
	else if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	else
		std::cout << BLUE << _target << " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;
}

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm *a)
{
	o << "Persidential Pardon Form " << a->getName() << ", which target is " << a->getTarget() << ", has :\nSign grade :" << a->getSignGrade() << "\nExecute grade :" << a->getExecuteGrade() << "\nIs signed : " << a->getIsSignedString() << std::endl;
	return(o);
}