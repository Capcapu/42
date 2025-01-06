/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:18:03 by csolari           #+#    #+#             */
/*   Updated: 2024/12/23 18:06:04 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(char *rest)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!rest[i])
		return (NULL);
	while (rest[i] && rest[i] != '\n')
		i++;
	str = ft_calloc(sizeof(char), (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
	{
		str[i] = rest[i];
		i++;
	}
	if (rest[i] == '\n')
	{
		str[i] = rest[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_next_rest(char *rest)
{
	char	*new_rest;
	size_t	i;
	size_t	j;
	size_t	len_rest;

	i = 0;
	j = 0;
	len_rest = ft_strlen(rest);
	while (rest[i] && rest[i] != '\n')
		i++;
	if (!rest[i])
		return (free(rest), NULL);
	new_rest = ft_calloc(sizeof(char), len_rest - i + 1);
	if (!new_rest)
		return (NULL);
	while (rest[++i])
	{
		new_rest[j] = rest[i];
		j++;
	}
	new_rest[j] = 0;
	free(rest);
	return (new_rest);
}

char	*ft_read_file(int fd, char *rest)
{
	int		bytes;
	char	*buf;

	bytes = 1;
	buf = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (bytes != 0 && !ft_strchr(rest, '\n'))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buf), free(rest), NULL);
		buf[bytes] = 0;
		rest = ft_strjoin(rest, buf);
	}
	free(buf);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*complete_line;
	static char	*rest_line[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest_line[fd] = ft_read_file(fd, rest_line[fd]);
	if (!rest_line[fd])
		return (NULL);
	complete_line = ft_get_line(rest_line[fd]);
	rest_line[fd] = ft_next_rest(rest_line[fd]);
	return (complete_line);
}


int main()
{
	int	fd;
	int	fd2;
	char	*test;
	
	fd = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
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
	
	test = get_next_line(fd2);
	printf("%s", test);
	free(test);

	test = get_next_line(fd);
	printf("%s", test);
	free(test);
	
 }

