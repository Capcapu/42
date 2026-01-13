/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:11:21 by csolari           #+#    #+#             */
/*   Updated: 2025/02/21 16:05:44 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

static void	order_tab(int *tab, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (tab[i] > tab[j])
				swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}

t_value	*ft_median(t_pslist **stack_a)
{
	t_value		*mv;
	int			i;
	t_pslist	*temp;

	temp = *stack_a;
	mv = (t_value *)malloc(sizeof(t_value));
	if (!mv)
		return (NULL);
	mv->len = ft_ps_lstsize(*stack_a);
	i = 0;
	mv->cpy_tab = (int *)malloc(sizeof(int) * mv->len);
	while (temp)
	{
		mv->cpy_tab[i] = temp->value;
		temp = temp->next;
		i++;
	}
	order_tab(mv->cpy_tab, mv->len);
	if (mv->len % 2 == 0)
		mv->median = (mv->cpy_tab[mv->len / 2 - 1] + mv->cpy_tab[mv->len / 2])
			/ 2;
	else
		mv->median = mv->cpy_tab[mv->len / 2];
	return (free(mv->cpy_tab), mv);
}

void	ft_push_median(t_pslist **stack_a, t_pslist **stack_b, t_value *mv)
{
	int	med;
	int	len;

	med = mv->median;
	len = mv->len;
	while (len > 3)
	{
		if ((*stack_a)->value <= med)
			ft_pb(stack_a, stack_b);
		else
		{
			ft_pb(stack_a, stack_b);
			ft_rb(stack_b, 0);
		}
		len--;
	}
	free(mv);
}

// while(mv->cpy_tab[i])
// {
// 	printf("%d\n", mv->cpy_tab[i]);
// 	i++;
// }