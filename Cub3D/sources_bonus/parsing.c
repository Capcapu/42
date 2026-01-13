/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:59:58 by csolari           #+#    #+#             */
/*   Updated: 2025/10/17 11:29:41 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	parsing(t_context *context)
{
	parsing_top_file(context);
	if (!check_context_top(context))
		ft_error(9, context);
	parsing_map(context);
	if (context->map->height > 80 || context->map->width > 100)
		ft_error(16, context);
}
