# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 12:25:14 by arnaud            #+#    #+#              #
#    Updated: 2023/12/16 12:43:23 by arnaud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
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
		srcs/ft_putchar_fd.c \
		srcs/ft_putstr_fd.c \
		srcs/ft_putnbr_fd.c \
		srcs/ft_strlen.c \
		srcs/ft_u_putnbr_fd.c \
		srcs/ft_strlcpy.c \
		srcs/ft_puthex_fd.c

SRCS =  $(addprefix src/libft/, $(LIBFT_SRCS)) \
		$(addprefix src/libft/, $(LIBFT_BONUS)) \
		$(addprefix src/ft_printf/, $(FT_PRINTF_SRCS))

OBJS = $(SRCS:.c=.o)

all: $(NAME)
	 	@echo "${GREEN}Complation completed.${NC}"

$(NAME): $(OBJS)
		@ar rcs $(NAME) $(OBJS)
		@echo "${YELLOW}Libary $(NAME) created.$(NC)"

%.o: %.c
	@echo "${RED}Compiling $<...${NC}"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "${GREEN}Object files cleaned.${NC}"

fclean: clean
	@rm -f $(NAME)
	@echo "${RED}Library removed.${NC}"

re: fclean all

.PHONY: all clean fclean re