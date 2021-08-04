# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/30 17:49:17 by mwen              #+#    #+#              #
#    Updated: 2021/07/30 18:29:26 by mwen             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR		=	libft/
LIB				=	libft.a
SRCS			=	push_swap.c check.c error.c init_stack.c get.c sort.c\
					swap.c rotate.c push.c
OBJS			=	$(SRCS:.c=.o)
HEADER_FILES	=	push_swap.h
NAME			=	push_swap
CC				=	gcc
RM				= 	rm -f
CFLAGS			=	-Wall -Werror -Wextra

all:			$(LIB) $(NAME)

$(LIB):
				make -C $(LIBFT_DIR)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)*.a -o push_swap

clean:			
				$(RM) $(OBJS)
				make -C $(LIBFT_DIR) clean
fclean:			
				clean
				$(RM) push_swap

re:				fclean all
.PHONY: all clean fclean re compile