/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:39:05 by csolari           #+#    #+#             */
/*   Updated: 2025/10/29 18:13:38 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <stdlib.h>

class Animal {

	protected:
	
	std::string	_type;

	public:

	Animal( void ) ;
	Animal(const Animal& copy);
	Animal(std::string type);
	Animal &operator=(const Animal& other);
	virtual ~Animal( void );
	virtual void	makeSound(void)const;
	std::string	getType(void) const;

};

#endif
