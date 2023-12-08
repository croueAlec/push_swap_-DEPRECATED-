# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acroue <acroue@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 11:51:52 by acroue            #+#    #+#              #
#    Updated: 2023/12/08 15:47:21 by acroue           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
INCLUDE = include/
SRC_DIR = src
SRC = ${addprefix ${SRC_DIR}/, test_push_swap.c parsing.c}
OBJ_DIR = obj
OBJ = ${addprefix ${OBJ_DIR}/, ${SRC:.c=.o}}
LIB_DIR = libft
LIB = libft.a

all: ${NAME}

${NAME}: ${OBJ}
	@make -C ${LIB_DIR} --no-print-directory
	@echo "* Assembling $@"
	@${CC} ${CFLAGS} ${OBJ} -o $@ ${LIB_DIR}/${LIB}

${OBJ_DIR}/%.o: %.c
	@mkdir -p ${OBJ_DIR}
	@mkdir -p ${OBJ_DIR}/${SRC_DIR}
	@${CC} ${CFLAGS} -c $< -I ${INCLUDE} -o $@
	@echo "- Compiling $<"

clean:
	@make clean -C ${LIB_DIR} --no-print-directory
	@echo "! Removing ${OBJ_DIR} files"
	@${RM} ${OBJ_DIR}

fclean: clean
	@make fclean -C ${LIB_DIR} --no-print-directory
	@echo "! Removing ${NAME}"
	@${RM} ${NAME}

re: fclean all

norm:
	@norminette | awk '/Error/';

.PHONY = all clean fclean re norm
