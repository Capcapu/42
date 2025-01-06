/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:18:53 by csolari           #+#    #+#             */
/*   Updated: 2024/12/20 16:22:26 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	bytes;
	size_t	i;

	i = 0;
	bytes = nmemb * size;
	if (size != 0 && ((bytes / size) != nmemb))
		return (NULL);
	ptr = malloc(bytes);
	if (!ptr)
		return (NULL);
	while (i < bytes)
		ptr[i++] = 0;
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*strj;
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_calloc(1, 1);
	if (!s1 || !s2)
		return (NULL);
	strj = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!strj)
		return (NULL);
	while (s1 && s1[i])
	{
		strj[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		strj[i + j] = s2[j];
		j++;
	}
	strj[ft_strlen(s1) + ft_strlen(s2)] = 0;
	return (free(s1), strj);
}

char	*ft_strchr(char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)(str + i));
	return (NULL);
}
