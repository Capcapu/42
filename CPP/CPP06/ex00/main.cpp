/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 10:11:22 by csolari           #+#    #+#             */
/*   Updated: 2026/02/05 10:51:32 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Invalid number of arguments : one is required." << std::endl;
			return (1);
	}

	std::string str = argv[1];
	ScalarConverter::convert(str);

	return (0);
}