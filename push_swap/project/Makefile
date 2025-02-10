# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sarunomane <sarunomane@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/07 06:04:02 by zsonie            #+#    #+#              #
#    Updated: 2025/02/10 16:00:12 by sarunomane       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------------------------------VAR----------------------------------------------------------#
NAME= test
CC= gcc
FLAGS= -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3
OBJ_DIR= obj
SRC_DIR= src
INC_DIR= includes

OBJ= $(SRC:%.c=$(OBJ_DIR)/%.o)

SRCS=$(addprefix $(SRC_DIR),$(SRC:%.c))

SRC= error.c \
		operation.c \
		push_swap.c

SRC_OPERATIONS= push.c \
				rotate.c \
				swap.c

#--------------------------------------------RULES--------------------------------------------------------#

$(NAME): $(OBJ_DIR) $(OBJ)
	@echo "\n$(_CYAN)Compiling objects contained in $(_UNDER)$(_GREEN)$<$(_END)$(_CYAN) in executable $(_UNDER)$(_PURPLE)$@$(_END) $(_WHITE)"
	@$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L./mlx-linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@echo "$(_YELLOW)Creating object $(_UNDER)$(_GREEN)$@$(_END)$(_YELLOW) from source: $(_UNDER)$(_GREEN)$<$(_END)$(_WHITE)"
	@$(CC) $(FLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR):
	@echo "$(_CYAN)Creating $(_UNDER)$(_GREEN)$@$(_END)$(_CYAN) directory$(_WHITE)\n"
	@mkdir -p $(OBJ_DIR)
#-------------------------------------------ACTIONS-------------------------------------------------------#

all: $(NAME)

clean:
	@echo "\n$(_CYAN)Cleaning $(_UNDER)$(_RED)$(OBJ_DIR)$(_END)$(_CYAN) directory $(_WHITE)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(_CYAN)Cleaning executable $(_UNDER)$(_RED)$(NAME)$(_END) $(_WHITE)\n"
	@rm -rf $(NAME)

re: fclean all

#-------------------------------------------PHONY---------------------------------------------------------#

.PHONY: all clean fclean re

#------------------------------------------COLORS---------------------------------------------------------#

# This is a minimal set of ANSI/VT100 color codes
_END=\033[0m
_BOLD=\033[1m
_UNDER=\033[4m
_REV=\033[7m

# Colors
_GREY=\033[30m
_RED=\033[31m
_GREEN=\033[32m
_YELLOW=\033[33m
_BLUE=\033[34m
_PURPLE=\033[35m
_CYAN=\033[36m
_WHITE=\033[37m

# Inverted, i.e. colored backgrounds
_IGREY=\033[40m
_IRED=\033[41m
_IGREEN=\033[42m
_IYELLOW=\033[43m
_IBLUE=\033[44m
_IPURPLE=\033[45m
_ICYAN=\033[46m
_IWHITE=\033[47m