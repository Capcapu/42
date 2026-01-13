/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_see.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:06:44 by luda-cun          #+#    #+#             */
/*   Updated: 2025/10/14 14:13:44 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	see_right(t_context *ctx)
{
	int	x;
	int	y;
	int	deg;

	deg = ctx->map->deg;
	x = (int)(ctx->map->x);
	y = (int)(ctx->map->y);
	if (ctx->map->o == 'E' && ((deg + 1 < 90) || (deg + 1 >= 360)))
		ctx->map->o = 'S';
	else if (ctx->map->o == 'S' && deg + 1 < 180)
		ctx->map->o = 'W';
	else if (ctx->map->o == 'W' && deg + 1 < 270)
		ctx->map->o = 'N';
	else if (ctx->map->o == 'N' && deg + 1 <= 359)
		ctx->map->o = 'E';
	ctx->map->deg += 1;
	if (ctx->map->deg >= 360)
		ctx->map->deg = ctx->map->deg - 360;
	return (1);
}

int	see_left(t_context *ctx)
{
	int	x;
	int	y;
	int	deg;

	deg = ctx->map->deg;
	x = (int)(ctx->map->x);
	y = (int)(ctx->map->y);
	if (ctx->map->o == 'W' && deg - 1 < 180)
		ctx->map->o = 'S';
	else if (ctx->map->o == 'N' && deg - 1 < 270)
		ctx->map->o = 'W';
	else if (ctx->map->o == 'E' && deg - 1 < 0)
		ctx->map->o = 'N';
	else if (ctx->map->o == 'S' && deg - 1 < 90)
		ctx->map->o = 'E';
	ctx->map->deg -= 1;
	if (ctx->map->deg < 0)
		ctx->map->deg = ctx->map->deg + 360;
	return (1);
}
