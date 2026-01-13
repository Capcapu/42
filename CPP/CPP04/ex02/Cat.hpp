/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:48:09 by csolari           #+#    #+#             */
/*   Updated: 2025/10/29 17:33:46 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"

#ifndef CAT_HPP
#define CAT_HPP


class Cat : public Animal
{

	private : 
		std::string	_type;
		Brain	*_brain;
		
	public:
		Cat( void );
		Cat(const Cat& copy);
		Cat &operator=(const Cat& other);
		~Cat( void );
		void	makeSound(void) const;
		std::string	getType(void) const;
		void	setIdeas(size_t i, std::string idea);
		std::string	getIdeas(size_t i);
};

#endif