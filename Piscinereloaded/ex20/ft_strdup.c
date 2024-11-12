/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:32:46 by csolari           #+#    #+#             */
/*   Updated: 2024/11/06 12:10:54 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*p;

	i = 0;
	while (src[i])
		i++;
	p = (char *) malloc(sizeof(char) * (i + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (src[i])
	{
		p[i] = src[i];
		i++;
	}
	p[i] = 0;
	return (p);
}

/*
#include <stdio.h>
int	main(void)
{
	char	t[]="hello";
	char	*p;

	p = ft_strdup(t);
	printf("%s", p);
	free(p);
	return(0);
}
*/
