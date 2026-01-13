# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csolari <csolari@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/28 16:36:23 by csolari           #+#    #+#              #
#    Updated: 2025/10/29 16:16:04 by csolari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex00

OBJ_DIR = ./objects/

SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp\

OBJ =  $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
INC_H = -I includes/ 

all : $(NAME)

$(OBJ_DIR) :
		mkdir -p $(OBJ_DIR)

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(INC_H) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: %.cpp | $(OBJ_DIR)
		$(CC) $(CFLAGS) $(INC_H) -c $< -o $@

clean :
		rm -rf $(OBJ_DIR)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re