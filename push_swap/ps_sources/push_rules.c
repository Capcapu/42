/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:20:54 by csolari           #+#    #+#             */
/*   Updated: 2025/02/13 13:35:12 by csolari          ###   ########.fr       */
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

void	ft_pa(t_pslist **stackA, t_pslist **stackB)
{
	ft_push(stackA, stackB);
}

void	ft_pb(t_pslist **stackA, t_pslist **stackB)
{
	ft_push(stackB, stackA);
}