#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/23 15:55:54 by dmaslenn          #+#    #+#              #
#    Updated: 2017/10/19 13:47:20 by dmaslenn         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = RTv1

SRC = rtv.c \
		initialize.c \
		plane.c \
		sphere.c \
		cylinder.c \
		help.c \
		calc.c \
		rand.c \
		cone.c

OBJ = $(SRC:.c=.o)

CC = gcc -Wall -Werror -Wextra

FLGS = -Wall -Werror -Wextra

INC = ./

LIB =  -L ./libft/ -lft

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft/
	@$(CC) -o $(NAME) $(OBJ) $(LIB) -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	@$(CC) $(FLG) -I $(INC) -c $<

clean:
	@make -C ./libft/ clean
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
