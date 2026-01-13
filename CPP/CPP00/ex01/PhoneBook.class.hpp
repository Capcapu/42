/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:44:19 by csolari           #+#    #+#             */
/*   Updated: 2025/10/20 18:52:00 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H
#include "Contact.class.hpp"

class PhoneBook {

	private :
	Contact	_contacts[8];

	public :
	PhoneBook( void );
	~PhoneBook( void );

	void	AddContact();
	void	Search();
	Contact	getContact(int number)const;
};

#endif