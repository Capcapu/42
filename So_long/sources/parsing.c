/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:20:21 by csolari           #+#    #+#             */
/*   Updated: 2025/04/04 15:00:21 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*parsing_map_into_lst(int fd)
{
	t_list	*data;
	t_list	*temp;

	data = NULL;
	data = malloc(sizeof(t_list));
	if (!data)
		return (ft_putstr_fd("Error : Malloc\n", 2), NULL);
	temp = data;
	data->content = get_next_line(fd);
	while (data->content > 0)
	{
		data->next = malloc(sizeof(t_list));
		if (!data->next)
		{
			ft_lstclear(&data, free);
			return (NULL);
		}
		data = data->next;
		data->content = get_next_line(fd);
	}
	data->next = NULL;
	return (temp);
}

char	**parsing_map_into_tab(t_list *data)
{
	char	**map;
	int		size;
	int		i;

	size = ft_lstsize(data);
	map = malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (ft_putstr_fd("Error : Malloc\n", 2), NULL);
	i = 0;
	while (i < size)
	{
		map[i] = ft_strdup(data->content);
		data = data->next;
		i++;
	}
	map[i] = NULL;
	return (map);
}

char	**parsing_map(char **argv)
{
	int		fd;
	char	**map;
	t_list	*data;
	int		size;

	fd = 0;
	size = ft_strlen(argv[1]);
	if (!(ft_strncmp(&argv[1][size - 1], "r", 1) == 0
		&& ft_strncmp(&argv[1][size - 2], "e", 1) == 0
		&& ft_strncmp(&argv[1][size - 3], "b", 1) == 0
		&& ft_strncmp(&argv[1][size - 4], ".", 1) == 0))
		return (ft_putstr_fd("Error : No correct file format founded .ber\n",
				2), NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error : Opening file map\n");
		exit(0);
	}
	data = parsing_map_into_lst(fd);
	if (!data)
		return (NULL);
	map = parsing_map_into_tab(data);
	ft_lstclear(&data, free);
	return (close(fd), map);
}
