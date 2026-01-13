/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_top.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 09:55:32 by csolari           #+#    #+#             */
/*   Updated: 2025/10/17 12:42:33 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_check_name(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str)
	{
		if (str[i] == '.')
			break ;
		i++;
	}
	if (str[i + 1] == 'c' && str[i + 2] == 'u' && str[i + 3] == 'b' && str[i
			+ 4] == '\0' && i > 0)
		return (1);
	return (0);
}

int	check_number_coma(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		return (0);
	return (1);
}

int	check_context_top(t_context *ctx)
{
	if (!ctx)
		return (0);
	if (ctx->image->adr_no == NULL || ctx->image->adr_so == NULL
		|| ctx->image->adr_we == NULL || ctx->image->adr_ea == NULL
		|| ctx->image->f_r == -1 || ctx->image->f_g == -1
		|| ctx->image->f_b == -1 || ctx->image->c_r == -1
		|| ctx->image->c_g == -1 || ctx->image->c_b == -1)
		return (0);
	return (1);
}

void	check_bis_values_colors(char **tab, int i, int j, t_context *context)
{
	while (tab[i] && tab[i][j])
	{
		if (!ft_isdigit(tab[i][j]))
			return (ft_free_tab(tab), ft_error(7, context));
		j++;
	}
	if (j == 0 || ft_atoi(tab[i]) > 255)
		return (ft_free_tab(tab), ft_error(7, context));
}

void	check_values_colors(char **tab, t_context *context)
{
	int		i;
	int		j;
	char	*trimmed;

	i = 0;
	if (!tab)
		ft_error(7, context);
	if (!tab[0] || !tab[1] || !tab[2] || tab[3])
		return (ft_free_tab(tab), ft_error(7, context));
	while (i < 3)
	{
		j = 0;
		if (i == 2 && tab[i])
		{
			if (!ft_strncmp(tab[i], "\n", 1))
				return (ft_free_tab(tab), ft_error(7, context));
			trimmed = ft_strtrim(tab[i], "\n");
			if (!trimmed || trimmed[0] == 0)
				return (ft_free_tab(tab), ft_error(2, context));
			free(tab[i]);
			tab[i] = trimmed;
		}
		check_bis_values_colors(tab, i, j, context);
		i++;
	}
}
