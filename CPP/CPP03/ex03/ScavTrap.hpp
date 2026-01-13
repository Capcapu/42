/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:58:51 by csolari           #+#    #+#             */
/*   Updated: 2025/10/29 12:31:26 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H
#include <iostream>
#include <stdlib.h>
#include "ClapTrap.hpp"

class	ScavTrap : public virtual ClapTrap
{
	protected :

		int	_gateKeeper;

	public :

		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &copy);
		ScavTrap	&operator=(const ScavTrap& other);
		~ScavTrap(void);
		void	guardGate(void);
		void	attack(const std::string& target);


} ;

#endif
