/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:17:01 by csolari           #+#    #+#             */
/*   Updated: 2025/10/13 15:20:06 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	is_backslash(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str && str[i])
	{
		if (ft_isspace(str[i]))
			i++;
		else
			break ;
	}
	if (str[i] == '\n')
		return (1);
	return (0);
}

int	ft_str_printable(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] > 32 && str[i] < 127)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_str_space(char *str)
{
	int	i;

	i = 0;
	if (!str || (str[i] && str[i] == 0))
		return (1);
	while (str && str[i])
	{
		if (ft_isspace(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

static int	check_printable(t_list *temp, t_context *ctx)
{
	if (!ft_str_printable(temp->content))
		ft_error(8, ctx);
	else
	{
		if (temp->next)
			return (1);
		else
			return (0);
	}
	return (1);
}

int	check_end_file(t_context *ctx)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = ctx->current;
	while (temp->content && (!is_backslash(temp->content)
			&& !ft_str_space(temp->content)))
	{
		i++;
		if (temp->next)
			temp = temp->next;
		else
			return (i);
	}
	while (temp->content)
	{
		if (check_printable(temp, ctx))
			temp = temp->next;
		else
			break ;
	}
	return (i);
}
