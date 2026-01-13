/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:48:09 by csolari           #+#    #+#             */
/*   Updated: 2025/10/29 16:01:41 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#ifndef CAT_HPP
#define CAT_HPP


class Cat : public Animal
{

	private : 
		std::string	_type;
	
	public:

	Cat( void );
	Cat(const Cat& copy);
	Cat &operator=(const Cat& other);
	~Cat( void );
	void	makeSound(void) const;
	std::string	getType(void) const;
};

#endif