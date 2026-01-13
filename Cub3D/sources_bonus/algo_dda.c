/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_dda.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:08:43 by luda-cun          #+#    #+#             */
/*   Updated: 2025/10/13 15:19:53 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	hit_a_wall(t_context *ctx, int y, int x)
{
	if (x < 0 || y < 0 || !ctx->map->tab || !ctx->map->tab[y]
		|| !ctx->map->tab[y][x])
		return (2);
	if (ctx->map->tab[y][x] == '1')
		return (1);
	else
		return (0);
}

void	calc_step_and_side_dist(t_ray *ray, t_camera *cam)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (cam->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - cam->pos_x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (cam->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - cam->pos_y) * ray->delta_dist_y;
	}
}

void	calc_wall_position(t_ray *ray, t_camera *cam, double *wall_x,
		double *wall_y)
{
	double	perp_wall_dist;

	if (ray->side == 0)
	{
		perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
		if (ray->step_x < 0)
			*wall_x = ray->map_x + 1.0;
		else
			*wall_x = ray->map_x;
		*wall_y = cam->pos_y + perp_wall_dist * ray->dir_y;
	}
	else
	{
		perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
		*wall_x = cam->pos_x + perp_wall_dist * ray->dir_x;
		if (ray->step_y < 0)
			*wall_y = ray->map_y + 1.0;
		else
			*wall_y = ray->map_y;
	}
}

int	perform_dda(t_ray *ray, t_context *ctx)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (hit_a_wall(ctx, ray->map_y, ray->map_x) == 2)
			hit = 2;
		else if (hit_a_wall(ctx, ray->map_y, ray->map_x) == 1)
			hit = 1;
	}
	return (hit);
}
