/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_raycasting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:03:58 by csolari           #+#    #+#             */
/*   Updated: 2025/10/13 15:20:47 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	init_data_camera(t_camera *cam, t_context *ctx)
{
	double	angle_rad;

	cam->pos_x = (double)ctx->map->x;
	cam->pos_y = (double)ctx->map->y;
	angle_rad = (ctx->map->deg) * 3.14159265359 / 180.0;
	cam->dir_x = cos(angle_rad);
	cam->dir_y = sin(angle_rad);
	cam->plane_x = -cam->dir_y * 0.66;
	cam->plane_y = cam->dir_x * 0.66;
}

void	init_data_ray(t_ray *ray, t_camera *cam, int screen_x, int screen_width)
{
	double	cam_x;

	cam_x = 2 * screen_x / (double)screen_width - 1;
	ray->dir_x = cam->dir_x + cam->plane_x * cam_x;
	ray->dir_y = cam->dir_y + cam->plane_y * cam_x;
	ray->map_x = (int)cam->pos_x;
	ray->map_y = (int)cam->pos_y;
	if (ray->dir_x == 0)
		ray->delta_dist_x = 1000000000.0;
	else
		ray->delta_dist_x = fabs(1 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->delta_dist_y = 1000000000.0;
	else
		ray->delta_dist_y = fabs(1 / ray->dir_y);
}
