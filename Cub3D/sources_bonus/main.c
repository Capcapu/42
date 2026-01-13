/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:00:04 by csolari           #+#    #+#             */
/*   Updated: 2025/10/17 11:21:04 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	read_file(t_context *context, char *file)
{
	char	*line;
	t_list	*file_lst;
	t_list	*new_node;

	file_lst = NULL;
	context->fd = open(file, O_RDONLY);
	if (context->fd < 0)
		ft_error(5, context);
	line = get_next_line(context->fd);
	while (line)
	{
		new_node = ft_lstnew(ft_strdup(line));
		if (!new_node)
		{
			free(line);
			return (0);
		}
		ft_lstadd_back(&file_lst, new_node);
		free(line);
		line = get_next_line(context->fd);
	}
	context->file = file_lst;
	return (1);
}

int	main(int argc, char **argv)
{
	t_context	*context;

	context = NULL;
	if (argc != 2)
		ft_error(4, context);
	if (!ft_check_name(argv[1]))
		ft_error(3, context);
	init_context(&context);
	if (!read_file(context, argv[1]))
		ft_error(6, context);
	parsing(context);
	raycasting(context);
	display(context);
	clean_up(context);
	return (0);
}
