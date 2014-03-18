#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdemay <tdemay@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/03 20:21:55 by tdemay            #+#    #+#              #
#    Updated: 2014/01/03 20:21:58 by tdemay           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: clean fclean re

NAME = raytracer

CC = cc $(FLAGS)

FLAGS = -Wall -Wextra -Werror

LIB = -L libft/ -lft -L/usr/X11/lib -lmlx -lXext -lX11

SRC = vector.c\
vector_op.c\
sphere.c\
plan.c\
scene.c\
cam.c\
parse.c\
cylinder.c\
light.c\
color.c

OBJ = $(SRC:.c=.o)

.SILENT:

all: $(NAME)

$(NAME): $(OBJ) $(NAME).h main.c ./libft/libft.a
	printf "\r\033[38;5;11m⌛  MAKE   $(NAME) plz wait ...\033[K\033[0m"
	$(CC) $(OBJ) main.c -o $(NAME) $(LIB)
	echo -en "\r\033[38;5;22m✅  MAKE   $(NAME)\033[K\033[0m"
	echo -en "\r\033[38;5;22m🍺  ENJOY !🍺\033[K\033[0m"

%.o: %.c %.h
	$(CC) $(FLAGS) -c $< -o $@

./libft/libft.a:
	make -C libft/ fclean
	make -C libft/

clean:
	printf "\r\033[38;5;25m⌛  CLEAN  $(NAME) plz wait ...\033[K\033[0m"
	rm -f $(OBJ)
	echo -en "\r\033[38;5;124m❌  CLEAN  $(NAME)\033[K\033[0m"

fclean: clean
	printf "\r\033[38;5;25m⌛  FCLEAN $(NAME) plz wait ...\033[K\033[0m"
	rm -f $(NAME)
	make -C ./libft/ fclean
	echo -en "\r\033[38;5;124m❌  FCLEAN $(NAME)\033[K\033[0m"

re: fclean all

rew: all
	./raytracer
