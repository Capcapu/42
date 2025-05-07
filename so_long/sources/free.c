/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:14:09 by csolari           #+#    #+#             */
/*   Updated: 2025/04/08 15:52:02 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_context_bis(t_context *context)
{
	if (context->mlx)
		free(context->mlx);
	if (context->exit)
		free(context->exit);
	if (context->ground)
		free(context->ground);
	if (context->wall)
		free(context->wall);
	if (context->player)
		free(context->player);
	if (context->collectible)
		free(context->collectible);
}

void	ft_free_context(t_context *context)
{
	if (context)
	{
		ft_free_tab(context->map);
		if (context->map_struct)
			free(context->map_struct);
		if (context->exit && context->exit->img)
			mlx_destroy_image(context->mlx, context->exit->img);
		if (context->ground && context->ground->img)
			mlx_destroy_image(context->mlx, context->ground->img);
		if (context->player && context->player->img)
			mlx_destroy_image(context->mlx, context->player->img);
		if (context->wall && context->wall->img)
			mlx_destroy_image(context->mlx, context->wall->img);
		if (context->collectible && context->collectible->img)
			mlx_destroy_image(context->mlx, context->collectible->img);
		mlx_destroy_window(context->mlx, context->win);
		mlx_destroy_display(context->mlx);
		ft_free_context_bis(context);
		free(context);
	}
}
