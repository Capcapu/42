/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:33:44 by csolari           #+#    #+#             */
/*   Updated: 2026/02/03 15:51:05 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
#include <string>

class Data
{
	private :
		std::string	_content;
	
	public :
	
		Data(void);
		Data(Data &cpy);
		~Data(void);
		Data & operator=(Data const &src);

		std::string	getContent(void) const;
};


#endif