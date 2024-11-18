/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:45:51 by csolari           #+#    #+#             */
/*   Updated: 2024/11/06 12:12:33 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*p;
	int	i;
	int	dif;

	dif = max - min;
	p = NULL;
	if (dif > 0)
	{
		p = (int *)malloc(sizeof(int) * (dif + 1));
		if (!p)
			return (NULL);
		i = 0;
		while (i < dif)
		{
			p[i] = min + i;
			i++;
		}
		p[i] = '\0';
	}
	return (p);
}

/*
#include <stdio.h>
int	main(void)
{
	int *tab;
	int i;
	int min;
	int max;

	min = 7;
	max = 30;
	i = 0;
	tab = ft_range(min, max);
	while (i < max - min)
	{
		printf("%d\n", tab[i]);
		i++;
	}
	free (tab);
	return (0);
}
*/
