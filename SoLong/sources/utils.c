/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:28:43 by csolari           #+#    #+#             */
/*   Updated: 2025/04/08 12:54:37 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_lst_map(t_map *lst_map)
{
	lst_map->x = 0;
	lst_map->y = 0;
	lst_map->row = 0;
	lst_map->col = 0;
	lst_map->collectible = 0;
	lst_map->exit = 0;
	lst_map->player = 0;
}

void	init_lst_data(t_data *data)
{
	data->img = NULL;
	data->addr = NULL;
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->endian = 0;
	data->width = 0;
	data->height = 0;
}

void	init_lst_context(t_context *context)
{
	context->mlx = NULL;
	context->win = NULL;
	context->map = NULL;
	context->map_struct = NULL;
	context->exit = NULL;
	context->ground = NULL;
	context->player = NULL;
	context->wall = NULL;
	context->collectible = NULL;
	context->nb_moves = 0;
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		ft_printf("%s", map[i]);
		i++;
	}
	ft_printf("\n");
}

void	flood_fill(char **tab, t_map *map_struct, int x, int y)
{
	int	exit;

	exit = 0;
	if (x < 0 || y < 0 || y >= map_struct->col || x >= map_struct->row)
		return ;
	if (tab[x][y] == 'F' || tab[x][y] == '1')
		return ;
	if (tab[x][y] == 'E')
		exit = 1;
	tab[x][y] = 'F';
	if (exit == 0)
	{
		flood_fill(tab, map_struct, x - 1, y);
		flood_fill(tab, map_struct, x + 1, y);
		flood_fill(tab, map_struct, x, y - 1);
		flood_fill(tab, map_struct, x, y + 1);
	}
}
