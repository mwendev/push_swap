# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/30 17:49:17 by mwen              #+#    #+#              #
#    Updated: 2021/08/31 15:33:07 by mwen             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR		=	libft/
SRC_DIR			=	src/
LIB				=	libft.a
SRCS			=	push_swap.c check.c error.c init_stack.c get.c sort.c\
					swap.c rotate.c push.c has.c sort_large.c sort_helper.c
SRCS_WITHPATH	=	$(addprefix $(SRC_DIR), $(SRCS))
OBJS			=	$(SRCS_WITHPATH:.c=.o)
NAME			=	push_swap
CC				=	gcc
RM				= 	rm -f
FLAGS			=	-Wall -Werror -Wextra

define CAT
      |\      _,,,---,,_
ZZZzz /,`.-'`'    -.  ;-;;,_
     |,4-  ) )-,_. ,\ (  `'-'
    '---''(_/--'  `-'\_)  You've got a libft.a
endef
export CAT
define DONE
 _._     _,-'""`-._
(,-.`._,'(       |\`-/|
    `-.-' \ )-`( , o o)
          `-    \`_`"'-   Time to push swup wup
endef
export DONE

all:			$(LIB) $(NAME)

$(LIB):
				make -C $(LIBFT_DIR)
				@echo "$$CAT"

$(NAME):		$(OBJS)
				@$(CC) $(FLAGS) $(OBJS) $(LIBFT_DIR)*.a -o push_swap
				@echo "$$DONE"

clean:			
				@$(RM) $(OBJS)
				make -C $(LIBFT_DIR) clean
				@echo "Why did you clean me?"

fclean:			clean
				@$(RM) push_swap
				@make -C $(LIBFT_DIR) fclean
				@echo "There is NOTHING LEFT!"

re:				fclean all

.PHONY: all clean fclean re