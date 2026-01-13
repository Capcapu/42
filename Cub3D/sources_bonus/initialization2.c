/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:38:37 by csolari           #+#    #+#             */
/*   Updated: 2025/10/13 15:20:56 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	init_color(t_color *color)
{
	color->img_ptr = NULL;
	color->bits_per_pixel = 0;
	color->line_length = 0;
	color->endian = 0;
	color->pixel_index = 0;
}

void	init_press(t_press *press)
{
	press->w = 0;
	press->s = 0;
	press->d = 0;
	press->a = 0;
	press->l = 0;
	press->r = 0;
}

void	init_camera(t_camera *cam)
{
	cam->pos_x = 0.0;
	cam->pos_y = 0.0;
	cam->dir_x = 0.0;
	cam->dir_y = 0.0;
	cam->plane_x = 0.0;
	cam->plane_y = 0.0;
}

void	init_ray(t_ray *ray)
{
	ray->dir_x = 0.0;
	ray->dir_y = 0.0;
	ray->delta_dist_x = 0.0;
	ray->delta_dist_y = 0.0;
	ray->side_dist_x = 0.0;
	ray->side_dist_y = 0.0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->side = 0;
	ray->wall_o = 0;
}

void	init_texture(t_texture *tex)
{
	tex->northptr = NULL;
	tex->north = NULL;
	tex->southptr = NULL;
	tex->south = NULL;
	tex->eastptr = NULL;
	tex->east = NULL;
	tex->westptr = NULL;
	tex->west = NULL;
	tex->n_h = 0;
	tex->n_w = 0;
	tex->s_h = 0;
	tex->s_w = 0;
	tex->e_h = 0;
	tex->e_w = 0;
	tex->w_h = 0;
	tex->w_w = 0;
}
