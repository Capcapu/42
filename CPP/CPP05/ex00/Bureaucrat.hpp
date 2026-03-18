/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:32:59 by csolari           #+#    #+#             */
/*   Updated: 2025/11/12 14:32:59 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
	private:
		std::string	const		_name;
		int						_grade;
		Bureaucrat();
		
	public:
		Bureaucrat(const std::string name = "default");
		Bureaucrat(int grade);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& copy);

		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& other);

		void		setGrade(int grade);
		std::string	getName(void) const;
		int			getGrade(void) const;
		
		void		incraseGrade(void);
		void		decreaseGrade(void);

		class GradeTooHighException: public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
		
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a);

#endif
