# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 11:52:13 by ozasahin          #+#    #+#              #
#    Updated: 2024/05/29 15:44:40 by ozasahin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL: $(NAME)

NAME	=	philo

SRC		=		\
				src/check_args.c\
				src/closing.c\
				src/diner_routing.c\
				src/do_simulation.c\
				src/init.c\
				src/lft.c\
				src/main.c\
				src/memory.c\
				src/monitor.c\
				src/mutex_access.c\
				src/mutex_handler.c\
				src/thread_handler.c\
				src/time.c

OBJ		=	$(patsubst src/%.c, obj/%.o, $(SRC))

# Controls
CC			=	cc
CFLAGS		=	-Werror -Wall -Wextra
INCLUDES	=	-Iinclude
# LINKS		=
RM			=	rm -rf

# Colors
COLOR_RESET			=	\033[0m
COLOR_RED			=	\033[0;31m
COLOR_GREEN			=	\033[0;32m
COLOR_PURPLE		=	\033[0;95m
COLOR_BLUE			=	\033[0;34m

# Colored Messages
MESSAGE_CLEAR		=	\033[0K\r\c
MESSAGE_OK			=	[\033[32mOK\033[0m]
MESSAGE_COMPILE		=	$(COLOR_BLUE)Compiling :$(COLOR_RESET)
MESSAGE_DONE		=	$(COLOR_GREEN)Compilation completed.$(COLOR_RESET)
MESSAGE_DONE2		=	$(MESSAGE_OK) philo compiled.
MESSAGE_CLEAN		=	$(COLOR_PURPLE)Cleaning up...$(COLOR_RESET)
MESSAGE_CLEAN_DONE	=	$(COLOR_PURPLE)Cleanup completed.$(COLOR_RESET)

all:		$(NAME)

m:			clear $(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME)
	@echo "$(MESSAGE_DONE2)"

obj/%.o:	src/%.c
	@echo "[...] libft... $(MESSAGE_COMPILE) $*.c\r\c"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(MESSAGE_CLEAR)"

clean:
	@echo "$(MESSAGE_CLEAN)\c"
	@$(RM) obj
	@echo "$(MESSAGE_CLEAN_DONE)"

fclean:		clean
	@$(RM) $(NAME)

re:		fclean all

clear:
	clear

ARG := $(shell norminette | grep Error: | wc -l)

norm:
	@if norminette | grep -v OK; then \
		echo "$(COLOR_RED)$(ARG) norm violations found$(COLOR_RESET)"; \
	else \
		echo "$(COLOR_GREEN)All OK!"; \
	fi

.PHONY: all clean fclean re