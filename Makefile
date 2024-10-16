# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/28 13:14:45 by gonolive          #+#    #+#              #
#    Updated: 2024/10/16 20:31:28 by gonolive         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
BONUS_NAME	=	bonus_so_long
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

BONUS_SRCS	=	bonus/bonus_so_long.c \
				bonus/bonus_error.c \
				bonus/bonus_inits.c \
				bonus/bonus_inits_utils.c \
				bonus/bonus_valid_map.c \
				bonus/bonus_freeza.c \
				bonus/bonus_render.c \

LIBFT		=	libft/libft.a
CFLAGS		=	-Wall -Wextra -Werror -g
MLXFLAGS	=	-L ./mlx/ -lmlx -framework OpenGL -framework AppKit -lz
X11FLAGS	=	-I/opt/X11/include -L/opt/X11/lib -lX11
RM			=	rm -f
OBJS		=	$(SRCS:%.c=%.o)
BONUS_OBJS	=	$(BONUS_SRCS:%.c=%.o)

ifeq ($(shell uname), Linux)
MLXFLAGS	=	-L ./mlx_linux/ -lmlx -Ilmlx -lXext -lX11
X11FLAGS	=	-I/usr/include/X11 -L/usr/lib/X11 -lX11
endif

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C libft	
			make clean -C libft
			$(CC) $(SRCS) $(LIBFT) $(MLXFLAGS) $(X11FLAGS) $(CFLAGS) -o $(NAME)

bonus:		$(BONUS_NAME)

$(BONUS_NAME):	$(BONUS_OBJS)
				make -C libft
				make clean -C libft
				$(CC) $(BONUS_SRCS) $(LIBFT) $(MLXFLAGS) $(X11FLAGS) $(CFLAGS) -o $(BONUS_NAME)

%.o:		%.c
			$(CC) $(CFLAGS) -I/opt/X11/include -Imlx -c $< -o $@

run:		all

clean:
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
			$(RM) $(NAME) $(BONUS_NAME)
			$(RM) *.out
			make fclean -C libft/

re:			fclean all

.PHONY:		all clean fclean re bonus