/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:59:05 by csolari           #+#    #+#             */
/*   Updated: 2025/10/23 16:09:27 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "Zombie.h"

int	main(void)
{
	Zombie *heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	
	randomChump("StackZombie");
	
	delete heapZombie;
	
	return(0);
}
