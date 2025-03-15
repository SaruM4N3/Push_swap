# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/14 20:19:25 by zsonie            #+#    #+#              #
#    Updated: 2025/03/14 20:32:05 by zsonie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBFT= libft/libft.a
LIB= -Llibft

INC = -I includes
SRCDIR = src
OBJDIR = obj

SRCS = pushswap.c \
		ft_atoi.c \
		parsing.c \
		quicksort.c \
		stack_utils.c \
		operations/swap.c \
		operations/rotate.c \
		operations/reverserotate.c \
		operations/push.c

OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo "$(GREEN)Making executable$(RESET)"
	@$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJS) $(LIB)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@echo "$(YELLOW)Converting $(GREEN)$< $(YELLOW)to $(GREEN)$@$(RESET)"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)/operations

$(LIBFT):
	@echo "Make libft"
	@$(MAKE) -s -j -C ./libft

clean:
	@echo "$(RED)Cleaning $(GREEN)$(OBJDIR) $(RED)dir"
	@$(RM) $(OBJS)
	@$(RM) -r $(OBJDIR)

fclean: clean
	@echo "$(RED)Full clean"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

.DEFAULT_GOAL = all
# COLORS
RED    = \033[31m
GREEN  = \033[32m
YELLOW = \033[33m
RESET  = \033[0m
