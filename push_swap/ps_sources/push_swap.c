/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:32:03 by csolari           #+#    #+#             */
/*   Updated: 2025/02/18 14:09:04 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int argc, char **argv)
{
	t_pslist	**stackA;
	t_pslist	**stackB;
	t_value		*mv;
	int	i;

	i = 1;
	if (argc == 2)
		ft_parse_str(argv);
	while (argv[i])
		i++;
	argc = i;
	stackA = (t_pslist **)malloc(sizeof(t_pslist *));
	if (!stackA)
		return (0);
	stackB = (t_pslist **)malloc(sizeof(t_pslist *));
	if (!stackB)
		return(0);
	if (ft_check_input(argc, argv) == 0)
		return (0);
	// ft_printf("hey c tout ok\n");

	if (argc >= 2)
	{
		ft_parse_input(stackA, argc, argv);
		
		ft_print_list(stackA, 'A');
		ft_print_list(stackB, 'B');
		ft_printf("\n\n");

		if (argc <= 4)
			ft_algo_three(stackA, argc);
		else
		{
			mv = ft_median(stackA, stackB);
			ft_push_median(stackA, stackB, mv);
			ft_algo_three(stackA, 4);

			ft_print_list(stackA, 'A');
			ft_print_list(stackB, 'B');
			ft_printf("\n\n");

			ft_algo(stackA, stackB);
		}

	
	ft_print_list(stackA, 'A');
	ft_print_list(stackB, 'B');
	ft_printf("\n\n");

	}
	return (0);
}
/* 
//valgrind --leak-check=full --track-origins=yes ./push_swap 4
./push_swap 5 2 4 6 | ./checker_linux 5 2 4 6



	ft_print_list(stackA, 'A');
	ft_print_list(stackB, 'B');
	ft_printf("\n\n");


	ft_print_list(stackA, 'A');
	ft_print_list(stackB, 'B');
	ft_printf("\n\n");






	// ft_print_list(stackA, 'A');
	// ft_print_list(stackB, 'B');
	ft_pb(stackA, stackB);
	ft_pb(stackA, stackB);
	ft_printf("\n\n");
	ft_print_list(stackA, 'A');
	ft_print_list(stackB, 'B');
	//ft_ra(stackA);
	ft_printf("\n\n");
	ft_printf("%d  : tri stackA\n",ft_check_order_decr(stackA));
	ft_printf("%d  : tri stackB\n", ft_check_order_decr(stackB));
	return (0); */

	// 	ft_printf("%d  : tri stackA\n",ft_check_order(stackA));
	// ft_printf("%d  : tri stackB\n", ft_check_order(stackB));


