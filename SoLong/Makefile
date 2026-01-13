# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csolari <csolari@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/27 12:20:39 by csolari           #+#    #+#              #
#    Updated: 2025/04/04 16:33:02 by csolari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC_DIR = ./sources/
OBJ_DIR = ./objects/
LIBFT_DIR = ./Libft
MLX_DIR = ./minilibx-linux/

SRC = parsing.c so_long.c utils.c check_map.c display.c moves.c free.c\
		check_map2.c moves2.c display_init.c\

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

CC = cc -g
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Imlx -lmlx -lXext -lX11
INC_H = -I includes/ -I $(LIBFT_DIR)/includes -I $(MLX_DIR)

all : $(NAME)

$(NAME) : $(OBJ)
		@make -C $(LIBFT_DIR) all
		@echo "libft compiled! $<"
		@make -C $(MLX_DIR)
		@echo "minilibx compiled! $<"
		@$(CC) $(CFLAGS) $(INC_H) $(OBJ) -L $(LIBFT_DIR) -lft -L $(MLX_DIR) $(LDFLAGS) -o $(NAME)
		@echo "so_long compiled! $<"

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
		@echo "so_long executable removed! $<"
		@make -C $(LIBFT_DIR) fclean
		@echo "Libft executable removed! $<"

re : fclean all

.PHONY : all clean fclean re
