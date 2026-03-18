/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 10:48:02 by csolari           #+#    #+#             */
/*   Updated: 2026/03/13 21:04:08 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "Colors.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << RED << "Error: could not open file." << RESET << std::endl;
		return 1;
	}
	BitcoinExchange	btc("data.csv");
	try 
	{
		btc.loadingData();
	}
	catch (const BitcoinExchange::OpenCsvException &e)
	{
		std::cerr << PINK << e.what() << RESET << std::endl;
		return 1;	
	}
	btc.processInput(argv[1], btc);
	return 0;
}
