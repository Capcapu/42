/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:23:03 by csolari           #+#    #+#             */
/*   Updated: 2024/11/05 10:42:47 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	mem;

	mem = *a;
	*a = *b;
	*b = mem;
}

/*
int	main(void)
{
	int	a;
	int	b;
	
	a = 4;
	b = 7;

	printf("%d", a);
	printf("%d", b);
	
	ft_swap(&a, &b);
	
	printf("%d", a);
	printf("%d", b);

	return(0);
}
*/
