/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_rules.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:57:47 by csolari           #+#    #+#             */
/*   Updated: 2025/02/18 14:55:12 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse_rotate(t_pslist **stack)
{
	t_pslist	*temp;

	temp = ft_ps_lstlast(*stack);
	ft_ps_lstpenultimate(*stack)->next = NULL;
	temp->next = *stack;
	*stack = temp;
}

void	ft_rra(t_pslist **stackA)
{
	if (!stackA || !*stackA || !(*stackA)->next)
		return ;
	ft_reverse_rotate(stackA);
}

void	ft_rrb(t_pslist **stackB)
{
	if (!stackB || !*stackB || !(*stackB)->next)
		return ;
	ft_reverse_rotate(stackB);
}

void	ft_rrr(t_pslist **stackA, t_pslist **stackB)
{
	ft_rra(stackA);
	ft_rrb(stackB);
}