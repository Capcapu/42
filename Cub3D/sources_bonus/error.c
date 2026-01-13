/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:24:09 by csolari           #+#    #+#             */
/*   Updated: 2025/10/15 14:45:18 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	ft_error_bis(int error_code)
{
	if (error_code == 12)
		ft_putstr_fd("Error\nInvalid map : map must be closed\n", 2);
	else if (error_code == 13)
		ft_putstr_fd("Error\nIntialisation mlx\n", 2);
	else if (error_code == 14)
		ft_putstr_fd("Error\nWhile opening window\n", 2);
	else if (error_code == 15)
		ft_putstr_fd("Error\nWhile creating images\n", 2);
	else if (error_code == 16)
		ft_putstr_fd("Error\nMap to big to be printed\n", 2);
}

void	ft_error(int error_code, t_context *context)
{
	if (error_code == 1)
		ft_putstr_fd("Error\n", 2);
	else if (error_code == 2)
		ft_putstr_fd("Error\nMalloc error\n", 2);
	else if (error_code == 3)
		ft_putstr_fd("Error\nInvalid name of file\n", 2);
	else if (error_code == 4)
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
	else if (error_code == 5)
		ft_putstr_fd("Error\nWhile opening file\n", 2);
	else if (error_code == 6)
		ft_putstr_fd("Error\nWhile reading file\n", 2);
	else if (error_code == 7)
		ft_putstr_fd("Error\nInvalid color identifier\n", 2);
	else if (error_code == 8)
		ft_putstr_fd("Error\nInvalid map\n", 2);
	else if (error_code == 9)
		ft_putstr_fd("Error\nInvalid  informations in the file\n", 2);
	else if (error_code == 10)
		ft_putstr_fd("Error\nInvalid map : must have one player\n", 2);
	else if (error_code == 11)
		ft_putstr_fd("Error\nInvalid map : wrong caracter\n", 2);
	ft_error_bis(error_code);
	clean_up(context);
	exit(1);
}
