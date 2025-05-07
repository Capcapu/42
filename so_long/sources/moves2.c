/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:20:05 by csolari           #+#    #+#             */
/*   Updated: 2025/04/08 12:00:16 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	keypress
	65307	-Echap
	119		-W
	97		-A
	115		-S
	100		-D
	65362	-Fleche haut
	65361	-Fleche gauche
	65364	-Fleche bas
	65363	-Fleche droite
*/
int	key_press(int keypress, t_context *context)
{
	int	state;

	state = 1;
	if (!context || !context->map || !context->map_struct)
	{
		ft_putstr_fd("Error: Context or map not initialized\n", 2);
		return (1);
	}
	if (keypress == 65307)
		state = 0;
	else if (keypress == 119 || keypress == 65362)
		state = go_up(context);
	else if (keypress == 97 || keypress == 65361)
		state = go_left(context);
	else if (keypress == 115 || keypress == 65364)
		state = go_down(context);
	else if (keypress == 100 || keypress == 65363)
		state = go_right(context);
	if (state == 0)
		mlx_loop_end(context->mlx);
	else
		display_map(context);
	return (0);
}

int	close_window(t_context *context)
{
	mlx_loop_end(context->mlx);
	return (0);
}
