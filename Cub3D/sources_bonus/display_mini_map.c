/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_mini_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:43:24 by luda-cun          #+#    #+#             */
/*   Updated: 2025/10/15 14:59:16 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

// Création nouvelle image, comme une toile vierge
// modification des pixels de la nouvelle image pour mettre pixels colores
// Couleur blanche (RGB: 255,255,255)
// 0xFF0000 Rouge
// 0xFFFFFF Blanc

void	fill_image_white(t_context *ctx, int size)
{
	int		y;
	int		x;
	t_color	*white;

	white = (t_color *)malloc(sizeof(t_color));
	if (!white)
		ft_error(2, ctx);
	init_color(white);
	ctx->image->white = white;
	white->img_ptr = mlx_get_data_addr(ctx->image->whiteptr,
			&white->bits_per_pixel, &white->line_length, &white->endian);
	if (!white->img_ptr)
		ft_error(15, ctx);
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			white->pixel_index = y * white->line_length + x++
				*(white->bits_per_pixel / 8);
			*(int *)(white->img_ptr + white->pixel_index) = 0xFFFFFF;
		}
		y++;
	}
}

void	fill_image_black(t_context *ctx, int size)
{
	int		y;
	int		x;
	t_color	*black;

	black = (t_color *)malloc(sizeof(t_color));
	if (!black)
		ft_error(2, ctx);
	init_color(black);
	ctx->image->black = black;
	black->img_ptr = mlx_get_data_addr(ctx->image->blackptr,
			&black->bits_per_pixel, &black->line_length, &black->endian);
	if (!black->img_ptr)
		ft_error(15, ctx);
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			black->pixel_index = y * black->line_length + x++
				*(black->bits_per_pixel / 8);
			*(int *)(black->img_ptr + black->pixel_index) = 0xC8CCCE;
		}
		y++;
	}
}

void	fill_image_red(t_context *ctx, int size)
{
	int		y;
	int		x;
	t_color	*red;

	red = (t_color *)malloc(sizeof(t_color));
	if (!red)
		ft_error(2, ctx);
	init_color(red);
	ctx->image->red = red;
	red->img_ptr = mlx_get_data_addr(ctx->image->redptr, &red->bits_per_pixel,
			&red->line_length, &red->endian);
	if (!red->img_ptr)
		ft_error(15, ctx);
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			red->pixel_index = y * red->line_length + x++ *(red->bits_per_pixel
					/ 8);
			*(int *)(red->img_ptr + red->pixel_index) = 0xFF0000;
		}
		y++;
	}
}

void	init_mlx_images(t_context *ctx)
{
	int	size_y;
	int	size_x;

	size_x = (ctx->screen_height * 0.2) / ctx->map->height;
	size_y = (ctx->screen_width * 0.2) / ctx->map->width;
	if (size_x > size_y)
		ctx->size_pix = size_y;
	else
		ctx->size_pix = size_x;
	if (ctx->size_pix < 1)
		ctx->size_pix = 1;
	ctx->image->whiteptr = mlx_new_image(ctx->window->mlx, ctx->size_pix,
			ctx->size_pix);
	if (!ctx->image->whiteptr)
		ft_error(15, ctx);
	ctx->image->blackptr = mlx_new_image(ctx->window->mlx, ctx->size_pix,
			ctx->size_pix);
	if (!ctx->image->blackptr)
		ft_error(15, ctx);
	ctx->image->redptr = mlx_new_image(ctx->window->mlx, ctx->size_pix * 0.3,
			ctx->size_pix * 0.3);
	if (!ctx->image->redptr)
		ft_error(15, ctx);
	return (fill_image_white(ctx, ctx->size_pix), fill_image_red(ctx,
			ctx->size_pix * 0.3), fill_image_black(ctx, ctx->size_pix));
}

void	put_image(t_context *ctx, int i, int j)
{
	if (ctx->map->tab[i][j] == '0' || ctx->map->tab[i][j] == 'N'
		|| ctx->map->tab[i][j] == 'O' || ctx->map->tab[i][j] == 'S'
		|| ctx->map->tab[i][j] == 'E')
		mlx_put_image_to_window(ctx->window->mlx, ctx->window->win,
			ctx->image->whiteptr, ctx->size_pix * j, ctx->size_pix * i);
	else if (ctx->map->tab[i][j] == '1')
		mlx_put_image_to_window(ctx->window->mlx, ctx->window->win,
			ctx->image->blackptr, ctx->size_pix * j, ctx->size_pix * i);
}
