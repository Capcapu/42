/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:32:03 by csolari           #+#    #+#             */
/*   Updated: 2025/02/25 15:05:19 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_main_part_algo(t_pslist **stack_a, t_pslist **stack_b, int argc)
{
	t_value		*mv;

	if (ft_check_order(stack_a) == 1)
		return ;
	if (argc <= 4)
		ft_algo_three(stack_a, argc);
	else
	{
		mv = ft_median(stack_a);
		if (!mv)
			return ;
		ft_push_median(stack_a, stack_b, mv);
		ft_algo_three(stack_a, 4);
		ft_algo(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_pslist	**stack_a;
	t_pslist	**stack_b;

	if (ft_check_input(argc, argv) == 0)
		return (0);
	stack_a = (t_pslist **)ft_calloc(sizeof(t_pslist *), 1);
	if (!stack_a)
		return (0);
	stack_b = (t_pslist **)ft_calloc(sizeof(t_pslist *), 1);
	if (!stack_b)
		return (free(stack_a), 0);
	if (argc >= 2)
	{
		ft_parse_input(stack_a, argc, argv);
		ft_main_part_algo(stack_a, stack_b, argc);
	}
	return (ft_ps_lstfree(stack_a), ft_ps_lstfree(stack_b), 0);
}

/* 
//valgrind --leak-check=full --track-origins=yes ./push_swap 4
// pareil avec -s pour voir les erreurs
//./complexity 500 100 5500 -f ../push_swap/push_swap ../push_swap/checker_linux
./push_swap 5 2 4 6 | ./checker_linux 5 2 4 6

	// ft_print_list(stack_a, 'A');
	// ft_print_list(stack_b, 'B');
	// ft_printf("\n\n");

	ft_print_list(stack_a, 'A');
	ft_print_list(stack_b, 'B');
	ft_printf("\n\n");

	// ft_print_list(stack_a, 'A');
	// ft_print_list(stack_b, 'B');
	ft_pb(stack_a, stack_b);
	ft_pb(stack_a, stack_b);
	ft_printf("\n\n");
	ft_print_list(stack_a, 'A');
	ft_print_list(stack_b, 'B');
	//ft_ra(stack_a);
	ft_printf("\n\n");
	ft_printf("%d  : tri stack_a\n",ft_check_order_decr(stack_a));
	ft_printf("%d  : tri stack_b\n", ft_check_order_decr(stack_b));
	return (0); */

	// 	ft_printf("%d  : tri stack_a\n",ft_check_order(stack_a));
	// ft_printf("%d  : tri stack_b\n", ft_check_order(stack_b));

	// ./push_swap 5 2 4 6 | ./checker_linux 5 2 4 6
	// ./push_swap 5 2 4 6 | wc -l