/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:51:13 by csolari           #+#    #+#             */
/*   Updated: 2025/10/17 12:32:53 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	fill_f_or_c(t_context *ctx, char *line, int fc)
{
	char	**tab;

	if (!check_number_coma(line))
		ft_error(8, ctx);
	line++;
	while (line && line[0] && ft_isspace(line[0]))
		line++;
	tab = ft_split(line, ',');
	if (!tab)
		ft_error(2, ctx);
	check_values_colors(tab, ctx);
	if (fc == 1)
	{
		ctx->image->f_r = ft_atoi(tab[0]);
		ctx->image->f_g = ft_atoi(tab[1]);
		ctx->image->f_b = ft_atoi(tab[2]);
	}
	else if (fc == 2)
	{
		ctx->image->c_r = ft_atoi(tab[0]);
		ctx->image->c_g = ft_atoi(tab[1]);
		ctx->image->c_b = ft_atoi(tab[2]);
	}
	return (ft_free_tab(tab));
}

static void	fill_fc(t_context *context, char *line)
{
	if (line[0] == 'F' && ft_isspace(line[1]))
		fill_f_or_c(context, line, 1);
	else if (line[0] == 'C' && ft_isspace(line[1]))
		fill_f_or_c(context, line, 2);
	return ;
}

static int	fill_top(t_context *ctx)
{
	int		i;
	char	c;
	char	*content;

	i = 0;
	if (!ctx->current || !ctx->current->content)
		return (0);
	content = ctx->current->content;
	while (content && ft_isspace(content[0]))
		content++;
	c = content[0];
	if (c == '\n')
		return (1);
	if (c != 'N' && c != 'S' && c != 'E' && c != 'W' && c != 'F' && c != 'C')
		return (0);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		fill_nsew(ctx, content);
	fill_fc(ctx, content);
	return (1);
}

void	parsing_top_file(t_context *ctx)
{
	ctx->current = ctx->file;
	while (!check_context_top(ctx))
	{
		if (!fill_top(ctx))
			break ;
		if (ctx->current->next != NULL)
			ctx->current = ctx->current->next;
	}
}
