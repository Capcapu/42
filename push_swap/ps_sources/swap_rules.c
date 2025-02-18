/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:19:44 by csolari           #+#    #+#             */
/*   Updated: 2025/02/07 11:19:55 by csolari          ###   ########.fr       */
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

void	ft_sa(t_pslist	**stackA)
{
	if (!stackA || !*stackA || !(*stackA)->next)
		return;
	ft_swap(stackA);
}


void	ft_sb(t_pslist	**stackB)
{
	if (!stackB || !*stackB || !(*stackB)->next)
		return;
	ft_swap(stackB);
}

void	ft_ss(t_pslist **stackA, t_pslist **stackB)
{
	ft_sa(stackA);
	ft_sb(stackB);
}