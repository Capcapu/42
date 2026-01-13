/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reform_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:39:32 by csolari           #+#    #+#             */
/*   Updated: 2025/09/26 18:02:22 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_len_max_map(t_context *ctx)
{
	int	i;
	int	max;
	int	save;

	i = 0;
	max = 0;
	save = 0;
	while (ctx->map->tab[i])
	{
		save = ft_strlen(ctx->map->tab[i]);
		if (ctx->map->tab[i][save - 1] == '\n')
			save--;
		if (save > max)
			max = save;
		i++;
	}
	return (max);
}

static void	ft_add_space(t_context *ctx, int i, int len_max)
{
	char	*cpy;
	int		j;

	cpy = NULL;
	j = 0;
	cpy = malloc(sizeof(char *) * len_max + 1);
	while (ctx->map->tab[i][j] && ctx->map->tab[i][j] != '\n')
	{
		cpy[j] = ctx->map->tab[i][j];
		j++;
	}
	while (j < len_max)
	{
		cpy[j] = ' ';
		j++;
	}
	cpy[j] = 0;
	if (ctx->map->tab[i])
		free(ctx->map->tab[i]);
	ctx->map->tab[i] = cpy;
	if (!ctx->map->tab[i])
		ft_error(2, ctx);
}

void	reform_map(t_context *ctx)
{
	int	len_max;
	int	i;

	i = 0;
	len_max = ft_len_max_map(ctx);
	while (ctx->map->tab[i])
	{
		ft_add_space(ctx, i, len_max);
		i++;
	}
}
