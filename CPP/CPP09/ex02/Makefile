# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: capucine <capucine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/09 10:35:15 by csolari           #+#    #+#              #
#    Updated: 2026/03/16 11:19:02 by capucine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#.SILENT:
.NOTPARALLEL : all fclean re #to avoid hazardous compilation with "make -j re"

NAME = PmergeMe

OBJ_DIR = ./objects/

SRC = main.cpp PmergeMe.cpp \

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
INC_H = -I .

all : $(NAME)

$(OBJ_DIR) :
		mkdir -p $(OBJ_DIR)

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(INC_H) $(INC_H) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o : %.cpp | $(OBJ_DIR)
		$(CC) $(CFLAGS) $(INC_H) -c $< -o $@

clean :
		rm -rf $(OBJ_DIR)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re

