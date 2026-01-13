/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:55:19 by csolari           #+#    #+#             */
/*   Updated: 2025/04/08 15:52:12 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_lst_exit(t_context *context)
{
	t_data	*exit;

	exit = NULL;
	exit = malloc(sizeof(t_data));
	if (!exit)
		return (ft_putstr_fd("Error : Malloc\n", 2), ft_free_context(context),
			0);
	init_lst_data(exit);
	(*exit).img = mlx_xpm_file_to_image(context->mlx, "images/exit.xpm",
			&(*exit).width, &(*exit).height);
	context->exit = exit;
	if (!(*exit).img)
		return (ft_free_context(context), 0);
	return (1);
}

int	init_lst_ground(t_context *context)
{
	t_data	*ground;

	ground = NULL;
	ground = malloc(sizeof(t_data));
	if (!ground)
		return (ft_putstr_fd("Error : Malloc\n", 2), free(context->exit), 0);
	init_lst_data(ground);
	(*ground).img = mlx_xpm_file_to_image(context->mlx, "images/ground.xpm",
			&(*ground).width, &(*ground).height);
	context->ground = ground;
	if (!(*ground).img)
		return (ft_free_context(context), 0);
	return (1);
}

int	init_lst_player(t_context *context)
{
	t_data	*player;

	player = NULL;
	player = malloc(sizeof(t_data));
	if (!player)
		return (ft_putstr_fd("Error : Malloc\n", 2), ft_free_context(context),
			0);
	init_lst_data(player);
	(*player).img = mlx_xpm_file_to_image(context->mlx, "images/player.xpm",
			&(*player).width, &(*player).height);
	context->player = player;
	if (!(*player).img)
		return (ft_free_context(context), 0);
	return (1);
}

int	init_lst_wall(t_context *context)
{
	t_data	*wall;

	wall = NULL;
	wall = malloc(sizeof(t_data));
	if (!wall)
		return (ft_putstr_fd("Error : Malloc\n", 2), ft_free_context(context),
			0);
	init_lst_data(wall);
	(*wall).img = mlx_xpm_file_to_image(context->mlx, "images/wall.xpm",
			&(*wall).width, &(*wall).height);
	context->wall = wall;
	if (!(*wall).img)
		return (ft_free_context(context), 0);
	return (1);
}

int	init_lst_collec(t_context *context)
{
	t_data	*collec;

	collec = NULL;
	collec = malloc(sizeof(t_data));
	if (!collec)
		return (ft_putstr_fd("Error : Malloc\n", 2), ft_free_context(context),
			0);
	init_lst_data(collec);
	(*collec).img = mlx_xpm_file_to_image(context->mlx,
			"images/collectible.xpm", &(*collec).width, &(*collec).height);
	context->collectible = collec;
	if (!(*collec).img)
		return (ft_free_context(context), 0);
	return (1);
}
