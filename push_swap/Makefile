# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csolari <csolari@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/04 10:32:18 by csolari           #+#    #+#              #
#    Updated: 2025/02/18 13:07:47 by csolari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT_DIR = ./Libft
SRC_DIR = ./ps_sources/
OBJ_DIR = ./ps_objects/

SOURCES = input.c parsing.c push_swap.c swap_rules.c push_rules.c rotate_rules.c \
			reverse_rotate_rules.c check_order.c median.c algorithm.c sort_three.c\
			errors.c moves_cost.c\

OBJECTS = $(addprefix $(OBJ_DIR), $(SOURCES:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror
INC_H = -I . -I $(LIBFT_DIR)/includes # -I . indique au compilateur de chercher les headers a la racine du projet, le second -I inclu les headers de la libft

all : $(NAME) 

$(NAME) : $(OBJECTS) $(LIBFT_DIR)/libft.a
	make -C $(LIBFT_DIR) all
	$(CC) $(CFLAGS) $(INC_H) $(OBJECTS) -L $(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT_DIR)/libft.a :
	make -C $(LIBFT_DIR) all

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR) #cherche dans le dossier source
	$(CC) $(CFLAGS) $(INC_H) -c $< -o $@

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR) #cherche a la racine les .c, la ou est le makefile
	$(CC) $(CFLAGS) $(INC_H) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean :
	rm -rf $(OBJ_DIR) 
	make -C $(LIBFT_DIR) clean

fclean : clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re : fclean all

.PHONY : all clean fclean re