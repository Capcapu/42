/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:32:59 by csolari           #+#    #+#             */
/*   Updated: 2025/11/12 14:32:59 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Colors.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << ORANGE << "Bureaucrat default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : _name("default")
{
	std::cout << ORANGE << "Bureaucrat constructor 1 called" << RESET << std::endl;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	std::cout << ORANGE << "Bureaucrat constructor 2 called" << RESET << std::endl;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(std::string name) : _name(name)
{
	std::cout << ORANGE << "Bureaucrat constructor 3 called" << RESET << std::endl;
	_grade = 150;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << ORANGE << "Bureaucrat copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName() + "_copy")
{
	std::cout << ORANGE << "Bureaucrat copy constructor called" << RESET << std::endl;
	*this = copy;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << ORANGE << "Bureaucrat destructor called" << RESET << std::endl;
}

std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade = grade;
}

int	Bureaucrat::getGrade(void) const
{
	return(_grade);
}

void	Bureaucrat::incraseGrade(void)
{
	if (_grade > 1)
		_grade--;
	else
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decreaseGrade(void)
{
	if (_grade < 150)
		_grade++;
	else
		throw Bureaucrat::GradeTooLowException() ;
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low!");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high!");
};

void	Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << PINK <<_name << " executed " << form.getName() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED << _name << " couldn't execute " << form.getName() 
			<< " because: " << e.what() << RESET << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a)
{
	o << PINK << a->getName() << ", bureaucrat grade " << a->getGrade() << "." << RESET << std::endl;
	return(o);
}


