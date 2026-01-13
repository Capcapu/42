/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_walk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:00:59 by csolari           #+#    #+#             */
/*   Updated: 2025/10/15 14:34:13 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

/*
	keypress
	65307	-Echap
	119		-W
	97		-A
	115		-S
	100		-D
	65362	-Fleche haut
	65361	-Fleche gauche
	65364	-Fleche bas
	65363	-Fleche droite
*/

int	go_up(t_context *ctx)
{
	t_move	m;

	init_move(&m, ctx, 1, 1);
	if (check_collisions_wall(m, ctx))
		return (1);
	ctx->map->x += m.move_x;
	ctx->map->y += m.move_y;
	return (1);
}

int	go_down(t_context *ctx)
{
	t_move	m;

	init_move(&m, ctx, 1, 2);
	if (check_collisions_wall(m, ctx))
		return (1);
	ctx->map->x += m.move_x;
	ctx->map->y += m.move_y;
	return (1);
}

int	go_left(t_context *ctx)
{
	t_move	m;

	init_move(&m, ctx, 2, 1);
	if (check_collisions_wall(m, ctx))
		return (1);
	ctx->map->x += m.move_x;
	ctx->map->y += m.move_y;
	return (1);
}

int	go_right(t_context *ctx)
{
	t_move	m;

	init_move(&m, ctx, 3, 1);
	if (check_collisions_wall(m, ctx))
		return (1);
	ctx->map->x += m.move_x;
	ctx->map->y += m.move_y;
	return (1);
}
