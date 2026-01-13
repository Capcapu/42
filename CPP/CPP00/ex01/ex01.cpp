/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:31:13 by csolari           #+#    #+#             */
/*   Updated: 2025/10/20 19:31:39 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>

int	main()
{
	PhoneBook	PhoneBook;
	std::string	buff;

	while (1)
	{
		if(!getline(std::cin, buff))
			return(1);
		if (buff == "EXIT") 
			return(0);
		else if (buff == "ADD")
		{
			PhoneBook.AddContact();
		}
		else if (buff == "SEARCH")
		{
			PhoneBook.Search();
		}
		else if (buff == "EXIT")
		{
			exit(1);
		}
	}
	return (0);
}
