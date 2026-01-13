# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csolari <csolari@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/17 13:58:45 by csolari           #+#    #+#              #
#    Updated: 2025/10/14 15:47:34 by csolari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
NAME_BONUS = cub3D_bonus

SRC_DIR = ./sources/
SRC_BNS_DIR = ./sources_bonus/
OBJ_DIR = ./objects/
OBJ_BNS_DIR = ./objects_bonus/
LIBFT_DIR = ./Libft
MLX_DIR = ./minilibx-linux/

SRC = parsing.c main.c error.c free.c initialization.c tool.c check_top.c \
		parsing_top.c parsing_map.c check_map.c check_map_line_col.c \
		reform_map.c display.c initialization2.c moves_walk.c \
		raycasting.c algo_dda.c moves_see.c key_press.c moves_utils.c \
		free2.c xpm_to_image.c initialization3.c init_data_raycasting.c \
		fill_struct.c raycasting2.c \

BONUS =  parsing.c main.c error.c free.c initialization.c tool.c check_top.c  \
		parsing_top.c parsing_map.c check_map.c check_map_line_col.c \
		reform_map.c display.c display_mini_map.c initialization2.c moves_walk.c \
		raycasting.c algo_dda.c moves_see.c key_press.c moves_utils.c \
		free2.c xpm_to_image.c initialization3.c init_data_raycasting.c \
		fill_struct.c raycasting2.c \

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
OBJ_BNS = $(addprefix $(OBJ_BNS_DIR), $(BONUS:.c=.o))

CC = cc -g
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Imlx -lmlx -lXext -lX11 -lm
INC_H = -I includes -I $(LIBFT_DIR)/includes -I $(MLX_DIR)
INC_BNS_H = -I includes -I $(LIBFT_DIR)/includes -I $(MLX_DIR)

all : $(NAME)

$(NAME) : $(OBJ)
		@make -C $(LIBFT_DIR) all
		@echo "libft compiled! $<"
		@make -C $(MLX_DIR)
		@echo "minilibx compiled! $<"
		@$(CC) $(CFLAGS) $(INC_H) $(OBJ) -L $(LIBFT_DIR) -lft -L $(MLX_DIR) $(LDFLAGS) -o $(NAME)
		@echo "cub3D compiled! $<"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
		@echo "Compiling $<"
		@$(CC) $(CFLAGS) $(INC_H) -c $< -o $@

$(OBJ_DIR) :
		@mkdir -p $(OBJ_DIR)

clean :
		@rm -rf $(OBJ_DIR)
		@make -C $(LIBFT_DIR) clean
		@echo "Objects removed! $<"
		@make -C $(MLX_DIR) clean
		@echo "minilibx executable removed! $<"

fclean : clean
		@rm -f $(NAME)
		@echo "cub3D executable removed! $<"
		@make -C $(LIBFT_DIR) fclean
		@echo "Libft executable removed! $<"

re : fclean all

bonus : $(OBJ_BNS)
		@make -C $(LIBFT_DIR) all
		@echo "libft compiled! $<"
		@make -C $(MLX_DIR)
		@echo "minilibx compiled! $<"
		@$(CC) $(CFLAGS) $(INC_BNS_H) $(OBJ_BNS) -L $(LIBFT_DIR) -lft -L $(MLX_DIR) $(LDFLAGS) -o $(NAME_BONUS)
		@echo "cub3D bonus compiled! $<"

$(OBJ_BNS_DIR)%.o: $(SRC_BNS_DIR)%.c | $(OBJ_BNS_DIR)
		@echo "Compiling $<"
		@$(CC) $(CFLAGS) $(INC_BNS_H) -c $< -o $@

$(OBJ_BNS_DIR) :
		@mkdir -p $(OBJ_BNS_DIR)

bonus_clean :
		@rm -rf $(OBJ_BNS_DIR)
		@make -C $(LIBFT_DIR) clean
		@echo "Objects removed! $<"
		@make -C $(MLX_DIR) clean
		@echo "minilibx executable removed! $<"

bonus_fclean : bonus_clean
		@rm -f $(NAME_BONUS)
		@echo "cub3D bonus executable removed! $<"
		@make -C $(LIBFT_DIR) fclean
		@echo "Libft executable removed! $<"

bonus_re : bonus_fclean bonus


.PHONY : all clean fclean re bonus bonus_clean bonus_fclean bonus_re
