# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csolari <csolari@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/28 11:41:25 by csolari           #+#    #+#              #
#    Updated: 2025/03/25 10:20:19 by csolari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC_DIR = ./sources/
OBJ_DIR = ./objects/
LIBFT_DIR = ./Libft

SRC = pipex.c path_cmd.c exec.c childs.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

CC = cc -g
CFLAGS = -Wall -Wextra -Werror
INC_H = -I includes/ -I $(LIBFT_DIR)/includes

all : $(NAME)

$(NAME) : $(OBJ)
		make -C $(LIBFT_DIR) all
		$(CC) $(CFLAGS) $(INC_H) $(OBJ) -L $(LIBFT_DIR) -lft -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
		$(CC) $(CFLAGS) $(INC_H) -c $< -o $@

$(OBJ_DIR) :
		mkdir -p $(OBJ_DIR)

clean :
		rm -rf $(OBJ_DIR)
		make -C $(LIBFT_DIR) clean

fclean : clean
		rm -f $(NAME)
		make -C $(LIBFT_DIR) fclean

re : fclean all

.PHONY : all clean fclean re
