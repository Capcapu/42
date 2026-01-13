/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:59:09 by csolari           #+#    #+#             */
/*   Updated: 2025/10/28 14:40:05 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main( void )
{
	ClapTrap	bob("bob");
	ScavTrap	ros("ros");

	bob.attack("jim");
	bob.takeDamage(5);
	bob.beRepaired(3);
	bob.takeDamage(5);
	bob.takeDamage(5);
	ros.attack("jim");
	ros.takeDamage(5);
	ros.guardGate();
	ros.beRepaired(3);
	ros.takeDamage(5);
	ros.guardGate();
	ros.guardGate();
	ros.takeDamage(5);

	return(0);
}
