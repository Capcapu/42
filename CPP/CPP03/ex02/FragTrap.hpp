/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:44:43 by csolari           #+#    #+#             */
/*   Updated: 2025/10/28 15:01:32 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H
#include <iostream>
#include <stdlib.h>
#include "ClapTrap.hpp"

class	FragTrap : public ClapTrap{

	public :

		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap &copy);
		FragTrap	&operator=(const FragTrap& other);
		~FragTrap(void);
		void	highFivesGuys(void);

} ;

#endif