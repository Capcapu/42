/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:59:58 by csolari           #+#    #+#             */
/*   Updated: 2025/10/13 15:34:45 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	parsing(t_context *context)
{
	parsing_top_file(context);
	if (!check_context_top(context))
		ft_error(9, context);
	parsing_map(context);
}
