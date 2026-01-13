/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:00:56 by csolari           #+#    #+#             */
/*   Updated: 2025/06/17 14:20:09 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (!(str[i] == '+' || str[i] == '-' || str[i] == ' ' || (str[i] >= 9
					&& str[i] <= 13)))
			break ;
		i++;
	}
	while (str && str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

int	check_positive(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < 5)
	{
		if (ft_atoi(argv[i]) <= 0)
			return (ft_putstr_fd("The mandatory arguments must be positive\n",
					2), 0);
		i++;
	}
	if (argc == 6 && ft_atoi(argv[5]) < 0)
		return (ft_putstr_fd("Optional argument must be positive or null\n", 2),
			0);
	return (1);
}

int	check_arguments(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc > 6 || argc < 5)
		return (ft_putstr_fd("Invalid number of arguments\n", 2), 0);
	while (i < argc)
	{
		if (!is_numeric(argv[i]))
			return (ft_putstr_fd("All arguments must be numeric\n", 2), 0);
		i++;
	}
	if (check_positive(argc, argv) == 0)
		return (0);
	if (ft_atoi(argv[1]) > 200)
		return (ft_putstr_fd("The number of philosopher is limited to 200\n",
				2), 0);
	return (1);
}
