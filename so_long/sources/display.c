/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:10:14 by csolari           #+#    #+#             */
/*   Updated: 2025/04/08 15:33:55 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_context	*init_context(t_map *map_struct)
{
	void		*mlx;
	void		*win;
	t_context	*contx;

	contx = NULL;
	contx = malloc(sizeof(t_context));
	if (!contx)
		return (ft_putstr_fd("Error : Malloc\n", 2), NULL);
	init_lst_context(contx);
	mlx = mlx_init();
	if (!mlx)
		return (ft_putstr_fd("Error Mlx\n", 2), free(contx), NULL);
	win = mlx_new_window(mlx, map_struct->col * 64, map_struct->row * 64,
			"* LET'S PLAYYYYYYY *");
	if (!win)
		return (ft_putstr_fd("Error Win\n", 2), free(mlx), free(contx), NULL);
	(*contx).mlx = mlx;
	(*contx).win = win;
	contx->map_struct = map_struct;
	if (init_lst_exit(contx) == 0 || init_lst_ground(contx) == 0
		|| init_lst_player(contx) == 0 || init_lst_wall(contx) == 0
		|| init_lst_collec(contx) == 0)
		return (NULL);
	(*contx).nb_moves = 0;
	return (contx);
}

void	display_map_bis(t_context *contx, int i, int j)
{
	if (contx->map[i][j] == '1')
		mlx_put_image_to_window(contx->mlx, contx->win, contx->wall->img, j
			* 64, i * 64);
	else if (contx->map[i][j] == '0')
		mlx_put_image_to_window(contx->mlx, contx->win, contx->ground->img, j
			* 64, i * 64);
	else if (contx->map[i][j] == 'C')
		mlx_put_image_to_window(contx->mlx, contx->win, contx->collectible->img,
			j * 64, i * 64);
	else if (contx->map[i][j] == 'E')
		mlx_put_image_to_window(contx->mlx, contx->win, contx->exit->img, j
			* 64, i * 64);
	else if (contx->map[i][j] == 'P')
		mlx_put_image_to_window(contx->mlx, contx->win, contx->player->img, j
			* 64, i * 64);
}

void	display_map(t_context *contx)
{
	int	i;
	int	j;

	i = 0;
	while (contx->map[i])
	{
		j = 0;
		while (contx->map[i][j])
		{
			display_map_bis(contx, i, j);
			j++;
		}
		i++;
	}
}
