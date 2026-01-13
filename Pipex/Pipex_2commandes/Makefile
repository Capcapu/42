# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csolari <csolari@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/28 11:41:25 by csolari           #+#    #+#              #
#    Updated: 2025/03/14 11:20:20 by csolari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC_DIR = ./sources/
OBJ_DIR = ./objects/
LIBFT_DIR = ./Libft

SRC = pipex.c check_arg.c struct.c
SRC_BONUS = bonus_pipex.c bonus_check_arg.c bonus_exec.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
OBJ_BONUS = $(addprefix $(OBJ_DIR), $(SRC_BONUS:.c=.o))

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

bonus : bo

bo : $(OBJ_BONUS)
	make -C $(LIBFT_DIR) all
	$(CC) $(CFLAGS) $(INC_H) $(OBJ_BONUS) -L $(LIBFT_DIR) -lft -o $(NAME)


clean :
		rm -rf $(OBJ_DIR)
		make -C $(LIBFT_DIR) clean

fclean : clean
		rm -f $(NAME)
		make -C $(LIBFT_DIR) fclean

re : fclean all

re_bonus : fclean bonus

.PHONY : all clean fclean re
