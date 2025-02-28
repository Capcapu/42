/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_rules.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:57:47 by csolari           #+#    #+#             */
/*   Updated: 2025/02/21 13:08:58 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse_rotate(t_pslist **stack)
{
	t_pslist	*temp;

	if (ft_ps_lstsize(*stack) < 2)
		return ;
	temp = ft_ps_lstlast(*stack);
	ft_ps_lstpenultimate(*stack)->next = NULL;
	temp->next = *stack;
	*stack = temp;
}

void	ft_rra(t_pslist **stack_a, int quiet)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	ft_reverse_rotate(stack_a);
	if (quiet == 0)
		ft_printf("rra\n");
}

void	ft_rrb(t_pslist **stack_b, int quiet)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	ft_reverse_rotate(stack_b);
	if (quiet == 0)
		ft_printf("rrb\n");
}

void	ft_rrr(t_pslist **stack_a, t_pslist **stack_b)
{
	ft_rra(stack_a, 1);
	ft_rrb(stack_b, 1);
	ft_printf("rrr\n");
}
