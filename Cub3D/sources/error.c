/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:24:09 by csolari           #+#    #+#             */
/*   Updated: 2025/09/29 13:42:25 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_error_bis(int error_code)
{
	if (error_code == 12)
		ft_putstr_fd("Error\nUnvalid map : map must be closed\n", 2);
	else if (error_code == 13)
		ft_putstr_fd("Error\nIntialisation mlx\n", 2);
	else if (error_code == 14)
		ft_putstr_fd("Error\nWhile opening window\n", 2);
	else if (error_code == 15)
		ft_putstr_fd("Error\nWhile creating images\n", 2);
}

void	ft_error(int error_code, t_context *context)
{
	if (error_code == 1)
		ft_putstr_fd("Error\n", 2);
	else if (error_code == 2)
		ft_putstr_fd("Error\nMalloc error\n", 2);
	else if (error_code == 3)
		ft_putstr_fd("Error\nUnvalid name of file\n", 2);
	else if (error_code == 4)
		ft_putstr_fd("Error\nUnvalid number of arguments\n", 2);
	else if (error_code == 5)
		ft_putstr_fd("Error\nWhile opening file\n", 2);
	else if (error_code == 6)
		ft_putstr_fd("Error\nWhile reading file\n", 2);
	else if (error_code == 7)
		ft_putstr_fd("Error\nUnvalid color identifier\n", 2);
	else if (error_code == 8)
		ft_putstr_fd("Error\nUnvalid map\n", 2);
	else if (error_code == 9)
		ft_putstr_fd("Error\nUnvalid  informations in the file\n", 2);
	else if (error_code == 10)
		ft_putstr_fd("Error\nUnvalid map : must have one player\n", 2);
	else if (error_code == 11)
		ft_putstr_fd("Error\nUnvalid map : wrong caracter\n", 2);
	ft_error_bis(error_code);
	clean_up(context);
	exit(1);
}
