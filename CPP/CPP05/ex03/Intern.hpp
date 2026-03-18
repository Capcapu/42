/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 11:47:37 by csolari           #+#    #+#             */
/*   Updated: 2026/01/26 12:14:10 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Intern
{
	public :
		
		Intern(void);
		Intern(Intern &cpy);
		~Intern(void);
		Intern	operator=(Intern const &src);

		AForm	*makeForm(const std::string formName, const std::string formTarget);

};


#endif