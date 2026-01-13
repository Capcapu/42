/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:08:47 by csolari           #+#    #+#             */
/*   Updated: 2025/10/15 14:34:44 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	init_move(t_move *m, t_context *ctx, int deg, int trigo)
{
	m->speed = 0.05;
	if (deg == 1)
		m->angle_rad = ctx->map->deg * 3.14159265359 / 180.0;
	else if (deg == 2)
		m->angle_rad = (ctx->map->deg - 90) * 3.14159265359 / 180.0;
	else if (deg == 3)
		m->angle_rad = (ctx->map->deg + 90) * 3.14159265359 / 180.0;
	if (trigo == 1)
	{
		m->move_x = cos(m->angle_rad) * m->speed;
		m->move_y = sin(m->angle_rad) * m->speed;
	}
	else if (trigo == 2)
	{
		m->move_x = -cos(m->angle_rad) * m->speed;
		m->move_y = -sin(m->angle_rad) * m->speed;
	}
	m->x = (int)ctx->map->x;
	m->y = (int)ctx->map->y;
	m->new_x = (int)(ctx->map->x + m->move_x);
	m->new_y = (int)(ctx->map->y + m->move_y);
}

int	check_collisions_wall(t_move m, t_context *ctx)
{
	if (ctx->map->y + m.move_y <= 1.0 || (ctx->map->tab[m.new_y]
			&& ctx->map->tab[m.new_y][m.new_x]
		&& ctx->map->tab[m.new_y][m.new_x] == '1'))
		return (1);
	if (ctx->map->x + m.move_x <= 1.0 || (ctx->map->tab[m.new_y]
			&& ctx->map->tab[m.new_y][m.new_x]
		&& ctx->map->tab[m.new_y][m.new_x] == '1'))
		return (1);
	if (ctx->map->tab[m.new_y] && ctx->map->tab[m.new_y][m.new_x]
		&& ctx->map->tab[m.new_y][m.new_x] == '1')
		return (1);
	if (ctx->map->tab[m.new_y] && ctx->map->tab[m.new_y][m.new_x]
		&& ctx->map->tab[m.new_y][m.new_x] == '1')
		return (1);
	if (ctx->map->tab[m.new_y] && ctx->map->tab[m.new_y][m.new_x]
		&& ctx->map->tab[m.new_y][m.new_x] == ' ')
		return (1);
	return (0);
}
