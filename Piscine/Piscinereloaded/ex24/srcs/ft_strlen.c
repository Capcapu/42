/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:02:51 by csolari           #+#    #+#             */
/*   Updated: 2024/07/02 19:11:55 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

/*
#include <stdio.h>
int	main(void)
{
	char	t[] = "hello";
	int	res;
	
	res = ft_strlen(t);
	printf("%d",res);
}
*/
