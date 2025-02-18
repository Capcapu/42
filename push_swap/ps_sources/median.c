/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:11:21 by csolari           #+#    #+#             */
/*   Updated: 2025/02/17 14:59:52 by csolari          ###   ########.fr       */
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

t_value	*ft_median(t_pslist **stackA, t_pslist **stackB)
{
	t_value		*mv;
	int			i;
	t_pslist	*temp;

	temp = *stackA;
	mv = (t_value *)malloc(sizeof(t_value));
	if (!mv)
		return(ft_error_stack(stackA, stackB), NULL);
	mv->len = ft_ps_lstsize(*stackA);
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
		mv->median = (mv->cpy_tab[mv->len / 2 - 1] + mv->cpy_tab[mv->len / 2]) / 2;
	else
		mv->median = mv->cpy_tab[mv->len / 2];
	mv->min = mv->cpy_tab[0];
	mv->max = mv->cpy_tab[mv->len - 1];
	return (free(mv->cpy_tab), mv);
}

void	ft_push_median(t_pslist **stackA, t_pslist **stackB, t_value *mv)
{
	int	med;
	int	len;

	med = mv->median;
	len = mv->len;
	while(len > 3)
	{
		if ((*stackA)->value <= med)
		{
			ft_pb(stackA, stackB);
			ft_printf("pb\n");
		}
		else
		{
			ft_pb(stackA, stackB);
			ft_rb(stackB);
			ft_printf("pb\nrb\n");
		}
		len--;
	}
}


	// while(mv->cpy_tab[i])
	// {
	// 	printf("%d\n", mv->cpy_tab[i]);
	// 	i++;
	// }

		// ft_printf("min ;%d", mv->min);
	// ft_printf("max ; %d", mv->max);