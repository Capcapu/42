/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:59:05 by csolari           #+#    #+#             */
/*   Updated: 2025/10/24 15:46:10 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "Zombie.h"

int	main(void)
{
	Zombie *horde = zombieHorde(5, "grrr");

	for (int i = 0; i < 5; i++)
	{
		horde[i].announce();
	}

	delete[] horde;
	return(0);
}
