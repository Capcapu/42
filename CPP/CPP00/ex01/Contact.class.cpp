/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:49:29 by csolari           #+#    #+#             */
/*   Updated: 2025/10/21 14:14:23 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.class.hpp"

Contact::Contact(void)
{
	// std::cout << "constructeur Contact" <<std::endl;
	return;
}

Contact::~Contact(void)
{
	// std::cout << "destructeur Contact" <<std::endl;
	return;
}

std::string	Contact::getFirstName(void)const
{
	return(_FirstName);
}

std::string	Contact::getLastName(void)const
{
	return(_LastName);
}

std::string	Contact::getNickName(void)const
{
	return(_NickName);
}

std::string	Contact::getPhoneNumber(void)const
{
	return(_PhoneNumber);
}

std::string	Contact::getDarkestSecret(void)const
{
	return(_DarkestSecret);
}

void	Contact::setFirstName(std::string FirstName)
{
	_FirstName = FirstName;
}

void	Contact::setLastName(std::string LastName)
{
	_LastName = LastName;
}

void	Contact::setNickName(std::string NickName)
{
	_NickName = NickName;
}

void	Contact::setPhoneNumber(std::string PhoneNumber)
{
	_PhoneNumber = PhoneNumber;
}

void	Contact::setDarkestSecret(std::string DarkestSecret)
{
	_DarkestSecret = DarkestSecret ;
}

bool	Contact::isEmpty(void)const
{
	return (_FirstName.empty());
}
