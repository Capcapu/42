/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:58:34 by csolari           #+#    #+#             */
/*   Updated: 2025/02/21 16:29:10 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_pslist **stack)
{
	t_pslist	*temp;

	if (!stack || !*stack || ft_ps_lstsize(*stack) < 2)
		return ;
	temp = *stack;
	*stack = temp->next;
	temp->next = NULL;
	ft_ps_lstadd_back(stack, temp);
}

void	ft_ra(t_pslist **stack_a, int quiet)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	ft_rotate(stack_a);
	if (quiet == 0)
		ft_printf("ra\n");
}

void	ft_rb(t_pslist **stack_b, int quiet)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	ft_rotate(stack_b);
	if (quiet == 0)
		ft_printf("rb\n");
}

void	ft_rr(t_pslist **stack_a, t_pslist **stack_b)
{
	ft_ra(stack_a, 1);
	ft_rb(stack_b, 1);
	ft_printf("rr\n");
}
