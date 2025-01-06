/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_linebis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:26:06 by csolari           #+#    #+#             */
/*   Updated: 2024/12/19 13:58:17 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*ft_joinfree(char *s, char *buf, int index)
{
	char	*res;

	res = ft_strjoin(s, (buf + index));
	free(s);
	
	return (res);
}

int	ft_contains_return(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != 0)
	{
		if (str[i] == '\n')
			return(i);
		i++;
	}
	return (-1);
}

char	*ft_line(char *buf, int fd)
{
	static char *rest_line;
	int			is_complete;
	int			i;
	int			ret;
	char		*line;
	char		*mem;

	is_complete = -1;
	i = -1;
	ret = ft_contains_return(rest_line);
	if (ret >= 0)
	{
		//line = ft_strdup(rest_line);
		line = ft_calloc(sizeof(char), ret + 2);
		ft_strlcpy(line, rest_line, ret + 2);
		mem = ft_strdup(rest_line);
		free(rest_line);
		rest_line = ft_strdup(&mem[ret + 1]);
		//line[ret + 1] = '\0';
		free(mem);
		return(line);
	}
	while (is_complete == -1)
	{
		if (i != 0)
		{
			ft_memset(buf, '\0', ft_strlen(buf));
			i = read(fd, buf, BUFFER_SIZE);
			buf = ft_strjoin(rest_line, buf);
			rest_line = NULL;
		}
		is_complete = ft_contains_return(buf);
		if (i == 1)
		{
			line = ft_strdup(buf);
			break;
		}
		// if (is_complete == 0)
		// 	rest_line = ft_strdup((buf + 1));
		else
		{
			rest_line = ft_joinfree(rest_line, buf, is_complete + 1);
			line = ft_calloc(sizeof(char), is_complete + 1);
			ft_strlcpy(line, buf, is_complete + 1);
		}
		free(buf);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char	*buf;
	char	*complete_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	complete_line = ft_line(buf, fd);
	free(buf);
	return(complete_line);
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
	// test = get_next_line(fd);
	// printf("%s", test);
	// free(test);
	
	test = get_next_line(fd);
	printf("%s", test);
	free(test);
	test = get_next_line(fd);
	printf("%s", test);
	free(test);
	
	test = get_next_line(fd);
	printf("%s", test);
	free(test);
		
// 	test = get_next_line(fd);
// 	printf("%s", test);
// 	free(test);
	
// 	test = get_next_line(fd);
// 	printf("%s", test);
// 	free(test);

	
// 	test = get_next_line(fd);
// 	printf("%s", test);
// 	free(test);

 }
