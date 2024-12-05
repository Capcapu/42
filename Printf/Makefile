# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csolari <csolari@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 14:45:17 by csolari           #+#    #+#              #
#    Updated: 2024/12/03 14:06:02 by csolari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES = ft_printf.c ft_printf_outils.c ft_printf_outils2.c \

LIBFT = Libft/libft.a

HEADERS =	printf.h

OBJECTS = $(SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar -rsc

all :  makelibft $(NAME) 

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME) : $(OBJECTS)
	cp $(LIBFT) $(NAME) 
	$(AR) $(NAME) $(OBJECTS)

clean :
	rm -f $(OBJECTS) 
	make -C Libft clean

fclean : clean
	rm -f $(NAME)
	rm -f Libft/libft.a

re : fclean all

makelibft :
	make -C Libft all

# Precise que ce ne sont pas des fichiers a compiler -> securise
.PHONY : all clean fclean re makelibft