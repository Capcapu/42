/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:18:37 by csolari           #+#    #+#             */
/*   Updated: 2026/01/22 18:04:28 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
	private :
		std::string const	_name;
		int const			_signGrade;
		int const			_executeGrade;
		bool				_isSigned;
		Form(void);

	public :
		Form(std::string const name = "default");
		Form(int signGrade, int executeGrade);
		Form(std::string const name, int signGrade, int executeGrade);
		Form(const Form &cpy);

		Form &operator=(const Form &src);
		~Form();

		std::string		getName() const;
		bool			getIsSigned() const;
		std::string		getIsSignedString() const;
		int				getSignGrade() const;
		int				getExecuteGrade() const;

		class GradeTooHighException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};

		bool			beSigned(Bureaucrat *b);
		void			signForm(Bureaucrat *b);
};

std::ostream	&operator<<(std::ostream &os, Form *a);

#endif