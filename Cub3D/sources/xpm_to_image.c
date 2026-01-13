/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_to_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:04:51 by csolari           #+#    #+#             */
/*   Updated: 2025/10/17 12:45:45 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_sprite_north(t_context *ctx)
{
	t_color	*north;
	int		width;
	int		height;

	north = (t_color *)malloc(sizeof(t_color));
	if (!north)
		ft_error(2, ctx);
	init_color(north);
	ctx->tex->north = north;
	ctx->tex->northptr = mlx_xpm_file_to_image(ctx->window->mlx,
			ctx->image->adr_no, &width, &height);
	if (!ctx->tex->northptr)
		ft_error(15, ctx);
	north->img_ptr = mlx_get_data_addr(ctx->tex->northptr,
			&north->bits_per_pixel, &north->line_length, &north->endian);
	if (!north->img_ptr)
		ft_error(15, ctx);
	ctx->tex->n_h = height;
	ctx->tex->n_w = width;
}

static void	init_sprite_south(t_context *ctx)
{
	t_color	*south;
	int		width;
	int		height;

	south = (t_color *)malloc(sizeof(t_color));
	if (!south)
		ft_error(2, ctx);
	init_color(south);
	ctx->tex->south = south;
	ctx->tex->southptr = mlx_xpm_file_to_image(ctx->window->mlx,
			ctx->image->adr_so, &width, &height);
	if (!ctx->tex->southptr)
		ft_error(15, ctx);
	south->img_ptr = mlx_get_data_addr(ctx->tex->southptr,
			&south->bits_per_pixel, &south->line_length, &south->endian);
	if (!south->img_ptr)
		ft_error(15, ctx);
	ctx->tex->s_h = height;
	ctx->tex->s_w = width;
}

static void	init_sprite_east(t_context *ctx)
{
	t_color	*east;
	int		width;
	int		height;

	east = (t_color *)malloc(sizeof(t_color));
	if (!east)
		ft_error(2, ctx);
	init_color(east);
	ctx->tex->east = east;
	ctx->tex->eastptr = mlx_xpm_file_to_image(ctx->window->mlx,
			ctx->image->adr_ea, &width, &height);
	if (!ctx->tex->eastptr)
		ft_error(15, ctx);
	east->img_ptr = mlx_get_data_addr(ctx->tex->eastptr, &east->bits_per_pixel,
			&east->line_length, &east->endian);
	if (!east->img_ptr)
		ft_error(15, ctx);
	ctx->tex->e_h = height;
	ctx->tex->e_w = width;
}

static void	init_sprite_west(t_context *ctx)
{
	t_color	*west;
	int		width;
	int		height;

	west = (t_color *)malloc(sizeof(t_color));
	if (!west)
		ft_error(2, ctx);
	init_color(west);
	ctx->tex->west = west;
	ctx->tex->westptr = mlx_xpm_file_to_image(ctx->window->mlx,
			ctx->image->adr_we, &width, &height);
	if (!ctx->tex->westptr)
		ft_error(15, ctx);
	west->img_ptr = mlx_get_data_addr(ctx->tex->westptr, &west->bits_per_pixel,
			&west->line_length, &west->endian);
	if (!west->img_ptr)
		ft_error(15, ctx);
	ctx->tex->w_h = height;
	ctx->tex->w_w = width;
}

void	init_sprite(t_context *ctx)
{
	init_sprite_north(ctx);
	init_sprite_south(ctx);
	init_sprite_east(ctx);
	init_sprite_west(ctx);
}
