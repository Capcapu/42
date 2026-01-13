/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:19:32 by csolari           #+#    #+#             */
/*   Updated: 2025/10/22 15:50:45 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int capitalize(char *str)
{
	int i = 0;

	while (str && str[i])
	{
		if (str[i] >= 97 && str[i] <= 122)
			std::cout << static_cast<char>(str[i] - 32);
		else 
			std::cout << str[i];
		i++;
	}
	return(0);
}

int	main(int argc, char **argv)
{
	int i = 0;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return(0);
	}
	while (i < argc)
	{
		capitalize(argv[i + 1]);
		i++;
	}
	std::cout << std::endl;
	return 0;
}