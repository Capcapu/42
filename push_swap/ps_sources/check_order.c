/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:09:51 by csolari           #+#    #+#             */
/*   Updated: 2025/02/11 12:30:12 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_order(t_pslist **stack)
{
	t_pslist	*temp;

	if (!(*stack) || !stack)
		return (-1);
	temp = *stack;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	ft_check_order_decr(t_pslist **stack)
{
	t_pslist	*temp;

	if (!(*stack) || !stack)
		return (-1);
	temp = *stack;
	while (temp->next)
	{
		if (temp->value < temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}