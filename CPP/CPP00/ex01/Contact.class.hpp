/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:44:36 by csolari           #+#    #+#             */
/*   Updated: 2025/10/20 16:22:34 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H
#include <iostream>

class Contact {
	private :

	std::string	_FirstName;
	std::string	_LastName;
	std::string	_NickName;
	std::string	_PhoneNumber;
	std::string	_DarkestSecret;

	public :

		Contact( void );
		~Contact( void );
		std::string	getFirstName(void)const;
		std::string	getLastName(void)const;
		std::string	getNickName(void)const;
		std::string	getPhoneNumber(void)const;
		std::string	getDarkestSecret(void)const;
		void	setFirstName(std::string FirstName);
		void	setLastName(std::string LastName);
		void	setNickName(std::string NickName);
		void	setPhoneNumber(std::string PhoneNumber);
		void	setDarkestSecret(std::string DarkestSecret);
		bool	isEmpty(void)const;

};


#endif