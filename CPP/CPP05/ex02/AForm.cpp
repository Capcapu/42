/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:18:30 by csolari           #+#    #+#             */
/*   Updated: 2026/01/22 18:16:38 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Colors.hpp"

AForm::AForm() : _name("default"), _signGrade(150), _executeGrade(150), _isSigned(false)
{
	std::cout << ORANGE << "Form default constructor, not supposed to be called" << RESET << std::endl;
}

AForm::AForm(std::string const name) : _name(name), _signGrade(150), _executeGrade(150), _isSigned(false) 
{
	std::cout << ORANGE << "Form constructor 1 called" << RESET << std::endl;
} 

AForm::AForm(int signGrade, int executeGrade) : _name("default"), _signGrade(signGrade), _executeGrade(executeGrade), _isSigned(false)
{
	std::cout << ORANGE <<"Form constructor 2 called" << RESET << std::endl;

	const int sign = this->getSignGrade();
	const int exec = this->getExecuteGrade();
	if (sign > 150 || exec > 150)
		throw GradeTooLowException();
	else if (sign < 1 || exec < 1)
		throw GradeTooHighException();
}

AForm::AForm(std::string const name, int signGrade, int executeGrade) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade), _isSigned(false)
{
	std::cout << ORANGE <<"Form constructor 3 called" << RESET << std::endl;

	const int sign = this->getSignGrade();
	const int exec = this->getExecuteGrade();
	if (sign > 150 || exec > 150)
		throw GradeTooLowException();
	else if (sign < 1 || exec < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm &cpy) : _name(cpy.getName()+ "_copy"), _signGrade(cpy.getSignGrade()), _executeGrade(cpy.getExecuteGrade()), _isSigned(false)
{
	std::cout << ORANGE << "Form copy constructor called" << RESET << std::endl;
}


AForm &AForm::operator=(const AForm &src)
{
	std::cout << ORANGE << "Form copy assignment operator called" << RESET << std::endl;
	if(this == &src)
		return(*this);
	//rien a assigner dans cette classe
	return(*this);
}

AForm::~AForm()
{
	std::cout << ORANGE << "Form destructor called" << RESET<< std::endl;
}

std::string	AForm::getName() const
{
	return (_name);
}

bool	AForm::getIsSigned() const
{
	return(_isSigned);
}

std::string	AForm::getIsSignedString() const
{
	if (_isSigned)
		return("True");
	else
		return("False");
}

int		AForm::getSignGrade() const
{
	return(_signGrade);
}

int		AForm::getExecuteGrade() const
{
	return(_executeGrade);
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Form grade is too low!");
};

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Form grade is too high!");
};

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form needs to be signed before execution!");
};


std::ostream	&operator<<(std::ostream &os, AForm *a)
{
	os << "Form " << a->getName() << ", needs a grade " << a->getSignGrade() << " to be signed, and a grade " << a->getExecuteGrade() << " to be excecuted. The signed state of the Aform is : " << LIGHT_BLUE << a->getIsSignedString() << RESET << std::endl;
	return(os);
}


// -----------------------------------------------------

bool	AForm::beSigned(Bureaucrat *b)
{
	if(b->getGrade() <= this->getSignGrade())
	{
		this->_isSigned = true;
		return (true);
	}
	else
		throw GradeTooLowException();
	return (false);
}

void	AForm::signForm(Bureaucrat *b)
{
	if (this->_isSigned)
	{
		std::cout << PINK << b->getName() << " couldn't sign " << this->getName() << " because it was already signed" << RESET << std::endl;
		return ;
	}
	bool state = this->beSigned(b);
	if (state)
		std::cout << PINK << b->getName() << " signed " << this->getName() << RESET << std::endl;
	else 
		std::cout << PINK << b->getName() << " couldn't sign " << this->getName() << " because his grade was too low" << RESET << std::endl;
}

