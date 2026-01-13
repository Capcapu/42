/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:59:35 by csolari           #+#    #+#             */
/*   Updated: 2025/10/22 17:50:08 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include "Zombie.hpp"

void randomChump( std::string name )
{
	Zombie	newZombie;

	newZombie.setName(name);
	newZombie.announce();
}
