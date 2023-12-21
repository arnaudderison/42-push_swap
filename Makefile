# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 12:25:14 by arnaud            #+#    #+#              #
#    Updated: 2023/12/21 14:18:53 by arnaud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
PUSH_SWAP = push_swap
PUSH_SWAP_CHECKER = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./src/libft/libft
FT_PRINTF_DIR = ./src/libft/ft_printf
GNL_DIR = ./src/libft/gnl
INCLUDES = -I$(LIBFT_DIR) -I $(FT_PRINTF_DIR)/includes -I$(GNL_DIR)

# Colors
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
CYAN=\033[0;36m
NC=\033[0m

# Libft sources
LIBFT_SRCS = $(wildcard $(LIBFT_DIR)/*.c)
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

# ft_printf sources
FT_PRINTF_SRCS = $(wildcard $(FT_PRINTF_DIR)/*.c) \
				$(wildcard $(FT_PRINTF_DIR)/srcs/*.c)
FT_PRINTF_OBJS = $(FT_PRINTF_SRCS:.c=.o)

# GNL sources
GNL_SRCS = $(wildcard $(GNL_DIR)/*.c)
GNL_OBJS = $(GNL_SRCS:.c=.o)

# push_swap sources
PUSH_SWAP_SRCS = $(wildcard ./src/*/*.c) \
				push_swap.c
PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)

# checker sources
PUSH_SWAP_CHECKER_SRCS = $(wildcard ./src/*/*.c) \
						checker.c
PUSH_SWAP_CHECKER_OBJS = $(PUSH_SWAP_CHECKER_SRCS:.c=.o)

# Compilation rules
all: $(NAME) $(PUSH_SWAP) $(PUSH_SWAP_CHECKER)

$(NAME): $(LIBFT_OBJS) $(FT_PRINTF_OBJS) $(GNL_OBJS)
	@ar rcs $(NAME) $^
	@echo "${YELLOW}Library $(NAME) created.${NC}"

$(PUSH_SWAP): $(PUSH_SWAP_OBJS) $(NAME)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "${YELLOW}Executable $(PUSH_SWAP) created.${NC}"

$(PUSH_SWAP_CHECKER): $(PUSH_SWAP_CHECKER_OBJS) $(NAME)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "${YELLOW}Executable $(PUSH_SWAP_CHECKER) created.${NC}"

%.o: %.c
	@echo "${CYAN}Compiling $<...${NC}"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(LIBFT_OBJS) $(FT_PRINTF_OBJS) $(GNL_OBJS) $(PUSH_SWAP_OBJS) $(PUSH_SWAP_CHECKER_OBJS)
	@echo "${GREEN}Object files cleaned.${NC}"

fclean: clean
	@rm -f $(NAME) $(PUSH_SWAP) $(PUSH_SWAP_CHECKER)
	@echo "${RED}All files removed.${NC}"

re: fclean all

.PHONY: all clean fclean re
