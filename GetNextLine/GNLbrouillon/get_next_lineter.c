/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:57:48 by csolari           #+#    #+#             */
/*   Updated: 2024/12/20 12:25:02 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



int	ft_contains_return(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != 0)
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_rest(char *rest, int fd)
{
	int		bytes;
	char	*buf;

	buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes = 1;
	if (!rest)
		rest = ft_strdup("\0");
	// if (ft_contains_return(rest) != -1)
	// 	return (free(buf), rest);
	else
	{
		while (bytes != 0 && ft_contains_return(rest) == -1)
		{
			bytes = read(fd, buf, BUFFER_SIZE);
			if (bytes == -1)
			{
				if (buf)
					free(buf);
				if (rest)
					free(rest);
				return (NULL);
			}
			buf[bytes] = 0;
			rest = ft_strjoin(rest, buf);
		}
	}
	return (free(buf), rest);
}

char	*get_next_line(int fd)
{
	char		*complete_line;
	static char	*rest_line;
	size_t		index_n;
	char		*mem;
	size_t		size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest_line = ft_rest(rest_line, fd);
	if (rest_line == NULL)
		return (NULL);
	index_n = ft_contains_return(rest_line);
	//printf("%zu", index_n);
	//if (index_n == (unsigned long)-1)
	//{
		// index_n = ft_strlen(rest_line) - 1;
		// printf("%zu", index_n);
		//complete_line = ft_strdup(rest_line);
		//printf("%s",complete_line);
		//return(free(rest_line), complete_line);
	//}
	complete_line = ft_calloc(sizeof(char), index_n + 2);
	ft_strlcpy(complete_line, rest_line, index_n + 2);
	mem = ft_strdup(rest_line);
	free(rest_line);
	size = ft_strlen(mem) - index_n;
	//printf("%zu", size);
	rest_line = ft_calloc(sizeof(char), size);
	ft_strlcpy(rest_line, (mem + index_n + 1), size);
	free(mem);
	return (complete_line);
}

int main()
{
	int	fd;
	char	*test;
	
	fd = open("test2.txt", O_RDONLY);
	if (fd < 0)
        return (printf("Erreur lors de l'ouverture du fichier"));
	// while((test = get_next_line(fd)))
	// {
	// 	printf("%s", test);
	// 	free(test);
	// }
	test = get_next_line(fd);
	printf("%s", test);
	free(test);
	
	test = get_next_line(fd);
	printf("%s", test);
	free(test);
	test = get_next_line(fd);
	printf("%s", test);
	free(test);
	
	test = get_next_line(fd);
	printf("%s", test);
	free(test);
		
	test = get_next_line(fd);
	printf("%s", test);
	free(test);
	
	test = get_next_line(fd);
	printf("%s", test);
	free(test);

	test = get_next_line(fd);
	printf("%s", test);
	free(test);

 }
