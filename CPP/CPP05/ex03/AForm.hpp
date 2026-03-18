/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:18:37 by csolari           #+#    #+#             */
/*   Updated: 2026/01/26 14:17:00 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
	private :
		AForm(void);

	protected :
		std::string const	_name;
		int const			_signGrade;
		int const			_executeGrade;
		bool				_isSigned;
		AForm(std::string const name = "default");
		AForm(int signGrade, int executeGrade);
		AForm(std::string const name, int signGrade, int executeGrade);

	public :
		AForm(const AForm &cpy);

		AForm &operator=(const AForm &src);
		virtual ~AForm();

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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		bool			beSigned(Bureaucrat *b);
		void			signForm(Bureaucrat *b);
		virtual void 	execute(Bureaucrat const & executor) const = 0;
};

std::ostream	&operator<<(std::ostream &os, AForm *a);

#endif