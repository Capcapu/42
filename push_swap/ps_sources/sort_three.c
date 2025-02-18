/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:17:44 by csolari           #+#    #+#             */
/*   Updated: 2025/02/17 11:35:56 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_pslist **stack)
{
	if (ft_check_order(stack) == 0)
		ft_sa(stack);
}
// ft_sort_three


void	ft_algo_three(t_pslist **stackA, int argc)
{
	int	a;
	int	b;
	int	c;

	if (argc == 3)
		ft_sort_two(stackA);
	else
	{
		a = (*stackA)->value;
		b = (*stackA)->next->value;
		c = (*stackA)->next->next->value;

		if (a > c && b < c && c < a)
			ft_ra(stackA);
		if (a < b && b > c && c < a)
			ft_rra(stackA);
		if (a < b && b > c && c > a)
		{
			ft_rra(stackA);
			ft_sa(stackA);
		}
		if (a > b && b < c && c > a)
			ft_sa(stackA);
		if (a > b && b > c && c < a)
		{
			ft_ra(stackA);
			ft_sa(stackA);
		}
	}
}
