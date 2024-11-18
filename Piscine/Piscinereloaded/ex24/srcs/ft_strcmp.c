/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 08:35:34 by csolari           #+#    #+#             */
/*   Updated: 2024/07/02 10:51:01 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1[i] == 0 && s2[i] == 0)
	{
		return (0);
	}
	while (s1[i] != 0)
	{
		if (s1[i] == s2[i])
		{
			i++;
		}
		else
		{
			return (s1[i] - s2[i]);
		}
	}
	return (s1[i] - s2[i]);
}

/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char s1[]="";
	char s2[]="";
	int ret;
	ret = strcmp(s1, s2);
	printf("%d\n", ret);
}
*/
