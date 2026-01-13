/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_line_col.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:42:31 by csolari           #+#    #+#             */
/*   Updated: 2025/10/13 15:20:00 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	check_line(t_context *ctx, int i, int j)
{
	int	pos;

	pos = j;
	while (j >= 0 && ctx->map->tab[i][j] && ctx->map->tab[i][j] != '1'
		&& (ctx->map->tab[i][j] == '0' || ctx->map->tab[i][j] == ctx->map->o))
		j--;
	if (j == -1 || (ctx->map->tab[i][j] && ctx->map->tab[i][j] != '1'))
		ft_error(12, ctx);
	while (ctx->map->tab[i][pos] && ctx->map->tab[i][pos] != '1'
		&& (ctx->map->tab[i][pos] == '0'
			|| ctx->map->tab[i][pos] == ctx->map->o))
		pos++;
	if (ctx->map->tab[i][pos] == 0 || ctx->map->tab[i][pos] != '1')
		ft_error(12, ctx);
}

void	check_col(t_context *ctx, int i, int j)
{
	int	pos;

	pos = i;
	while (i >= 0 && ctx->map->tab[i] && ctx->map->tab[i][j]
		&& ctx->map->tab[i][j] != '1' && (ctx->map->tab[i][j] == '0'
			|| ctx->map->tab[i][j] == ctx->map->o))
		i--;
	if (i == -1 || (ctx->map->tab[i] && ctx->map->tab[i][j]
		&& ctx->map->tab[i][j] != '1'))
		ft_error(12, ctx);
	while (ctx->map->tab[pos] && ctx->map->tab[pos][j]
		&& ctx->map->tab[pos][j] != '1' && (ctx->map->tab[pos][j] == '0'
			|| ctx->map->tab[pos][j] == ctx->map->o))
		pos++;
	if (ctx->map->tab[pos] == NULL || (ctx->map->tab[pos]
			&& ctx->map->tab[pos][j] && ctx->map->tab[pos][j] != '1'))
		ft_error(12, ctx);
}
