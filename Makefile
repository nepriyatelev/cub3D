# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 18:01:34 by modysseu          #+#    #+#              #
#    Updated: 2022/04/16 22:11:38 by modysseu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D

SRC		=	main.c\
			print_error.c\
			parser/checking_card_information.c\
			parser/reading_a_file.c\
			parser/recording_file_information.c\
			parser/parser.c\
			drawing_the_map.c

HEADER	=	-I./include -I./minilibx

FLAGS	=	-Wall -Wextra -Werror

LIBFT	=	./libft/libft.a

LIBMLX	=	./minilibx/libmlx.a

MLXFLAGS	=	-lmlx -framework OpenGL -framework AppKit
#MLXFLAGS= -I /usr/include -g -L /usr/lib -lX11 -lmlx -lXext -lm -fsanitize=address

RM		=	rm -f

OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	@make -C ./libft
	@make -C ./minilibx
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(LIBMLX) $(MLXFLAGS) -o $(NAME)

%.o: %.c $(HEADER) Makefile
	@$(CC) $(FLAGS) -c $< -o $@

clean	:
	rm -f $(OBJ)
	make -C ./libft clean
	make -C ./minilibx clean

fclean	:	clean
	rm -f $(NAME)
	make -C ./libft fclean

re : fclean all

.PHONY: all clean fclean re