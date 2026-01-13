/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:06:27 by csolari           #+#    #+#             */
/*   Updated: 2025/10/17 12:36:59 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

// if (ray->side == 0)  // Mur vertical (axe X)
//     if (ray->step_x > 0) // Texture Est
//     else // Texture Ouest
// else  // Mur horizontal (axe Y)
//     if (ray->step_y > 0) // Texture Sud
//     else // Texture Nord

int	get_wall_texture_index(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->step_x > 0)
			return (1);
		else
			return (2);
	}
	else
	{
		if (ray->step_y > 0)
			return (3);
		else
			return (4);
	}
}

void	draw_col(t_context *ctx)
{
	int		screen_x;
	double	wall_x;
	double	wall_y;

	screen_x = 0;
	while (screen_x < ctx->screen_width)
	{
		init_data_ray(ctx->ray, ctx->cam, screen_x, ctx->screen_width);
		calc_step_and_side_dist(ctx->ray, ctx->cam);
		perform_dda(ctx->ray, ctx);
		calc_wall_position(ctx->ray, ctx->cam, &wall_x, &wall_y);
		ctx->screen_x = screen_x;
		draw_image(ctx);
		screen_x++;
	}
}

void	raycasting(t_context *ctx)
{
	if (!ctx || !ctx->window || !ctx->window->mlx || !ctx->window->win)
		return ;
	if (!ctx->cam || !ctx->ray)
		return ;
	ctx->image->c_rgb = convert_rgb(ctx->image->c_r, ctx->image->c_g,
			ctx->image->c_b);
	ctx->image->f_rgb = convert_rgb(ctx->image->f_r, ctx->image->f_g,
			ctx->image->f_b);
	init_big(ctx);
	init_data_camera(ctx->cam, ctx);
	draw_col(ctx);
	ctx->number_image++;
	mlx_put_image_to_window(ctx->window->mlx, ctx->window->win,
		ctx->image->bigptr, 0, 0);
	display_mini_map(ctx);
	mlx_destroy_image(ctx->window->mlx, ctx->image->bigptr);
	ctx->image->bigptr = NULL;
	free(ctx->image->big);
	ctx->image->big = NULL;
}
