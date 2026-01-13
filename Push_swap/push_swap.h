/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:30:52 by csolari           #+#    #+#             */
/*   Updated: 2025/02/25 14:58:28 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/includes/libft.h"

int		ft_check_input(int argc, char **argv);
void	ft_parse_input(t_pslist **lst, int argc, char **argv);

void	ft_sa(t_pslist	**stack_a, int quiet);
void	ft_sb(t_pslist	**stack_b, int quiet);
void	ft_ss(t_pslist **stack_a, t_pslist **stack_b);
void	ft_pa(t_pslist **stack_a, t_pslist **stack_b);
void	ft_pb(t_pslist **stack_a, t_pslist **stack_b);
void	ft_ra(t_pslist **stack_a, int quiet);
void	ft_rb(t_pslist **stack_b, int quiet);
void	ft_rr(t_pslist **stack_a, t_pslist **stack_b);
void	ft_rra(t_pslist **stack_a, int quiet);
void	ft_rrb(t_pslist **stack_b, int quiet);
void	ft_rrr(t_pslist **stack_a, t_pslist **stack_b);

int		ft_check_order(t_pslist **stack);
int		ft_check_order_decr(t_pslist **stack);

t_value	*ft_median(t_pslist **stack_a);

void	ft_push_median(t_pslist **stack_a, t_pslist **stack_b, t_value *mv);
void	ft_sort_two(t_pslist **stack);
void	ft_algo_three(t_pslist **stack_a, int argc);

void	ft_algo(t_pslist **stack_a, t_pslist **stack_b);

typedef struct s_moves
{
	int		pa;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		value;
	int		count;
}			t_moves;

void	ft_count_moves(t_pslist **stack_a, t_pslist **stack_b, t_moves *moves);

#endif
