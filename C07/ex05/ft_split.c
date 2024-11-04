/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:58:35 by csolari           #+#    #+#             */
/*   Updated: 2024/07/17 13:38:45 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	ft_in_str(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_words( char *str, char *charset)
{
	int 	i;
	int		nb_w;

	i = 0;
	nb_w = 0;
	while (str[i + 1] != 0)
	{
		if (ft_in_str(str[i], charset) == 0
			&& ft_in_str(str[i + 1], charset) == 1)
			nb_w++;
		i++;
	}
	return (nb_w);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int 	count;

	printf("d",ft_count_words(str, charset));
//	res = (char **)malloc(sizeof(char *) * (ft_count_words(str, charset) + 1));
	return (res);
}

int	main()
{
	int	i;
	char	**res;

	i = 0;
	res = ft_split("bonjour je m'appelle :) capucine!solari He Ytuvas b i en:", " !:")
                          
}






/*

void	ft_strcpy(int i, char *dest, char *str)
{
	int	j;

	j = 0;
	while (dest[j] != 0)
	{
		dest[j] = str[i + j];
		printf("%c", str[i+j]);
		j++;
	}
}



res[nb_lignes] = "0";
	i = 0;
	j = 0;
	count = 0;
	while (str[i] != 0)
	{
		if (ft_in_str(str[i], charset) == 1
			&& ft_in_str(str[i + 1], charset) == 0)
		{ 
			res[count] = (char *)malloc(sizeof(char) * (i - j + 1));
			res[count][i - j] = '\0';
			ft_strcpy(j, res[count], str);
			printf("%s", ft_strcpy(j,res[count], str));
			j = i;
			count++;
		}
		i++;
	}


*/