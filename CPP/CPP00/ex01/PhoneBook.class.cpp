/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:49:45 by csolari           #+#    #+#             */
/*   Updated: 2025/10/22 15:50:44 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) {
	// std::cout << "constructeur PhoneBook" <<std::endl;
}

PhoneBook::~PhoneBook(void) {
	// std::cout << "destructeur PhoneBook" <<std::endl;
	return;
}

Contact	PhoneBook::getContact(int number)const
{
	return(_contacts[number]);
}

int	is_whitespace(std::string buff)
{
	unsigned long	i;

	i = 0;
	while (i < buff.length())
	{
		if (!isspace(buff[i])) // a revoir avec tous les white spaces maybe!
			return (0);
		i++;
	}
	return (1);
}

std::string	check_info(void)
{
	std::string		buff;


	if (!getline(std::cin, buff))
		exit(1);
	while(buff == "")
	{
		std::cout << "Field musn't be empty, please enter again :" ;
		if (!getline(std::cin, buff))
			exit(1);
		else if (is_whitespace(buff))
			buff = "";
	}
	return buff;
}

void	PhoneBook::AddContact(void)
{
	std::string		line;
	static int		count_contact = 0;
	
	std::cout << "Enter your firstname :";
	line = check_info();
	_contacts[count_contact % 8].setFirstName(line);

	std::cout << "Enter your lastname :";
	line = check_info();
	_contacts[count_contact % 8].setLastName(line);

	std::cout << "Enter your nickname :";
	line = check_info();
	_contacts[count_contact % 8].setNickName(line);

	std::cout << "Enter your phone number :";
	line = check_info();
	_contacts[count_contact % 8].setPhoneNumber(line);

	std::cout << "Enter your darkest secret :";
	line = check_info();
	_contacts[count_contact % 8].setDarkestSecret(line);
	
	std::cout <<std::endl;
	count_contact++;
}

void	print_info(std::string line)
{
	unsigned long	i;
	unsigned long 	length;

	i = 0;
	length = line.length();
	if (length <= 10)
	{
		while(i++ < 10 - length)
			std::cout << " ";
		std::cout << line;
	}
	else if (length > 10)
	{
		while (i < 9)
		{
			std::cout << line[i];
			i++;
		}
		std::cout << ".";
	}
	std::cout << "|";
}

void	print_contact_list(Contact contact, int number)
{
	std::string	line;

	std::cout << "         " << number + 1 << "|";
	line = contact.getFirstName();
	print_info(line);
	line = contact.getLastName();
	print_info(line);
	line = contact.getNickName();
	print_info(line);
	std::cout << std::endl;
}

void	print_contact_info(Contact contact)
{
	std::cout << "First name : " << contact.getFirstName() << std::endl;
	std::cout << "Last name : " << contact.getLastName() << std::endl;
	std::cout << "Nick name : " << contact.getNickName() << std::endl;
	std::cout << "Phone number : " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret : " << contact.getDarkestSecret() << std::endl;
	std::cout << std::endl;
}

void	PhoneBook::Search(void)
{
	int	i;
	Contact	contact;
	std::string	num;
	int			num_atoi;
	int			condition;

	i = 0;
	std::cout << "Index     |First name|Last name |Phone num.|" << std::endl;
	while(i < 8)
	{
		contact = PhoneBook::getContact(i);
		if (contact.isEmpty())
			break;
		print_contact_list(contact, i);
		i++;
	}
	num_atoi = 0;
	condition = 0;
	i = 0;
	while (!condition && i++ < 3)
	{
		std::cout << std::endl << "Enter the index of the contact you want to see :" ;
		num = check_info();
		num_atoi = atoi(num.c_str());
		if (num_atoi < 1 || num_atoi > 8)
		{
			std::cout << "Invalid index. Please enter a number between 1 and 8." << std::endl;
			condition = 0;
		}
		else
		{
			contact = PhoneBook::getContact(num_atoi - 1);
			if (contact.isEmpty())
			{
				std::cout << "No contact found at this index." << std::endl;
				condition = 0;
			}
			else
				condition = 1;
		}
	}
	if (condition == 1)
		print_contact_info(contact);
}
