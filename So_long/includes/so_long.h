/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:19:29 by csolari           #+#    #+#             */
/*   Updated: 2025/04/08 12:34:22 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_data;

typedef struct s_map
{
	int		x;
	int		y;
	int		row;
	int		col;
	int		collectible;
	int		exit;
	int		player;
}			t_map;

typedef struct s_context
{
	void	*mlx;
	void	*win;
	char	**map;
	t_map	*map_struct;
	t_data	*exit;
	t_data	*ground;
	t_data	*player;
	t_data	*wall;
	t_data	*collectible;
	int		nb_moves;
}			t_context;

int			check_map_size(char **map);
int			close_window(t_context *context);
int			key_press(int keypress, t_context *context);
int			go_right(t_context *cont);
int			go_left(t_context *cont);
int			go_up(t_context *cont);
int			go_down(t_context *cont);
int			init_lst_exit(t_context *context);
int			init_lst_ground(t_context *context);
int			init_lst_player(t_context *context);
int			init_lst_wall(t_context *context);
int			init_lst_collec(t_context *context);
char		**parsing_map(char **argv);
void		print_map(char **map);
void		init_lst_map(t_map *lst_map);
void		ft_free_tab(char **tab);
void		flood_fill(char **tab, t_map *map_struct, int x, int y);
void		ft_free_context(t_context *context);
void		display_map(t_context *context);
void		init_lst_data(t_data *data);
void		init_lst_context(t_context *context);
t_map		*check_solvability_map(char **map);
t_map		*count_elem_map(char **map);
t_context	*init_context(t_map *map_struct);

#endif
