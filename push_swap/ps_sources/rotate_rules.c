/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:58:34 by csolari           #+#    #+#             */
/*   Updated: 2025/02/18 14:29:05 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_pslist **stack)
{
	t_pslist	*temp;

	if (ft_ps_lstsize(*stack) < 2)
		return;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	ft_ps_lstadd_back(stack, temp);

}

void	ft_ra(t_pslist **stackA)
{
	if (!stackA || !*stackA || !(*stackA)->next)
		return;
	ft_rotate(stackA);
}

void	ft_rb(t_pslist **stackB)
{
	if (!stackB || !*stackB || !(*stackB)->next)
		return;
	ft_rotate(stackB);
}

void	ft_rr(t_pslist **stackA, t_pslist **stackB)
{
	ft_ra(stackA);
	ft_rb(stackB);
}
