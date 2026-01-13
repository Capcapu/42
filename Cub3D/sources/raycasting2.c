/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:36:16 by csolari           #+#    #+#             */
/*   Updated: 2025/10/17 12:37:22 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

typedef struct s_tex
{
	char	*data;
	int		line_len;
	int		bpp;
	int		width;
	int		height;
	int		tex_x;
}			t_tex;

void	fill_tex_data_bis(t_tex *tex, t_context *ctx, int wall_o)
{
	if (wall_o == 3)
	{
		tex->data = ctx->tex->south->img_ptr;
		tex->line_len = ctx->tex->south->line_length;
		tex->bpp = ctx->tex->south->bits_per_pixel;
		tex->width = ctx->tex->s_w;
		tex->height = ctx->tex->s_h;
	}
	else if (wall_o == 4)
	{
		tex->data = ctx->tex->north->img_ptr;
		tex->line_len = ctx->tex->north->line_length;
		tex->bpp = ctx->tex->north->bits_per_pixel;
		tex->width = ctx->tex->n_w;
		tex->height = ctx->tex->n_h;
	}
}

// Sélectionner la bonne texture et ses dimensions
void	fill_tex_data(t_tex *tex, t_context *ctx)
{
	int	wall_o;

	wall_o = get_wall_texture_index(ctx->ray);
	if (wall_o == 1)
	{
		tex->data = ctx->tex->east->img_ptr;
		tex->line_len = ctx->tex->east->line_length;
		tex->bpp = ctx->tex->east->bits_per_pixel;
		tex->width = ctx->tex->e_w;
		tex->height = ctx->tex->e_h;
	}
	else if (wall_o == 2)
	{
		tex->data = ctx->tex->west->img_ptr;
		tex->line_len = ctx->tex->west->line_length;
		tex->bpp = ctx->tex->west->bits_per_pixel;
		tex->width = ctx->tex->w_w;
		tex->height = ctx->tex->w_h;
	}
	fill_tex_data_bis(tex, ctx, wall_o);
}

// Calculer la distance et wall_x
// Calculer tex_x (colonne de texture)
int	calc_dist_col_height_x(t_context *ctx, int *wall_height, t_tex *tex)
{
	double	perp_wall_dist;
	double	wall_x;

	if (ctx->ray->side == 0)
	{
		perp_wall_dist = (ctx->ray->side_dist_x - ctx->ray->delta_dist_x);
		wall_x = ctx->cam->pos_y + perp_wall_dist * ctx->ray->dir_y;
	}
	else
	{
		perp_wall_dist = (ctx->ray->side_dist_y - ctx->ray->delta_dist_y);
		wall_x = ctx->cam->pos_x + perp_wall_dist * ctx->ray->dir_x;
	}
	wall_x -= floor(wall_x);
	if (perp_wall_dist <= 0)
		perp_wall_dist = 0.1;
	*wall_height = (int)(ctx->screen_height / perp_wall_dist);
	return ((int)(wall_x * (double)tex->width));
}

// Draw mur avec texture
// Récupérer la couleur du pixel dans la texture
int	display_wall(t_context *ctx, int y, int wall_height, t_tex *tex)
{
	int	offset;
	int	color;
	int	tex_y;
	int	d;

	while (y < (ctx->screen_height + wall_height) / 2 && y < ctx->screen_height)
	{
		d = y * 256 - ctx->screen_height * 128 + wall_height * 128;
		tex_y = ((d * tex->height) / wall_height) / 256;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= tex->height)
			tex_y = tex->height - 1;
		offset = tex_y * tex->line_len + tex->tex_x * (tex->bpp / 8);
		color = *(unsigned int *)(tex->data + offset);
		put_pixel_to_image(ctx->image->big, ctx->screen_x, y, color);
		y++;
	}
	return (y);
}

// Draw ciel murs sol
// Calculer tex_y proportionnellement
void	draw_image(t_context *ctx)
{
	int		wall_height;
	int		y;
	int		tex_x;
	t_tex	*tex;

	y = 0;
	tex = malloc(sizeof(t_tex));
	if (!tex)
		ft_error(2, ctx);
	fill_tex_data(tex, ctx);
	tex_x = calc_dist_col_height_x(ctx, &wall_height, tex);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= tex->width)
		tex_x = tex->width - 1;
	tex->tex_x = tex_x;
	while (y < (ctx->screen_height - wall_height) / 2 && y < ctx->screen_height)
		put_pixel_to_image(ctx->image->big, ctx->screen_x, y++,
			ctx->image->c_rgb);
	y = display_wall(ctx, y, wall_height, tex);
	while (y < ctx->screen_height)
		put_pixel_to_image(ctx->image->big, ctx->screen_x, y++,
			ctx->image->f_rgb);
	free(tex);
}
