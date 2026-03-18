/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:19:05 by csolari           #+#    #+#             */
/*   Updated: 2026/01/23 12:32:55 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Breaucrat;
class AForm;

class PresidentialPardonForm : public AForm
{
	private :
		const std::string	_target;
		PresidentialPardonForm(void);

	public :
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm &cpy);

		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

		std::string getTarget(void) const;
		
		void	execute(Bureaucrat const &executor) const;

};

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm *a);

#endif