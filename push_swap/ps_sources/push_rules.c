/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:20:54 by csolari           #+#    #+#             */
/*   Updated: 2025/02/21 12:41:15 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_pslist **stack1, t_pslist **stack2)
{
	t_pslist	*temp;

	temp = *stack2;
	*stack2 = (*stack2)->next;
	ft_ps_lstadd_front(stack1, temp);
}

void	ft_pa(t_pslist **stack_a, t_pslist **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	ft_pb(t_pslist **stack_a, t_pslist **stack_b)
{
	ft_push(stack_b, stack_a);
	ft_printf("pb\n");
}
