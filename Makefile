# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aderison <aderison@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 12:25:14 by arnaud            #+#    #+#              #
#    Updated: 2024/07/08 20:56:37 by aderison         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
PUSH_SWAP = push_swap
PUSH_SWAP_CHECKER = checker
LIBFT_I = ./lib/libft/include/
PUSHSWAP_I = ./include/
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(LIBFT_I) -I$(PUSHSWAP_I)

# Colors
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
CYAN=\033[0;36m
NC=\033[0m

##Libft string
LIBFT_STRING = $(addprefix string/, ft_atoi.c ft_putchar_fd.c ft_putnbr_fd.c \
ft_split.c ft_strdup.c ft_strlcat.c ft_strmapi.c ft_strrchr.c ft_tolower.c \
ft_isalpha.c ft_putendl_fd.c ft_putptr.c ft_strchr.c ft_strcmp.c ft_striteri.c ft_strlcpy.c \
ft_strncmp.c ft_strtrim.c ft_toupper.c ft_isprint.c ft_pointer.c ft_puthex_fd.c \
ft_putstr_fd.c ft_strlen.c ft_u_putnbr_fd.c ft_strnstr.c ft_strjoin.c)

#Libft number
LIBFT_NUM = $(addprefix number/, ft_isalnum.c ft_isascii.c ft_isdigit.c ft_itoa.c)

#Libft memory
LIBFT_MEM = $(addprefix memory/, ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memmove.c ft_memset.c ft_free.c ft_free_matrice.c)

#Libft list
LIBFT_LST = $(addprefix list/, ft_lstadd_back_bonus.c ft_lstclear_bonus.c \
ft_lstiter_bonus.c ft_lstmap_bonus.c ft_lstsize_bonus.c ft_lstadd_front_bonus.c \
ft_lstdelone_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c)

#Libft process
LIBFT_PROC = $(addprefix process/, ft_close_pipes.c ft_create_pipes.c)

#Libft GNL
LIBFT_GNL = $(addprefix gnl/, get_next_line.c)

#Libft ft_printf
LIBFT_PRINTF = ft_printf/ft_printf.c

# Libft sources
LIBFT_SRCS = $(addprefix lib/libft/src/, $(LIBFT_STRING) $(LIBFT_NUM) $(LIBFT_MEM) \
$(LIBFT_LST) $(LIBFT_PRINTF) $(LIBFT_PROC) $(LIBFT_GNL))
LIBFT_OBJS = $(LIBFT_SRCS:%c=obj/%o)

#push swap src
PUSH_SWAP_ACTIONS = $(addprefix src/actions/, actions_move_min.c actions_push.c \
actions_reverse_rotate.c actions_rotate.c actions_swap.c)

PUSH_SWAP_OPERATION = $(addprefix src/operations/, push.c rotate.c swap.c)

PUSH_SWAP_SORT = $(addprefix src/sort/, sort.c)

PUSH_SWAP_UTILS = $(addprefix src/utils/, filter_atoi.c ft_atoi_malloc.c ft_init.c \
ft_intbit_count.c ft_is_validate.c ft_lstintmax.c ft_lstposintmin.c \
ft_lstsorted.c sort_utils.c optimised.c quicksort.c)

PUSH_SWAP_SRC = push_swap.c $(PUSH_SWAP_ACTIONS) $(PUSH_SWAP_OPERATION) $(PUSH_SWAP_SORT) $(PUSH_SWAP_UTILS)
PUSH_SWAP_OBJS = $(PUSH_SWAP_SRC:%c=obj/%o)

PUSH_SWAP_CHECKER_SRC = checker.c $(PUSH_SWAP_OBJS)
PUSH_SWAP_CHECKER_OBJS = $(PUSH_SWAP_CHECKER_SRC:%c=obj/%o)

# Compilation rules
all: $(NAME) $(PUSH_SWAP) $(PUSH_SWAP_CHECKER)

$(NAME): $(LIBFT_OBJS)
	@ar rcs $(NAME) $^
	@echo "${YELLOW}Library $(NAME) created.${NC}"

$(PUSH_SWAP): $(PUSH_SWAP_OBJS) $(NAME)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "${YELLOW}Executable $(PUSH_SWAP) created.${NC}"

$(PUSH_SWAP_CHECKER): $(PUSH_SWAP_CHECKER_OBJS) $(NAME)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "${YELLOW}Executable $(PUSH_SWAP_CHECKER) created.${NC}"

obj/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "${CYAN}Compiling $<...${NC}"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf obj
	@echo "${GREEN}Object files cleaned.${NC}"

fclean: clean
	@rm -f $(NAME) $(PUSH_SWAP) $(PUSH_SWAP_CHECKER)
	@echo "${RED}All files removed.${NC}"

re: fclean all

.PHONY: all clean fclean re
