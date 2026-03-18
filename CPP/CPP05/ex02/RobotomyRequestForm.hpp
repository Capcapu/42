/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:19:11 by csolari           #+#    #+#             */
/*   Updated: 2026/01/23 14:24:30 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm;

class RobotomyRequestForm : public AForm
{
	private :
		std::string	_target;
		RobotomyRequestForm(void);

	public :
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &cpy);

		~RobotomyRequestForm(void);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

		std::string	getTarget(void) const;

		void	execute(Bureaucrat const &executor) const;

};

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm *a);

#endif