/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:30:52 by csolari           #+#    #+#             */
/*   Updated: 2025/02/18 13:44:12 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/includes/libft.h"


int		ft_check_input(int argc, char **argv);
void	ft_parse_str(char **argv);
void	ft_parse_input(t_pslist **lst, int argc, char **argv);

void	ft_sa(t_pslist	**stackA);
void	ft_sb(t_pslist	**stackB);
void	ft_ss(t_pslist **stackA, t_pslist **stackB);
void	ft_pa(t_pslist **stackA, t_pslist **stackB);
void	ft_pb(t_pslist **stackA, t_pslist **stackB);
void	ft_ra(t_pslist **stackA);
void	ft_rb(t_pslist **stackB);
void	ft_rr(t_pslist **stackA, t_pslist **stackB);
void	ft_rra(t_pslist **stackA);
void	ft_rrb(t_pslist **stackB);
void	ft_rrr(t_pslist **stackA, t_pslist **stackB);

int		ft_check_order(t_pslist **stack);
int		ft_check_order_decr(t_pslist **stack);

t_value	*ft_median(t_pslist **stackA, t_pslist **stackB);

void	ft_push_median(t_pslist **stackA, t_pslist **stackB, t_value *mv);
void	ft_sort_two(t_pslist **stack);
void	ft_algo_three(t_pslist **stackA, int argc);

void	ft_algo(t_pslist **stackA, t_pslist **stackB);

void	ft_error_stack(t_pslist **stackA, t_pslist **stackB);

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

void	ft_moves_in_b(t_pslist **stackB, int value, t_moves *moves);
void	ft_moves_in_a(t_pslist **stackA, int value, t_moves *moves);
void	ft_count_moves(t_pslist **stackA, t_pslist **stackB, t_moves *moves);
void	ft_apply(t_pslist **stackA, t_pslist **stackB, t_moves *cheapest);

#endif
