# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/26 11:13:35 by rmatsuka          #+#    #+#              #
#    Updated: 2021/06/08 12:47:24 by rmatsuka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	../push_swap

SRCS	=	main.c \
			push_swap.c \
			ft_sort1.c \
			ft_sort2.c \
			ft_sort3.c \
			three_or_less.c \
			five_or_less.c

OBJS	=	$(SRCS:.c=.o)
RM		=	rm -f
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror #-g -fsanitize=address
LIBFT	=	../libft/libft.a
LIBPS	=	../libft_ps/libft_ps.a
LIBFT_DIR = ../libft
LIBPS_DIR = ../libft_ps


all :		$(NAME)

$(NAME) :	$(OBJS) $(LIBFT) $(LIBPS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(LIBPS)

$(LIBFT) :
			make -C $(LIBFT_DIR)
$(LIBPS) :
			make -C $(LIBPS_DIR)

clean :
		make clean -C $(LIBFT_DIR)
		make clean -C $(LIBPS_DIR)
		$(RM) $(OBJS)

fclean :	clean
		make fclean -C $(LIBFT_DIR)
		make fclean -C $(LIBPS_DIR)
		$(RM) $(NAME)

re :		fclean all

.PHONY:	all clean fclean re