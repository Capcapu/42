/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:37:49 by csolari           #+#    #+#             */
/*   Updated: 2025/04/08 12:24:44 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*****************************************************************************
check if there is only one player
check if there is only one exit
check if there is at least one collectible
check if the map is solvable
*****************************************************************************/

static int	check_player_exit_col(t_map *lst_map)
{
	if (lst_map->player != 1)
	{
		ft_putstr_fd("Error : Invalid map, too many or no player\n", 2);
		free(lst_map);
		return (0);
	}
	if (lst_map->exit != 1)
	{
		ft_putstr_fd("Error : Invalid map, too many or no exit\n", 2);
		free(lst_map);
		return (0);
	}
	if (lst_map->collectible == 0)
	{
		ft_putstr_fd("Error : Invalid map, no collectible\n", 2);
		free(lst_map);
		return (0);
	}
	return (1);
}

static int	check_solvability_bis(char **temp_map, t_map *lst_map, char **map)
{
	t_map	*lst_temp_map;
	int		i;

	i = 0;
	while (i < lst_map->row)
	{
		temp_map[i] = ft_strdup(map[i]);
		if (!temp_map[i])
		{
			while (i-- > 0)
				free(temp_map[i]);
			ft_free_tab(temp_map);
			return (free(lst_map), ft_putstr_fd("Error : Malloc\n", 2), 0);
		}
		i++;
	}
	flood_fill(temp_map, lst_map, lst_map->x, lst_map->y);
	lst_temp_map = count_elem_map(temp_map);
	if (!lst_temp_map)
		return (0);
	if (lst_temp_map->exit != 0 || lst_temp_map->collectible != 0)
		return (free(lst_temp_map), ft_putstr_fd("Error : Map not solvable\n",
				2), 0);
	return (free(lst_temp_map), 1);
}

t_map	*check_solvability_map(char **map)
{
	t_map	*lst_map;
	char	**temp_map;

	lst_map = count_elem_map(map);
	if (!lst_map)
		return (NULL);
	if (check_player_exit_col(lst_map) == 0)
		return (NULL);
	temp_map = ft_calloc(lst_map->row + 1, sizeof(char *));
	if (!temp_map)
		return (free(lst_map), ft_putstr_fd("Error : Malloc\n", 2), NULL);
	if (check_solvability_bis(temp_map, lst_map, map) == 0)
		return (ft_free_tab(temp_map), free(lst_map), NULL);
	return (ft_free_tab(temp_map), lst_map);
}
