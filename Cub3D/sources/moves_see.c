/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_see.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:06:44 by luda-cun          #+#    #+#             */
/*   Updated: 2025/10/10 18:24:21 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	see_right(t_context *ctx)
{
	int	x;
	int	y;
	int	deg;

	deg = ctx->map->deg;
	x = (int)(ctx->map->x);
	y = (int)(ctx->map->y);
	if (ctx->map->o == 'E' && ((deg + 3 < 90) || (deg + 3 >= 360)))
		ctx->map->o = 'S';
	else if (ctx->map->o == 'S' && deg + 3 < 180)
		ctx->map->o = 'W';
	else if (ctx->map->o == 'W' && deg + 3 < 270)
		ctx->map->o = 'N';
	else if (ctx->map->o == 'N' && deg + 3 <= 359)
		ctx->map->o = 'E';
	ctx->map->deg += 3;
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
	if (ctx->map->o == 'W' && deg - 3 < 180)
		ctx->map->o = 'S';
	else if (ctx->map->o == 'N' && deg - 3 < 270)
		ctx->map->o = 'W';
	else if (ctx->map->o == 'E' && deg - 3 < 0)
		ctx->map->o = 'N';
	else if (ctx->map->o == 'S' && deg - 3 < 90)
		ctx->map->o = 'E';
	ctx->map->deg -= 3;
	if (ctx->map->deg < 0)
		ctx->map->deg = ctx->map->deg + 360;
	return (1);
}
