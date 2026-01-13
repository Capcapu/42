/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:38:26 by csolari           #+#    #+#             */
/*   Updated: 2025/04/08 15:47:27 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*****************************************************************************
check if all lines are the same lenght
check if the map is rectangular
check if the map is surrounded by walls
*****************************************************************************/
int	check_map_walls(char **map, size_t len, size_t i)
{
	int	j;

	j = 0;
	while (map[0][j] != '\n')
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (ft_putstr_fd("Error : Map not surrounded by walls\n", 2),
				0);
		j++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][len - 2] != '1')
			return (ft_putstr_fd("Error : Map not surrounded by walls\n", 2),
				0);
		i++;
	}
	return (1);
}

int	check_map_size(char **map)
{
	size_t	i;
	size_t	len;

	i = 1;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i++]) != len)
		{
			ft_putstr_fd("Error : Map is not rectangular\n", 2);
			ft_putstr_fd("or return line missing at the end of file\n", 2);
			return (-1);
		}
	}
	if (i == len - 1)
		return (ft_putstr_fd("Error : Map is not rectangular\n", 2), -1);
	if (len > 41 || i > 22)
		return (ft_putstr_fd("Error : Map is too big\n", 2), -1);
	if (check_map_walls(map, len, i) == 0)
		return (-1);
	return (0);
}

/*****************************************************************************
count elements in the map to
check if there is only one player
check if there is only one exit
check if there is at least one collectible
*****************************************************************************/

static void	count_elem_bis(t_map *lst_map, char c, int i, int j)
{
	if (c == 'P')
	{
		lst_map->player += 1;
		lst_map->x = i;
		lst_map->y = j;
	}
	if (c == 'E')
		lst_map->exit += 1;
	if (c == 'C')
		lst_map->collectible += 1;
}

t_map	*count_elem_map(char **map)
{
	t_map	*lst_map;
	int		i;
	int		j;

	i = 0;
	lst_map = NULL;
	lst_map = malloc(sizeof(t_map));
	if (!lst_map)
		return (ft_putstr_fd("Error : Malloc\n", 2), NULL);
	init_lst_map(lst_map);
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			count_elem_bis(lst_map, map[i][j], i, j);
			j++;
		}
		i++;
	}
	lst_map->row = i;
	lst_map->col = j - 1;
	return (lst_map);
}
