/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:01:25 by csolari           #+#    #+#             */
/*   Updated: 2025/10/17 12:41:04 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../Libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# define SPEED 1000

typedef struct s_move
{
	int			x;
	int			y;
	int			new_x;
	int			new_y;
	float		speed;
	float		angle_rad;
	float		move_x;
	float		move_y;
}				t_move;

typedef struct s_color
{
	void		*img_ptr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			pixel_index;

}				t_color;

typedef struct s_image
{
	char		*adr_no;
	char		*adr_so;
	char		*adr_we;
	char		*adr_ea;
	int			f_r;
	int			f_g;
	int			f_b;
	int			c_r;
	int			c_g;
	int			c_b;
	int			f_rgb;
	int			c_rgb;
	void		*bigptr;
	t_color		*big;
}				t_image;

typedef struct s_texture
{
	void		*northptr;
	t_color		*north;
	int			n_w;
	int			n_h;
	void		*southptr;
	t_color		*south;
	int			s_w;
	int			s_h;
	void		*eastptr;
	t_color		*east;
	int			e_w;
	int			e_h;
	void		*westptr;
	t_color		*west;
	int			w_w;
	int			w_h;

}				t_texture;

typedef struct s_ray
{
	double		dir_x;
	double		dir_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			side;
	char		wall_o;
}				t_ray;

typedef struct s_camera
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_camera;

typedef struct s_map
{
	int			height;
	int			width;
	char		**tab;
	t_list		*lst;
	char		o;
	int			deg;
	float		x;
	float		y;
}				t_map;

typedef struct s_window
{
	void		*mlx;
	void		*win;
}				t_window;

typedef struct s_press
{
	int			w;
	int			s;
	int			d;
	int			a;
	int			l;
	int			r;

}				t_press;

typedef struct s_context
{
	t_image		*image;
	t_map		*map;
	t_window	*window;
	t_list		*file;
	t_list		*current;
	t_press		*press;
	t_ray		*ray;
	t_camera	*cam;
	t_texture	*tex;
	int			screen_width;
	int			screen_height;
	int			size_pix;
	int			fd;
	int			screen_x;
}				t_context;

/* algo_dda.c */
void			calc_step_and_side_dist(t_ray *ray, t_camera *cam);
void			calc_wall_position(t_ray *ray, t_camera *cam, double *wall_x,
					double *wall_y);
int				perform_dda(t_ray *ray, t_context *ctx);

/* check_map_line_col.c */
void			check_line(t_context *ctx, int i, int j);
void			check_col(t_context *ctx, int i, int j);

/* check_map.c */
int				is_backslash(char *str);
int				check_end_file(t_context *ctx);

/* check_top.c */
void			check_values_colors(char **tab, t_context *context);
int				ft_check_name(char *str);
int				check_number_coma(char *str);
int				check_context_top(t_context *ctx);

/* display.c */
void			display(t_context *ctx);

/* error.c */
void			ft_error(int error_code, t_context *context);

/* fill_struct.c */
void			fill_nsew(t_context *ctx, char *line);

/* free.c */
void			clean_up(t_context *context);

/* free2.c */
void			ft_free_tab(char **tab);
void			free_textures(t_context *ctx);

/* init_data_raycasting.c */

void			init_data_camera(t_camera *cam, t_context *ctx);
void			init_data_ray(t_ray *ray, t_camera *cam, int screen_x,
					int screen_width);

/* initialization.c */
void			init_context(t_context **context);

/* initialization2.c */
void			init_color(t_color *color);
void			init_press(t_press *press);
void			init_camera(t_camera *cam);
void			init_ray(t_ray *ray);
void			init_texture(t_texture *tex);

/* initialization3.c */
void			init_image(t_image *image);
void			init_map(t_map *map);
void			init_win(t_window *window);
void			init_big(t_context *ctx);

/* key_press.c */
int				key_press(int key, void *param);
int				key_release(int key, void *param);
int				loop_update(void *param);

/* moves_see.c */
int				see_left(t_context *ctx);
int				see_right(t_context *ctx);

/* moves_utils.c */
void			init_move(t_move *m, t_context *ctx, int deg, int trigo);
int				check_collisions_outside_wall(t_move m, t_context *ctx);

/* moves_walk.c */
int				go_up(t_context *ctx);
int				go_down(t_context *ctx);
int				go_left(t_context *ctx);
int				go_right(t_context *ctx);

/* parsing_map.c */
void			parsing_map(t_context *ctx);

/* parsing_top.c */
void			parsing_top_file(t_context *ctx);

/* parsing.c */
void			parsing(t_context *context);
int				get_wall_texture_index(t_ray *ray);

/* parsing2.c */
void			draw_image(t_context *ctx);

/* raycasting.c */
void			raycasting(t_context *ctx);

/* reform_map.c */
void			reform_map(t_context *ctx);

/* tool.c */
char			**lst_into_tab(t_context *ctx, int size_tab);
void			size_map(t_context *ctx);
int				convert_rgb(int r, int g, int b);
void			put_pixel_to_image(t_color *image, int x, int y, int color);

/* xpm_to_image.c */
void			init_sprite(t_context *ctx);

#endif