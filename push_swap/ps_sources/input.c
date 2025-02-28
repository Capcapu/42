/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:21:03 by csolari           #+#    #+#             */
/*   Updated: 2025/02/21 16:01:23 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_int(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (ft_strncmp(argv[i], "", 1) == 0)
			return (ft_printf("Error\n"), 0);
		while (argv[i][j] && argv[i])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9')
				&& !(argv[i][j] == '-') && !(argv[i][j] == '+'))
				return (ft_printf("Error\n"), 0);
			j++;
		}
		if (ft_atol(argv[i]) < -2147483648 || ft_atol(argv[i]) > 2147483647)
			return (ft_printf("Error\n"), 0);
		i++;
	}
	return (1);
}

static int	ft_check_doublons(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
				return (ft_printf("Error\n"), 0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_input(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (ft_check_int(argc, argv) == 0)
		return (0);
	if (ft_check_doublons(argc, argv) == 0)
		return (0);
	return (1);
}
