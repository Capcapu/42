/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:20:18 by csolari           #+#    #+#             */
/*   Updated: 2025/04/08 15:39:20 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char		**map;
	t_context	*context;
	t_map		*map_struct;

	if (argc != 2)
		return (ft_putstr_fd("Error : Wrong number of arguments\n", 2), 1);
	map = parsing_map(argv);
	if (!map)
		return (1);
	if (check_map_size(map) == -1)
		return (ft_free_tab(map), 1);
	map_struct = check_solvability_map(map);
	if (!map_struct)
		return (ft_free_tab(map), 1);
	context = init_context(map_struct);
	if (!context)
		return (ft_free_tab(map), 1);
	(*context).map = map;
	display_map(context);
	mlx_key_hook((*context).win, key_press, context);
	mlx_hook(context->win, 17, 0, close_window, context);
	mlx_loop(context->mlx);
	ft_free_context(context);
	return (0);
}
