/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 10:43:35 by csolari           #+#    #+#             */
/*   Updated: 2025/10/17 12:44:53 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_image(t_image *image)
{
	image->big = NULL;
	image->adr_no = NULL;
	image->adr_so = NULL;
	image->adr_we = NULL;
	image->adr_ea = NULL;
	image->bigptr = NULL;
	image->f_r = -1;
	image->f_g = -1;
	image->f_b = -1;
	image->c_r = -1;
	image->c_g = -1;
	image->c_b = -1;
	image->f_rgb = -1;
	image->c_rgb = -1;
}

void	init_map(t_map *map)
{
	map->tab = NULL;
	map->lst = NULL;
	map->o = 0;
	map->x = 0;
	map->y = 0;
	map->deg = 0;
	map->height = 0;
	map->width = 0;
}

void	init_win(t_window *window)
{
	window->mlx = NULL;
	window->win = NULL;
}

void	init_big(t_context *ctx)
{
	void	*bigptr;
	t_color	*big;

	big = malloc(sizeof(t_color));
	if (!big)
		ft_error(2, ctx);
	bigptr = mlx_new_image(ctx->window->mlx, ctx->screen_width,
			ctx->screen_height);
	if (!bigptr)
	{
		free(big);
		ft_error(15, ctx);
	}
	big->img_ptr = mlx_get_data_addr(bigptr, &big->bits_per_pixel,
			&big->line_length, &big->endian);
	if (!big->img_ptr)
	{
		mlx_destroy_image(ctx->window->mlx, bigptr);
		ft_error(15, ctx);
	}
	ctx->image->big = big;
	ctx->image->bigptr = bigptr;
}
