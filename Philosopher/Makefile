# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csolari <csolari@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/03 11:06:11 by csolari           #+#    #+#              #
#    Updated: 2025/06/17 11:51:19 by csolari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC_DIR = ./sources/
OBJ_DIR = ./objects/

SRC = main.c utils.c check_args.c initializations.c initializations2.c free.c \
		routine.c routine2.c print.c eat_sleep_think.c check_dead.c\

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

HEADER = philo.h

CC = cc -g
CFLAGS = -Wall -Wextra -Werror
INC_H = -I .

all : $(NAME)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(INC_H) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC_H) -c $< -o $@

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
