# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 17:37:16 by lbastien          #+#    #+#              #
#    Updated: 2023/01/30 15:05:24 by lbastien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Standard variables

NAME		=	get_next_line.a
CC			=	gcc
CFLAGS		=	-D BUFFER_SIZE=1 -Wall -Werror -Wextra -I
RM			=	rm -f
AR			=	ar rcs

#Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources

SRCS 		= 	get_next_line.c get_next_line_utils.c
OBJS 		=	$(SRCS:.c=.o)

#exe

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(AR) $(NAME) $(OBJS)
			@echo "$(GREEN)Successfully compiled!$(DEF_COLOR)"

%.o: 		%.c
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) -I./ -c $< -o $@
			
clean:
			@$(RM) $(OBJS)
			@echo "$(BLUE)Objects files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@echo "$(CYAN)Executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything!$(DEF_COLOR)"

norm:
	@norminette $(SRCS) | grep -v Norme -B1 || true

.PHONY: all, clean, fclean, re, norm
