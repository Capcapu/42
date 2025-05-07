/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:33:26 by csolari           #+#    #+#             */
/*   Updated: 2025/04/04 16:40:40 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_count_moves(t_context *context)
{
	context->nb_moves++;
	ft_printf("\rnumber of moves = %d", context->nb_moves);
}

int	go_up(t_context *cont)
{
	cont->map_struct->x--;
	if (cont->map[cont->map_struct->x][cont->map_struct->y] == 'C')
	{
		cont->map[cont->map_struct->x + 1][cont->map_struct->y] = '0';
		cont->map[cont->map_struct->x][cont->map_struct->y] = 'P';
		cont->map_struct->collectible--;
		print_count_moves(cont);
	}
	else if (cont->map[cont->map_struct->x][cont->map_struct->y] == 'E'
		&& cont->map_struct->collectible == 0)
	{
		cont->map[cont->map_struct->x + 1][cont->map_struct->y] = '0';
		print_count_moves(cont);
		ft_printf("\nCongratulation!! you won the game :)))\n");
		return (0);
	}
	else if (cont->map[cont->map_struct->x][cont->map_struct->y] == '0')
	{
		cont->map[cont->map_struct->x + 1][cont->map_struct->y] = '0';
		cont->map[cont->map_struct->x][cont->map_struct->y] = 'P';
		print_count_moves(cont);
	}
	else
		cont->map_struct->x++;
	return (1);
}

int	go_left(t_context *cont)
{
	cont->map_struct->y--;
	if (cont->map[cont->map_struct->x][cont->map_struct->y] == 'C')
	{
		cont->map[cont->map_struct->x][cont->map_struct->y + 1] = '0';
		cont->map[cont->map_struct->x][cont->map_struct->y] = 'P';
		cont->map_struct->collectible--;
		print_count_moves(cont);
	}
	else if (cont->map[cont->map_struct->x][cont->map_struct->y] == 'E'
		&& cont->map_struct->collectible == 0)
	{
		cont->map[cont->map_struct->x][cont->map_struct->y + 1] = '0';
		print_count_moves(cont);
		ft_printf("\nCongratulation!! you won the game :)))\n");
		return (0);
	}
	else if (cont->map[cont->map_struct->x][cont->map_struct->y] == '0')
	{
		cont->map[cont->map_struct->x][cont->map_struct->y + 1] = '0';
		cont->map[cont->map_struct->x][cont->map_struct->y] = 'P';
		print_count_moves(cont);
	}
	else
		cont->map_struct->y++;
	return (1);
}

int	go_down(t_context *cont)
{
	cont->map_struct->x++;
	if (cont->map[cont->map_struct->x][cont->map_struct->y] == 'C')
	{
		cont->map[cont->map_struct->x - 1][cont->map_struct->y] = '0';
		cont->map[cont->map_struct->x][cont->map_struct->y] = 'P';
		cont->map_struct->collectible--;
		print_count_moves(cont);
	}
	else if (cont->map[cont->map_struct->x][cont->map_struct->y] == 'E'
		&& cont->map_struct->collectible == 0)
	{
		cont->map[cont->map_struct->x - 1][cont->map_struct->y] = '0';
		print_count_moves(cont);
		ft_printf("\nCongratulation!! you won the game :)))\n");
		return (0);
	}
	else if (cont->map[cont->map_struct->x][cont->map_struct->y] == '0')
	{
		cont->map[cont->map_struct->x - 1][cont->map_struct->y] = '0';
		cont->map[cont->map_struct->x][cont->map_struct->y] = 'P';
		print_count_moves(cont);
	}
	else
		cont->map_struct->x--;
	return (1);
}

int	go_right(t_context *cont)
{
	cont->map_struct->y++;
	if (cont->map[cont->map_struct->x][cont->map_struct->y] == 'C')
	{
		cont->map[cont->map_struct->x][cont->map_struct->y - 1] = '0';
		cont->map[cont->map_struct->x][cont->map_struct->y] = 'P';
		cont->map_struct->collectible--;
		print_count_moves(cont);
	}
	else if (cont->map[cont->map_struct->x][cont->map_struct->y] == 'E'
		&& cont->map_struct->collectible == 0)
	{
		cont->map[cont->map_struct->x][cont->map_struct->y - 1] = '0';
		print_count_moves(cont);
		ft_printf("\nCongratulation!! you won the game :)))\n");
		return (0);
	}
	else if (cont->map[cont->map_struct->x][cont->map_struct->y] == '0')
	{
		cont->map[cont->map_struct->x][cont->map_struct->y - 1] = '0';
		cont->map[cont->map_struct->x][cont->map_struct->y] = 'P';
		print_count_moves(cont);
	}
	else
		cont->map_struct->y--;
	return (1);
}
