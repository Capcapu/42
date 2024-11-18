# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csolari <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 13:52:14 by csolari           #+#    #+#              #
#    Updated: 2024/11/08 16:34:25 by csolari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES_DIR = ./srcs/

HEADERS_DIR = ./includes/

SOURCES =	$(SOURCES_DIR)ft_putchar.c \
			$(SOURCES_DIR)ft_putstr.c \
			$(SOURCES_DIR)ft_strcmp.c \
			$(SOURCES_DIR)ft_strlen.c \
			$(SOURCES_DIR)ft_swap.c \

HEADERS =	$(HEADERS_DIR)ft_putchar.h \
			$(HEADERS_DIR)ft_putstr.h \
			$(HEADERS_DIR)ft_strcmp.h \
			$(HEADERS_DIR)ft_strlen.h \
			$(HEADERS_DIR)ft_swap.h \

OBJECTS = $(SOURCES:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I $(HEADERS_DIR)

AR = ar rsc

all : $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
