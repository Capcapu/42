/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:20:56 by csolari           #+#    #+#             */
/*   Updated: 2025/10/17 12:44:12 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_map(t_context *context)
{
	if (context->map)
	{
		if (context->map->tab)
			ft_free_tab(context->map->tab);
		if (context->map->lst)
			ft_lstfree(&context->map->lst);
		free(context->map);
	}
}

void	free_image(t_context *ctx)
{
	if (ctx->image)
	{
		if (ctx->image->adr_no)
			free(ctx->image->adr_no);
		if (ctx->image->adr_so)
			free(ctx->image->adr_so);
		if (ctx->image->adr_we)
			free(ctx->image->adr_we);
		if (ctx->image->adr_ea)
			free(ctx->image->adr_ea);
		if (ctx->image->big)
		{
			if (ctx->image->bigptr)
				mlx_destroy_image(ctx->window->mlx, ctx->image->bigptr);
			free(ctx->image->big);
		}
		free(ctx->image);
	}
}

void	free_window_cam_ray(t_context *ctx)
{
	if (ctx->window)
	{
		if (ctx->window->win && ctx->window->mlx)
			mlx_destroy_window(ctx->window->mlx, ctx->window->win);
		if (ctx->window->mlx)
		{
			mlx_destroy_display(ctx->window->mlx);
			free(ctx->window->mlx);
		}
		free(ctx->window);
	}
	if (ctx->cam)
		free(ctx->cam);
	if (ctx->ray)
		free(ctx->ray);
}

void	clean_up(t_context *context)
{
	if (context)
	{
		if (context->file)
			ft_lstfree(&context->file);
		if (context->fd >= 0)
			close(context->fd);
		free_map(context);
		if (context->tex)
		{
			free_textures(context);
			free(context->tex);
		}
		free_image(context);
		free_window_cam_ray(context);
		if (context->press)
			free(context->press);
		free(context);
	}
}
