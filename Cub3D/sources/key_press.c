/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:01:51 by luda-cun          #+#    #+#             */
/*   Updated: 2025/10/13 15:30:39 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_press(int key, void *param)
{
	t_context	*ctx;

	ctx = (t_context *)param;
	(void)key;
	if (key == 65307)
		mlx_loop_end(ctx->window->mlx);
	if (key == 119)
		ctx->press->w = 1;
	if (key == 97)
		ctx->press->a = true;
	if (key == 115)
		ctx->press->s = true;
	if (key == 100)
		ctx->press->d = true;
	if (key == 65361)
		ctx->press->l = true;
	if (key == 65363)
		ctx->press->r = true;
	return (1);
}

int	key_release(int key, void *param)
{
	t_context	*ctx;

	ctx = (t_context *)param;
	(void)key;
	if (key == 119)
		ctx->press->w = 0;
	if (key == 97)
		ctx->press->a = false;
	if (key == 115)
		ctx->press->s = false;
	if (key == 100)
		ctx->press->d = false;
	if (key == 65361)
		ctx->press->l = false;
	if (key == 65363)
		ctx->press->r = false;
	return (1);
}

int	apply_mvt(t_context *ctx)
{
	int	state;

	state = 2;
	if (ctx->press->l)
		state = see_left(ctx);
	if (ctx->press->r)
		state = see_right(ctx);
	if (ctx->press->w)
		state = go_up(ctx);
	if (ctx->press->a)
		state = go_left(ctx);
	if (ctx->press->s)
		state = go_down(ctx);
	if (ctx->press->d)
		state = go_right(ctx);
	return (state);
}

int	loop_update(void *param)
{
	static int	count = 0;
	int			state;
	t_context	*ctx;

	ctx = (t_context *)param;
	if (!ctx || !ctx->press)
		return (0);
	state = 2;
	count++;
	if (count % SPEED == 0)
	{
		state = apply_mvt(ctx);
		if (state == 0)
			mlx_loop_end(ctx->window->mlx);
		else
			raycasting(ctx);
	}
	return (1);
}
