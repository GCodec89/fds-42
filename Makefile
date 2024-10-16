# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/28 13:14:45 by gonolive          #+#    #+#              #
#    Updated: 2024/10/16 09:18:15 by gonolive         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
CC			=	cc
SRCS		=	srcs/so_long.c \
				srcs/error.c \
				srcs/inits.c \
				srcs/inits_utils.c \
				srcs/valid_map.c \
				srcs/freeza.c \
				srcs/render.c \
				srcs/hookie.c \
				srcs/press_left.c \
				srcs/press_right.c \
				srcs/press_up.c \
				srcs/press_down.c \

LIBFT		=	libft/libft.a
CFLAGS		=	-Wall -Wextra -Werror -g
MLXFLAGS	=	-L ./mlx/ -lmlx -framework OpenGL -framework AppKit -lz
X11FLAGS	=	-I/opt/X11/include -L/opt/X11/lib -lX11
RM			=	rm -f
OBJS		=	$(SRCS:%.c=%.o)

ifeq ($(shell uname), Linux)
MLXFLAGS	=	-L ./mlx_linux/ -lmlx -Ilmlx -lXext -lX11
X11FLAGS	=	-I/usr/include/X11 -L/usr/lib/X11 -lX11
endif

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C libft	
			make clean -C libft
			$(CC) $(SRCS) $(LIBFT) $(MLXFLAGS) $(X11FLAGS) $(CFLAGS) -o $(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) -I/opt/X11/include -Imlx -c $< -o $@

run:		all

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			$(RM) *.out
			make fclean -C libft/

re:			fclean all

.PHONY:		all clean fclean re