/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:59:23 by csolari           #+#    #+#             */
/*   Updated: 2025/10/23 16:05:45 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie	*newZombie = new Zombie();

	newZombie->setName(name);
	return(newZombie);
}
