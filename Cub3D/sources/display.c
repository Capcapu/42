/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:31:14 by csolari           #+#    #+#             */
/*   Updated: 2025/10/13 16:53:14 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	close_window(t_context *ctx)
{
	clean_up(ctx);
	exit(0);
	return (0);
}

void	display(t_context *ctx)
{
	int	size;

	size = 64;
	ctx->window->mlx = mlx_init();
	if (!ctx->window->mlx)
		ft_error(13, ctx);
	mlx_get_screen_size(ctx->window->mlx, &ctx->screen_width,
		&ctx->screen_height);
	ctx->window->win = mlx_new_window(ctx->window->mlx, ctx->screen_width,
			ctx->screen_height, "cub3D");
	if (!ctx->window->win)
		ft_error(14, ctx);
	init_sprite(ctx);
	raycasting(ctx);
	mlx_hook(ctx->window->win, 2, 1L << 0, key_press, ctx);
	mlx_hook(ctx->window->win, 3, 1L << 1, key_release, ctx);
	mlx_loop_hook(ctx->window->mlx, loop_update, ctx);
	mlx_hook(ctx->window->win, 17, 0, close_window, ctx);
	mlx_loop(ctx->window->mlx);
}
