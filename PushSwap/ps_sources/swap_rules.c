/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:19:44 by csolari           #+#    #+#             */
/*   Updated: 2025/02/21 13:09:33 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_pslist **stack)
{
	t_pslist	*temp1;
	t_pslist	*temp2;

	temp1 = *stack;
	temp2 = (*stack)->next;
	temp1->next = temp2->next;
	temp2->next = temp1;
	*stack = temp2;
}

void	ft_sa(t_pslist **stack_a, int quiet)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	ft_swap(stack_a);
	if (quiet == 0)
		ft_printf("sa\n");
}

void	ft_sb(t_pslist **stack_b, int quiet)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	ft_swap(stack_b);
	if (quiet == 0)
		ft_printf("sb\n");
}

void	ft_ss(t_pslist **stack_a, t_pslist **stack_b)
{
	ft_sa(stack_a, 1);
	ft_sb(stack_b, 1);
	ft_printf("ss\n");
}
