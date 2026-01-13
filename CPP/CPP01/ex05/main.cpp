/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:19:14 by csolari           #+#    #+#             */
/*   Updated: 2025/10/23 19:45:21 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

int main (void)
{
	Harl harl;

	std::cout << std::endl << "DEBUG Level" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl << "INFO Level" << std::endl;;
	harl.complain("INFO");
	std::cout << std::endl << "WARNING Level" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl << "ERROR Level" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl << "No valid Level" << std::endl;
	harl.complain("ALARM");
	return (0);
}
