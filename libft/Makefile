# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 16:43:33 by ozasahin          #+#    #+#              #
#    Updated: 2024/05/15 16:46:34 by ozasahin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	\
			err/ft_print_err.c\
			\
			file/ft_putchar_fd.c\
			file/ft_putendl_fd.c\
			file/ft_putnbr_fd.c\
			file/ft_putstr_fd.c\
			\
			free/ft_free_matrix.c\
			free/ft_free2d.c\
			\
			gnl/get_next_line_utils.c\
			gnl/get_next_line.c\
			\
			is/ft_isalnum.c\
			is/ft_isalpha.c\
			is/ft_isascii.c\
			is/ft_isdigit.c\
			is/ft_isprint.c\
			\
			lst/ft_lstadd_back.c\
			lst/ft_lstadd_front.c\
			lst/ft_lstclear.c\
			lst/ft_lstdelone.c\
			lst/ft_lstiter.c\
			lst/ft_lstlast.c\
			lst/ft_lstmap.c\
			lst/ft_lstnew.c\
			lst/ft_lstsize.c\
			\
			mem/ft_memset.c\
			mem/ft_bzero.c\
			mem/ft_calloc.c\
			mem/ft_memchr.c\
			mem/ft_memcmp.c\
			mem/ft_memcpy.c\
			mem/ft_memmove.c\
			\
			nbr/ft_atoi_base.c\
			nbr/ft_atoi.c\
			nbr/ft_itoa.c\
			\
			printf/ft_printf.c\
			printf/ft_printf_utils.c\
			\
			str/ft_split.c\
			str/ft_strrchr.c\
			str/ft_strdup.c\
			str/ft_striteri.c\
			str/ft_strjoin.c\
			str/ft_strlcat.c\
			str/ft_strlcpy.c\
			str/ft_strlen.c\
			str/ft_strmapi.c\
			str/ft_strncmp.c\
			str/ft_strnstr.c\
			str/ft_strrchr.c\
			str/ft_strtrim.c\
			str/ft_substr.c\
			str/ft_tolower.c\
			str/ft_toupper.c\
			\

SRCS_DIR	=	$(addprefix src/, $(SRCS))
OBJS		=	$(addprefix obj/,$(SRCS:.c=.o))

# Controls
CC			=	cc -g3
CFLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	-Iinclude -Ilibft
LINKS		=	-Llibft -lft -L/usr/lib
RM			=	rm -f

# Colors
COLOR_RESET			=	\033[0m
COLOR_RED			=	\033[0;31m
COLOR_GREEN			=	\033[0;32m
COLOR_PURPLE		=	\033[0;95m
COLOR_BLUE			=	\033[0;34m

# Messages
CLEAR_MESSAGE		=	\033[0K\r\c
MESSAGE_COMPILE		=	$(COLOR_BLUE)Compiling :$(COLOR_RESET)
MESSAGE_DONE		=	$(COLOR_GREEN)Compilation completed.$(COLOR_RESET)
MESSAGE_CLEAN		=	$(COLOR_PURPLE)Cleaning up...$(COLOR_RESET)
MESSAGE_CLEAN_DONE	=	$(COLOR_PURPLE)Cleanup completed.$(COLOR_RESET)

all:	${NAME}

${NAME}:	${OBJS}
			@ar rc ${NAME} ${OBJS}

obj/%.o: src/%.c | obj
	@echo "[...] libft... $(MESSAGE_COMPILE) $*.c\r\c"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(CLEAR_MESSAGE)"

obj:
		@mkdir -p obj

clean:
		@${RM} -r obj

fclean:	clean
		@${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
