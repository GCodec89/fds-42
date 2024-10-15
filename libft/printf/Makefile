# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 11:14:22 by gonolive          #+#    #+#              #
#    Updated: 2024/05/03 15:30:24 by gonolive         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a

CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror
RM 			= rm -rf

SRCS 		= ft_printf.c ft_printnbr.c ft_printptr.c ft_printstr.c \
				ft_putchar.c ft_putptrhex.c ft_utoa.c

OBJS 		= $(SRCS:.c=.o)

all: 		$(NAME)

$(NAME): 	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re