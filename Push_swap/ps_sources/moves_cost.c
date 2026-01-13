/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:28:51 by csolari           #+#    #+#             */
/*   Updated: 2025/02/21 16:02:07 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// FT_COUNT_MOVES
// pour 1 chiffre de stack B evaluer son cout
// moves stack b rb et rrb
// moves stack a bonne place, trouver place devant le max superieur
// push dans a, pa = 1 de toute facon
// combiner les ra rb avec rr et rra rrb avec rrr

static void	ft_moves_in_b(t_pslist **stack_b, int value, t_moves *moves)
{
	t_pslist	*temp;
	int			len;
	int			index;

	temp = *stack_b;
	len = ft_ps_lstsize(*stack_b);
	index = ft_ps_index(stack_b, value);
	while (index != 0)
	{
		if (index < (len / 2))
		{
			index--;
			moves->rb += 1;
		}
		else
		{
			index++;
			moves->rrb += 1;
			if (index == len)
				index = 0;
		}
	}
}

static void	ft_moves_in_a_bis(t_pslist *temp, t_moves *moves, int num)
{
	int	index;
	int	size;

	size = ft_ps_lstsize(temp);
	index = ft_ps_index(&temp, num);
	if (index < size / 2)
		moves->ra = index;
	else
		moves->rra = size - index;
}

static void	ft_moves_in_a_max(t_pslist *temp, t_moves *moves, int max)
{
	int	index;
	int	size;

	size = ft_ps_lstsize(temp);
	index = ft_ps_index(&temp, max);
	if (index < size / 2)
		moves->ra = index + 1;
	else
		moves->rra = size - index - 1;
}

static void	ft_moves_in_a(t_pslist **stack_a, int value, t_moves *moves)
{
	int			max_a;
	t_pslist	*temp;
	int			len;

	max_a = ft_ps_lstmax(stack_a);
	temp = *stack_a;
	len = ft_ps_lstsize(*stack_a);
	if (value > max_a)
		ft_moves_in_a_max(temp, moves, max_a);
	else
		ft_moves_in_a_bis(temp, moves, ft_firstsup(&temp, value));
}

void	ft_count_moves(t_pslist **stack_a, t_pslist **stack_b, t_moves *moves)
{
	ft_moves_in_b(stack_b, moves->value, moves);
	ft_moves_in_a(stack_a, moves->value, moves);
	while (moves->ra > 0 && moves->rb > 0)
	{
		moves->ra -= 1;
		moves->rb -= 1;
		moves->rr += 1;
	}
	while (moves->rra > 0 && moves->rrb > 0)
	{
		moves->rra -= 1;
		moves->rrb -= 1;
		moves->rrr += 1;
	}
	moves->pa = 1;
	moves->count = moves->pa + moves->ra + moves->rb + moves->rr + moves->rra
		+ moves->rrb + moves->rrr;
}
