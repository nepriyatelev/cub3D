# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: medeana <medeana@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/19 14:12:25 by medeana           #+#    #+#              #
#    Updated: 2022/05/03 15:33:46 by medeana          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D

SRC		=	main.c\
			print_error.c\
			parser/checking_card_information.c\
			parser/reading_a_file.c\
			parser/recording_file_information.c\
			parser/parser.c\
			parser/init.c\
			raycasting/draw_pixel_map.c\
			raycasting/move.c \
			raycasting/move_utils.c \
			raycasting/ray.c \
			raycasting/ray_utils.c \
			raycasting/texture.c

HEADER	=	-I./include -I./mlx

FLAGS	=	-Wall -Wextra -Werror

LIBFT	=	./libft/libft.a

LIBMLX	=	./mlx/libmlx.a

MLXFLAGS	=	-lmlx -framework OpenGL -framework AppKit

RM		=	rm -f

OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	@make -C ./libft
	@make -C ./mlx
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(LIBMLX) $(MLXFLAGS) -o $(NAME)

%.o: %.c $(HEADER) Makefile
	@$(CC) $(FLAGS) -c $< -o $@

clean	:
	rm -f $(OBJ)
	make -C ./libft clean
	make -C ./mlx clean

fclean	:	clean
	rm -f $(NAME)
	make -C ./libft fclean

re : fclean all

norm : 
	norminette ./libft/*.c ./parser/*.c ./raycasting/*.c *.c cub.h

.PHONY: all clean fclean re