/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:19:17 by csolari           #+#    #+#             */
/*   Updated: 2026/01/23 14:25:01 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm;

class ShrubberyCreationForm : public AForm
{
	private:
		std::string const	_target;
		ShrubberyCreationForm(void);

	public :
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &cpy);

		~ShrubberyCreationForm(void);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

		std::string			getTarget(void) const;
		void				execute(Bureaucrat const &executor) const;
	
};

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm *a);

#endif