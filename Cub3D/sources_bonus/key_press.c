/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:01:51 by luda-cun          #+#    #+#             */
/*   Updated: 2025/10/14 14:29:05 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

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
	return (1);
}

int	mouse_move(int x, int y, void *param)
{
	t_context	*ctx;
	static int	last_x = -1;

	(void)y;
	ctx = (t_context *)param;
	if (last_x == -1)
	{
		mlx_mouse_move(ctx->window->mlx, ctx->window->win, ctx->screen_width
			/ 2, ctx->screen_height / 2);
		last_x = ctx->screen_width / 2;
		return (1);
	}
	if (last_x - x < 0)
		see_right(ctx);
	else if (last_x - x > 0)
		see_left(ctx);
	last_x = x;
	if (x < 100 || x > ctx->screen_width - 100)
	{
		mlx_mouse_move(ctx->window->mlx, ctx->window->win, ctx->screen_width
			/ 2, ctx->screen_height / 2);
		last_x = ctx->screen_width / 2;
	}
	return (1);
}

int	key_release(int key, void *param)
{
	t_context	*ctx;

	ctx = (t_context *)param;
	if (key == 119)
		ctx->press->w = false;
	if (key == 97)
		ctx->press->a = false;
	if (key == 115)
		ctx->press->s = false;
	if (key == 100)
		ctx->press->d = false;
	return (1);
}

int	apply_mvt(t_context *ctx)
{
	int	state;

	state = 2;
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
