/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 09:58:12 by csolari           #+#    #+#             */
/*   Updated: 2025/10/17 12:43:35 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	fill_ns(t_context *ctx, char *line, char *trimed_path, int ref)
{
	int	i;

	i = 0;
	while (line && ft_isspace(line[i]))
		i++;
	if (ref == 1)
	{
		if (ctx->image->adr_no)
			free(ctx->image->adr_no);
		trimed_path = ft_strtrim(line + i + 2, " \t\n");
		ctx->image->adr_no = trimed_path;
	}
	if (ref == 2)
	{
		if (ctx->image->adr_so)
			free(ctx->image->adr_so);
		trimed_path = ft_strtrim(line + i + 2, " \t\n");
		ctx->image->adr_so = trimed_path;
	}
}

void	fill_ew(t_context *ctx, char *line, char *trimed_path, int ref)
{
	int	i;

	i = 0;
	while (line && ft_isspace(line[i]))
		i++;
	if (ref == 3)
	{
		if (ctx->image->adr_we)
			free(ctx->image->adr_we);
		trimed_path = ft_strtrim(line + i + 2, " \t\n");
		ctx->image->adr_we = trimed_path;
	}
	if (ref == 4)
	{
		if (ctx->image->adr_ea)
			free(ctx->image->adr_ea);
		trimed_path = ft_strtrim(line + i + 2, " \t\n");
		ctx->image->adr_ea = trimed_path;
	}
}

void	fill_nsew(t_context *ctx, char *line)
{
	int		i;
	char	*trimed_path;

	trimed_path = NULL;
	i = 0;
	while (line && ft_isspace(line[i]))
		i++;
	if ((ft_strncmp(line + i, "NO", 2) == 0 && ft_isspace(line[i + 2]))
		|| (line[i] == 'N' && ft_isspace(line[i + 1])))
		fill_ns(ctx, line, trimed_path, 1);
	else if ((ft_strncmp(line + i, "SO", 2) == 0 && ft_isspace(line[i + 2]))
		|| (line[i] == 'S' && ft_isspace(line[i + 1])))
		fill_ns(ctx, line, trimed_path, 2);
	else if ((ft_strncmp(line + i, "WE", 2) == 0 && ft_isspace(line[i + 2]))
		|| (line[i] == 'W' && ft_isspace(line[i + 1])))
		fill_ew(ctx, line, trimed_path, 3);
	else if ((ft_strncmp(line + i, "EA", 2) == 0 && ft_isspace(line[i + 2]))
		|| (line[i] == 'E' && ft_isspace(line[i + 1])))
		fill_ew(ctx, line, trimed_path, 4);
	else
		ft_error(9, ctx);
}
