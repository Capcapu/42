/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:17:44 by csolari           #+#    #+#             */
/*   Updated: 2025/02/21 15:02:55 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_pslist **stack)
{
	if (ft_check_order(stack) == 0)
	{
		ft_sa(stack, 0);
	}
}

static void	ft_move_three(t_pslist **stack_a, int a, int b, int c)
{
	if (a > b && b < c && c < a)
		ft_ra(stack_a, 0);
	else if (a < b && c < a)
		ft_rra(stack_a, 0);
	else if (a < c && c < b)
	{
		ft_rra(stack_a, 0);
		ft_sa(stack_a, 0);
	}
	else if (a > b && c > a)
		ft_sa(stack_a, 0);
	else if (a > b && b > c)
	{
		ft_sa(stack_a, 0);
		ft_ra(stack_a, 0);
	}
}

void	ft_algo_three(t_pslist **stack_a, int argc)
{
	int	a;
	int	b;
	int	c;

	if (argc == 3)
		ft_sort_two(stack_a);
	else
	{
		a = (*stack_a)->value;
		b = (*stack_a)->next->value;
		c = (*stack_a)->next->next->value;
		ft_move_three(stack_a, a, b, c);
	}
}
