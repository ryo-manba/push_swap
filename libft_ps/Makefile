# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/01 19:58:04 by rmatsuka          #+#    #+#              #
#    Updated: 2021/06/08 12:37:37 by rmatsuka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft_ps.a
SRCS	=	actions1.c \
			actions2.c \
			actions3.c \
			exit_fatal.c \
			make_dlist.c \
			quick_sort.c \
			utils1.c \
			utils2.c

OBJS	=	$(SRCS:.c=.o)
RM		=	rm -f
LIBC	=	ar rcs
CC		= 	gcc
CFLAGS	=	-Wall -Wextra -Werror #-g -fsanitize=address

all:		$(NAME)

$(NAME):	$(OBJS)
			$(LIBC) $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re