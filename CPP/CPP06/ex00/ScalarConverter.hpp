/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:08:06 by csolari           #+#    #+#             */
/*   Updated: 2026/02/03 13:47:09 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cerrno>
#include <cstdlib>

class ScalarConverter 
{
	private :
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &cpy);
		ScalarConverter const operator=(ScalarConverter const &src);
		~ScalarConverter(void);

	public :

		static void	convert(std::string &str);

};


#endif