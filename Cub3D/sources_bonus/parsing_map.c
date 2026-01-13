/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:51:42 by csolari           #+#    #+#             */
/*   Updated: 2025/10/13 15:21:29 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	check_map_closed(t_context *ctx)
{
	int	i;
	int	j;

	i = 0;
	while (ctx->map->tab && ctx->map->tab[i])
	{
		j = 0;
		while (ctx->map->tab[i][j])
		{
			if (ctx->map->tab[i][j] == '0'
				|| ctx->map->tab[i][j] == ctx->map->o)
			{
				check_line(ctx, i, j);
				check_col(ctx, i, j);
			}
			j++;
		}
		i++;
	}
}

static void	check_and_fill_info_player(t_context *ctx, int i, int j)
{
	if (ctx->map->o != 0)
		ft_error(10, ctx);
	ctx->map->o = ctx->map->tab[i][j];
	if (ctx->map->o == 'N')
		ctx->map->deg = 270;
	else if (ctx->map->o == 'E')
		ctx->map->deg = 0;
	else if (ctx->map->o == 'S')
		ctx->map->deg = 90;
	else if (ctx->map->o == 'W')
		ctx->map->deg = 180;
	ctx->map->y = i + 0.5;
	ctx->map->x = j + 0.5;
}

static void	check_caracters(t_context *ctx)
{
	char	**tab;
	int		i;
	int		j;

	tab = ctx->map->tab;
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'N' || tab[i][j] == 'S' || tab[i][j] == 'W'
				|| tab[i][j] == 'E')
				check_and_fill_info_player(ctx, i, j);
			else if (tab[i][j] != '0' && tab[i][j] != '1' && tab[i][j] != ' ')
				ft_error(11, ctx);
			j++;
		}
		i++;
	}
	if (ctx->map->o == 0)
		ft_error(10, ctx);
}

void	check_valid_map(t_context *ctx)
{
	reform_map(ctx);
	check_caracters(ctx);
	check_map_closed(ctx);
	size_map(ctx);
}

void	parsing_map(t_context *ctx)
{
	int	size;

	while (ctx->current && ctx->current->next)
	{
		if (is_backslash(ctx->current->content))
		{
			ctx->current = ctx->current->next;
		}
		else
			break ;
	}
	if (!ctx->current->next)
		ft_error(8, ctx);
	size = check_end_file(ctx);
	ctx->map->tab = lst_into_tab(ctx, size);
	check_valid_map(ctx);
}
