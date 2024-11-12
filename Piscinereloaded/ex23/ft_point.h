/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:05:55 by csolari           #+#    #+#             */
/*   Updated: 2024/11/08 16:10:48 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POINT_H
# define FT_POINT_H
# include <stdio.h>

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

void	set_point(t_point	*point);
#endif
