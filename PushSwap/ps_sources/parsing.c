/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:20:12 by csolari           #+#    #+#             */
/*   Updated: 2025/02/25 14:58:14 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parse_input(t_pslist **lst, int argc, char **argv)
{
	int			i;
	t_pslist	*temp;

	i = 1;
	while (i < argc)
	{
		temp = ft_ps_lstnew(ft_atoi(argv[i]));
		if (!temp)
			return (ft_ps_lstfree(lst));
		ft_ps_lstadd_back(lst, temp);
		i++;
	}
}
