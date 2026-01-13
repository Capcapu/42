/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:37:07 by csolari           #+#    #+#             */
/*   Updated: 2025/10/13 17:33:39 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	init_context_ter(t_context **context)
{
	t_texture	*tex;
	t_image		*image;

	image = malloc(sizeof(t_image));
	if (!image)
		ft_error(2, *context);
	init_image(image);
	(*context)->image = image;
	tex = malloc(sizeof(t_texture));
	if (!tex)
		ft_error(2, *context);
	init_texture(tex);
	(*context)->tex = tex;
	(*context)->screen_x = 0;
	(*context)->number_image = 0;
}

static void	init_context_bis(t_context **context)
{
	t_press		*press;
	t_camera	*cam;
	t_ray		*ray;

	press = malloc(sizeof(t_press));
	if (!press)
		ft_error(2, *context);
	init_press(press);
	(*context)->press = press;
	(*context)->file = NULL;
	(*context)->current = NULL;
	(*context)->image = NULL;
	(*context)->map = NULL;
	(*context)->screen_height = 0;
	(*context)->screen_width = 0;
	cam = malloc(sizeof(t_camera));
	if (!cam)
		ft_error(2, *context);
	init_camera(cam);
	(*context)->cam = cam;
	ray = malloc(sizeof(t_ray));
	if (!ray)
		ft_error(2, *context);
	init_ray(ray);
	(*context)->ray = ray;
}

void	init_context(t_context **context)
{
	t_map		*map;
	t_window	*window;

	*context = malloc(sizeof(t_context));
	if (!*context)
		ft_error(2, *context);
	(*context)->size_pix = 0;
	init_context_bis(context);
	init_context_ter(context);
	map = malloc(sizeof(t_map));
	if (!map)
		ft_error(2, *context);
	init_map(map);
	(*context)->map = map;
	(*context)->fd = -1;
	window = malloc(sizeof(t_window));
	if (!window)
		ft_error(2, *context);
	init_win(window);
	(*context)->window = window;
}
