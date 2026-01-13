/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:09:15 by csolari           #+#    #+#             */
/*   Updated: 2025/02/21 13:35:43 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_move_zero(t_moves *moves)
{
	moves->pa = 0;
	moves->ra = 0;
	moves->rb = 0;
	moves->rr = 0;
	moves->rra = 0;
	moves->rrb = 0;
	moves->rrr = 0;
	moves->value = 0;
	moves->count = 0;
}

static void	ft_apply(t_pslist **stack_a, t_pslist **stack_b, t_moves *cheapest)
{
	while (cheapest->ra-- > 0)
		ft_ra(stack_a, 0);
	while (cheapest->rb-- > 0)
		ft_rb(stack_b, 0);
	while (cheapest->rr-- > 0)
		ft_rr(stack_a, stack_b);
	while (cheapest->rra-- > 0)
		ft_rra(stack_a, 0);
	while (cheapest->rrb-- > 0)
		ft_rrb(stack_b, 0);
	while (cheapest->rrr-- > 0)
		ft_rrr(stack_a, stack_b);
	while (cheapest->pa-- > 0)
		ft_pa(stack_a, stack_b);
	ft_move_zero(cheapest);
}

// une fois la stack_a triee remettre le min en haut

static void	ft_up_min(t_pslist **stack_a)
{
	int	min;
	int	index;
	int	len;

	min = ft_ps_lstmin(stack_a);
	index = ft_ps_index(stack_a, min);
	len = ft_ps_lstsize(*stack_a);
	while ((*stack_a)->value != min)
	{
		if (index < len / 2)
			ft_ra(stack_a, 0);
		else
			ft_rra(stack_a, 0);
	}
}

static void	ft_each_move_count(t_pslist **stack_a, t_pslist **stack_b,
		t_moves *moves, t_moves *cheapest)
{
	t_pslist	*temp;

	temp = *stack_b;
	cheapest->value = temp->value;
	ft_count_moves(stack_a, stack_b, cheapest);
	while (temp && temp->next)
	{
		temp = temp->next;
		ft_move_zero(moves);
		moves->value = temp->value;
		ft_count_moves(stack_a, stack_b, moves);
		if (cheapest->count > moves->count)
			*cheapest = *moves;
	}
}

// une boucle d execution des movememts
// initialiser cheapest avec le premier calcul
// une boucle pour evaluer cout chaque nombre avant deplacement
// reinitialiser move
// pour chaque int de b calculer le cout pour allaer a la bonne place
// a chque count comparer avec le cheapest et remplacer si c est plus bas
// executer le moins couteux

void	ft_algo(t_pslist **stack_a, t_pslist **stack_b)
{
	t_moves	*moves;
	t_moves	*cheapest;
	int		len;

	moves = ft_calloc(1, sizeof(t_moves));
	if (!moves)
		return ;
	cheapest = ft_calloc(1, sizeof(t_moves));
	if (!cheapest)
		return (free(moves));
	len = ft_ps_lstsize(*stack_b);
	while (len-- > 0)
	{
		ft_each_move_count(stack_a, stack_b, moves, cheapest);
		ft_apply(stack_a, stack_b, cheapest);
	}
	ft_up_min(stack_a);
	free(moves);
	free(cheapest);
}

/*
// TESTS
	ft_moves_in_a(stack_a, 7, moves);
	ft_printf("\nra ; %d\n", moves->ra);
	ft_printf("rra ; %d\n", moves->rra);
	if ((*stack_b)->value == 0)
		value = 1;
*/

// ft_count_moves(stack_a, stack_b, moves);
// ft_printf("\npa :%d ", moves->pa);
// ft_printf("\nra :%d ", moves->ra);
// ft_printf("\nrb :%d ", moves->rb);
// ft_printf("\nrr :%d ", moves->rr);
// ft_printf("\nrra :%d ", moves->rra);
// ft_printf("\nrrb :%d ", moves->rrb);
// ft_printf("\nrrr :%d ", moves->rrr);
// ft_printf("\ncount :%d ", moves->count);

// ft_printf("\npa :%d ", cheapest->pa);
// ft_printf("\nra :%d ", cheapest->ra);
// ft_printf("\nrb :%d ", cheapest->rb);
// ft_printf("\nrr :%d ", cheapest->rr);
// ft_printf("\nrra :%d ", cheapest->rra);
// ft_printf("\nrrb :%d ", cheapest->rrb);
// ft_printf("\nrrr :%d ", cheapest->rrr);
// ft_printf("\ncount :%d\n ", cheapest->count);
