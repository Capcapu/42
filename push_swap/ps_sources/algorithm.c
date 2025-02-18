/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:09:15 by csolari           #+#    #+#             */
/*   Updated: 2025/02/18 15:06:22 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algo(t_pslist **stackA, t_pslist **stackB)
{
	t_moves	*moves;
	t_moves	*cheapest;
	//int		value;
	t_pslist	*temp;

	moves = ft_calloc(1, sizeof(t_moves));
	cheapest = ft_calloc(1, sizeof(t_moves));
	temp = *stackB;
	cheapest->value = 5 ; //temp->value;
	ft_count_moves(stackA, stackB, cheapest);
	//while (lenstackB) une boucle d execution des move'emts
	// {
	// 	while (temp->next) //une boucle pour evaluer cout chaque nombre avant deplacement
	// 	{
	// 		temp=temp->next;
	// 		value = temp->value;
	// 		//check order avant tout
	// 		reinitialiser move
	// 		moves->value = value;
	// 		//pour chaque int de b calculer le cout pour allaer a la bonne place
	// 		// initialiser cheapest avec le premier calcul
	// 		// a chque count comparer avec le cheapest et remplacer si c est plus bas
	// 	}
	// 		//executer le moins couteux
	// }

	// ft_count_moves(stackA, stackB, moves);
	// ft_printf("\npa :%d ", moves->pa);
	// ft_printf("\nra :%d ", moves->ra);
	// ft_printf("\nrb :%d ", moves->rb);
	// ft_printf("\nrr :%d ", moves->rr);
	// ft_printf("\nrra :%d ", moves->rra);
	// ft_printf("\nrrb :%d ", moves->rrb);
	// ft_printf("\nrrr :%d ", moves->rrr);
	// ft_printf("\ncount :%d ", moves->count);


	ft_printf("\npa :%d ", cheapest->pa);
	ft_printf("\nra :%d ", cheapest->ra);
	ft_printf("\nrb :%d ", cheapest->rb);
	ft_printf("\nrr :%d ", cheapest->rr);
	ft_printf("\nrra :%d ", cheapest->rra);
	ft_printf("\nrrb :%d ", cheapest->rrb);
	ft_printf("\nrrr :%d ", cheapest->rrr);
	ft_printf("\ncount :%d ", cheapest->count);


	ft_apply(stackA, stackB, cheapest);

	ft_printf("\npa :%d ", cheapest->pa);
	ft_printf("\nra :%d ", cheapest->ra);
	ft_printf("\nrb :%d ", cheapest->rb);
	ft_printf("\nrr :%d ", cheapest->rr);
	ft_printf("\nrra :%d ", cheapest->rra);
	ft_printf("\nrrb :%d ", cheapest->rrb);
	ft_printf("\nrrr :%d ", cheapest->rrr);
	ft_printf("\ncount :%d ", cheapest->count);

	free(moves);
	free(cheapest);
}

void	ft_apply(t_pslist **stackA, t_pslist **stackB, t_moves *cheapest)
{
	while (cheapest->ra > 0)
	{
		ft_ra(stackA);
		cheapest->ra -= 1;
		ft_print_list(stackA, 'A');
		ft_print_list(stackB, 'B');
		ft_printf("\n\n");
	}
	while (cheapest->rb > 0)
	{
		ft_rb(stackB);
		cheapest->rb -= 1;
	}
	while (cheapest->rr > 0)
	{
		ft_rr(stackA, stackB);
		cheapest->rr -= 1;
	}
	while (cheapest->rra > 0)
	{
		ft_rra(stackA);
		cheapest->rra -= 1;
	}
	while (cheapest->rrb > 0)
	{
		ft_rrb(stackB);
		cheapest->rrb -= 1;
		ft_print_list(stackA, 'A');
		ft_print_list(stackB, 'B');
		ft_printf("\n\n");
	}
	while (cheapest->rrr > 0)
	{
		ft_rrr(stackA, stackB);
		cheapest->rrr -= 1;
	}
	while (cheapest->pa > 0)
	{
		ft_pa(stackA, stackB);
		cheapest->pa -= 1;
	}
}


	/*
	// TESTS
		ft_moves_in_a(stackA, 7, moves);
		ft_printf("\nra ; %d\n", moves->ra);
		ft_printf("rra ; %d\n", moves->rra);
		if ((*stackB)->value == 0)
			value = 1;
	*/
