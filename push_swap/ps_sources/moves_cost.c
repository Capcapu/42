/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:28:51 by csolari           #+#    #+#             */
/*   Updated: 2025/02/18 13:35:31 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// FT_COUNT_MOVES
// pour 1 chiffre de stack B evaluer son cout
// moves stack b rb et rrb
// moves stack a bonne place, trouver place devant le max superieur
// push dans a, pa = 1 de toute facon
// combiner les ra rb avec rr et rra rrb avec rrr

void	ft_count_moves(t_pslist **stackA, t_pslist **stackB, t_moves *moves)
{
	ft_moves_in_b(stackB, moves->value, moves);
	ft_moves_in_a(stackA, moves->value, moves);
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

void	ft_moves_in_b(t_pslist **stackB, int value, t_moves *moves)
{
	t_pslist	**temp;
	int			len;
	int			index;

	temp = stackB;
	len = ft_ps_lstsize(*stackB);
	index = ft_ps_index(stackB, value);
	while ((*temp)->value != value)
	{
		if (index < (len / 2))
		{
			ft_rb(temp);
			moves->rb += 1;
		}
		else
		{
			ft_rrb(temp);
			moves->rrb += 1;
		}
	}
}

static void	ft_moves_in_a_bis(t_pslist **temp, t_moves *moves, int num,
		int where)
{
	int	index;
	int	size;

	size = ft_ps_lstsize(*temp);
	index = ft_ps_index(temp, num);
	while (index != where)
	{
		if (index < (size / 2) + 1)
		{
			ft_ra(temp);
			moves->ra += 1;
		}
		else
		{
			ft_rra(temp);
			moves->rra += 1;
		}
		index = ft_ps_index(temp, num);
	}
}

void	ft_moves_in_a(t_pslist **stackA, int value, t_moves *moves)
{
	int			maxA;
	t_pslist	**temp;
	int			len;

	maxA = ft_ps_lstmax(stackA);
	temp = stackA;
	len = ft_ps_lstsize(*stackA);
	if (value > maxA)
		ft_moves_in_a_bis(temp, moves, maxA, len - 1);
	else
		ft_moves_in_a_bis(temp, moves, ft_firstsup(temp, value), 0);
}
