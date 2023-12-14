# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acroue <acroue@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 11:51:52 by acroue            #+#    #+#              #
#    Updated: 2023/12/14 09:21:07 by acroue           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
INCLUDE = include/
SRC_DIR = src
SRC = ${addprefix ${SRC_DIR}/, test_push_swap.c parsing.c swap_functions.c}
OBJ_DIR = obj
OBJ = ${addprefix ${OBJ_DIR}/, ${SRC:.c=.o}}
LIB_DIR = libft
LIB = libft.a

DEFAULT	= \033[0m
BLACK	= \033[0;30m
RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
PURPLE	= \033[0;35m
CYAN	= \033[0;36m
BWHITE	= \033[1;37m

all: ${NAME}

${NAME}: ${OBJ}
	@make -C ${LIB_DIR} --no-print-directory
	@echo "$(GREEN)* Assembling $(BWHITE)$@$(DEFAULT)"
	@${CC} ${CFLAGS} ${OBJ} -o $@ ${LIB_DIR}/${LIB}

${OBJ_DIR}/%.o: %.c
	@mkdir -p ${OBJ_DIR}
	@mkdir -p ${OBJ_DIR}/${SRC_DIR}
	@${CC} ${CFLAGS} -c $< -I ${INCLUDE} -o $@
	@echo "$(CYAN)- Compiling$(DEFAULT) $<"

clean:
	@make clean -C ${LIB_DIR} --no-print-directory
	@echo "$(RED)! Removing$(DEFAULT) ${OBJ_DIR} files"
	@${RM} ${OBJ_DIR}

fclean: clean
	@make fclean -C ${LIB_DIR} --no-print-directory
	@echo "$(RED)! Removing$(DEFAULT) ${NAME}"
	@${RM} ${NAME}

re: fclean all

norm:
	@norminette $(SRC_DIR) | awk '/'Error'/ {print; found=1} END {if (!found) print "$(PURPLE)Norm O.K.$(DEFAULT)"}'
	@norminette $(LIB_DIR) | awk '/'Error'/ {print; found=1} END {if (!found) print "$(YELLOW)Norm libft O.K.$(DEFAULT)"}'

.PHONY = all clean fclean re norm
