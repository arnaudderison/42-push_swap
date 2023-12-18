# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 12:25:14 by arnaud            #+#    #+#              #
#    Updated: 2023/12/18 10:21:53 by arnaud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
PUSH_SWAP = push_swap.out
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./srcs/libft/libft
FT_PRINTF_DIR = ./srcs/libft/ft_printf
INCLUDES = -I$(LIBFT_DIR) -I $(FT_PRINTF_DIR)/includes

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
CYAN=\033[0;36m
NC=\033[0m

LIBFT_SRCS = 	ft_isdigit.c \
		ft_memset.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_isprint.c\
		ft_putchar_fd.c \
		ft_strlcat.c \
		ft_substr.c \
		ft_atoi.c \
		ft_itoa.c \
		ft_putendl_fd.c \
		ft_strlcpy.c \
		ft_tolower.c \
		ft_bzero.c \
		ft_putnbr_fd.c \
		ft_strlen.c \
		ft_toupper.c \
		ft_calloc.c \
		ft_memchr.c \
		ft_putstr_fd.c \
		ft_strmapi.c \
		ft_isalnum.c \
		ft_memcmp.c \
		ft_split.c \
		ft_strncmp.c \
		ft_isalpha.c \
		ft_memcpy.c \
		ft_strchr.c \
		ft_strnstr.c \
		ft_isascii.c \
		ft_memmove.c \
		ft_strdup.c \
		ft_strrchr.c \
		ft_striteri.c

LIBFT_BONUS = ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c

FT_PRINTF_SRCS = 	ft_printf.c \
		srcs/ft_pointer.c \
		srcs/ft_putchar_fd_printf.c \
		srcs/ft_putstr_fd_printf.c \
		srcs/ft_putnbr_fd_printf.c \
		srcs/ft_strlen_printf.c \
		srcs/ft_u_putnbr_fd_printf.c \
		srcs/ft_strlcpy_printf.c \
		srcs/ft_puthex_fd_printf.c

PUSH_SWAP_SRCS = push_swap.c \
				srcs/utils/filter_atoi.c \
				srcs/utils/sort_utils.c \
				srcs/operations/swap.c \
				srcs/operations/rotate.c \
				srcs/operations/push.c \
				srcs/actions/actions_swap.c \
				srcs/actions/actions_push.c \
				srcs/actions/actions_reverse_rotate.c \
				srcs/actions/actions_rotate.c \
				srcs/sort/sort.c

SRCS =  $(addprefix srcs/libft/libft/, $(LIBFT_SRCS)) \
		$(addprefix srcs/libft/libft/, $(LIBFT_BONUS)) \
		$(addprefix srcs/libft/ft_printf/, $(FT_PRINTF_SRCS)) \
		$(PUSH_SWAP_SRCS)

OBJS = $(SRCS:.c=.o)
PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)

all: $(NAME) $(PUSH_SWAP)
	 	@echo "${GREEN}Complation completed.${NC}"

$(NAME): $(OBJS)
		@ar rcs $(NAME) $(OBJS)
		@echo "${YELLOW}Libary $(NAME) created.$(NC)"

$(PUSH_SWAP): $(OBJS) $(PUSH_SWAP_OBJS)
	@$(CC) -g $(PUSH_SWAP_OBJS) -L. -lft -o $(PUSH_SWAP)
	@echo "${YELLOW}Executable $(PUSH_SWAP) created.${NC}"

%.o: %.c
	@echo "${CYAN}Compiling $<...${NC}"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS) $(PUSH_SWAP_OBJS)
	@echo "${GREEN}Object files cleaned.${NC}"

fclean: clean
	@rm -f $(NAME) $(PUSH_SWAP)
	@echo "${RED}Library removed.${NC}"

re: fclean all

.PHONY: all clean fclean re