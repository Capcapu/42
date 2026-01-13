/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:49:43 by csolari           #+#    #+#             */
/*   Updated: 2025/10/13 15:21:50 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

char	**lst_into_tab(t_context *ctx, int size_tab)
{
	char	**map;
	int		size;
	int		i;
	t_list	*current;

	if (!ctx->current)
		return (NULL);
	size = size_tab;
	map = malloc(sizeof(char *) * (size + 1));
	if (!map)
		ft_error(2, ctx);
	i = 0;
	current = ctx->current;
	while (i < size && current)
	{
		map[i] = ft_strdup(current->content);
		if (!map[i++])
		{
			ft_free_tab(map);
			return (NULL);
		}
		current = current->next;
	}
	map[i] = NULL;
	return (map);
}

void	size_map(t_context *ctx)
{
	int	i;

	i = 0;
	while (ctx->map->tab && ctx->map->tab[i])
		i++;
	ctx->map->height = i;
	i = 0;
	while (ctx->map->tab && ctx->map->tab[0] && ctx->map->tab[0][i])
		i++;
	ctx->map->width = i;
}

int	convert_rgb(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

void	put_pixel_to_image(t_color *image, int x, int y, int color)
{
	int	offset;

	if (x < 0 || y < 0 || !image || !image->img_ptr)
		return ;
	offset = y * image->line_length + x * (image->bits_per_pixel / 8);
	*(unsigned int *)(image->img_ptr + offset) = color;
}
