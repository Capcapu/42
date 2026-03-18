/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:38:05 by csolari           #+#    #+#             */
/*   Updated: 2026/02/03 16:14:02 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>
#include "Data.hpp"

class Data;

class Serializer
{
	private :
	
		Serializer(void);
		Serializer(Serializer &cpy);
		~Serializer(void);
		Serializer const operator=(Serializer const &src);

	public :

		static uintptr_t	serialize(Data* ptr);
		static Data* 		deserialize(uintptr_t raw);
	
};


#endif