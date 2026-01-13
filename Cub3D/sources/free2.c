/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:25:51 by csolari           #+#    #+#             */
/*   Updated: 2025/10/13 10:48:40 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

void	free_textures(t_context *ctx)
{
	if (ctx->tex->north)
	{
		if (ctx->tex->northptr)
			mlx_destroy_image(ctx->window->mlx, ctx->tex->northptr);
		free(ctx->tex->north);
	}
	if (ctx->tex->south)
	{
		if (ctx->tex->southptr)
			mlx_destroy_image(ctx->window->mlx, ctx->tex->southptr);
		free(ctx->tex->south);
	}
	if (ctx->tex->east)
	{
		if (ctx->tex->eastptr)
			mlx_destroy_image(ctx->window->mlx, ctx->tex->eastptr);
		free(ctx->tex->east);
	}
	if (ctx->tex->west)
	{
		if (ctx->tex->westptr)
			mlx_destroy_image(ctx->window->mlx, ctx->tex->westptr);
		free(ctx->tex->west);
	}
}
