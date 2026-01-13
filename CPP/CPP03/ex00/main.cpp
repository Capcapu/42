/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:49:36 by csolari           #+#    #+#             */
/*   Updated: 2025/10/27 19:49:18 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main( void )
{
	ClapTrap	bob("bob");

	bob.attack("jim");
	bob.takeDamage(5);
	bob.beRepaired(3);
	bob.takeDamage(5);
	bob.takeDamage(5);
	return(0);
}
