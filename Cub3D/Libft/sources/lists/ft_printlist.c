/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:45:40 by csolari           #+#    #+#             */
/*   Updated: 2025/10/17 12:49:48 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printlist(t_list **lst)
{
	t_list	*temp;

	temp = *lst;
	ft_printf("\n-------\n");
	while (temp)
	{
		ft_printf("%s", temp->content);
		temp = temp->next;
	}
	ft_printf("-------\n\n");
}
