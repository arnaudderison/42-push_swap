# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aderison <aderison@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 12:25:14 by arnaud            #+#    #+#              #
#    Updated: 2024/07/15 20:05:30 by aderison         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
OBJ_DIR = obj
CFLAGS = -Wall -Wextra -Werror

# Colors
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
CYAN=\033[0;36m
NC=\033[0m

#Libft string
LIBFT_STRING = $(addprefix string/, ft_atoi.c ft_isprint.c ft_putchar_fd.c \
ft_puthex_fd.c ft_putptr.c ft_split.c ft_strcmp.c ft_striteri.c ft_strlcat.c \
ft_strlen.c ft_strncmp.c ft_strrchr.c ft_substr.c ft_toupper.c ft_isalpha.c \
ft_pointer.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strchr.c \
ft_strdup.c ft_strjoin.c ft_strlcpy.c ft_strmapi.c ft_strnstr.c ft_strtrim.c \
ft_tolower.c ft_u_putnbr_fd.c)

#Libft number
LIBFT_NUM = $(addprefix number/, ft_isalnum.c ft_isascii.c ft_isdigit.c ft_itoa.c)

#Libft memory
LIBFT_MEM = $(addprefix memory/, ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memmove.c ft_memset.c ft_free.c ft_free_matrice.c)

#Libft list
LIBFT_LST = $(addprefix list/, ft_lstadd_back_bonus.c ft_lstclear_bonus.c \
ft_lstiter_bonus.c ft_lstmap_bonus.c ft_lstsize_bonus.c ft_lstadd_front_bonus.c \
ft_lstdelone_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c)

#Libft ft_printf
LIBFT_PRINTF = ft_printf/ft_printf.c

#libft gnl
LIBFT_GNL = gnl/get_next_line.c

# Libft sources
LIBFT_SRCS = $(addprefix src/, $(LIBFT_STRING) $(LIBFT_NUM) $(LIBFT_MEM) \
$(LIBFT_LST) $(LIBFT_PRINTF) $(LIBFT_GNL))
LIBFT_OBJS = $(LIBFT_SRCS:%c=obj/%o)

# Compilation rules
all: $(NAME)

$(NAME): $(LIBFT_OBJS)
	@ar rcs $(NAME) $^
	@echo "${YELLOW}Library $(NAME) created.${NC}"

obj/%.o: %.c
	@mkdir -p $(dir $@)
	@echo -n "\r${CYAN}Compiling $<...${NC}"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf obj
	@echo "${GREEN}Object files cleaned.${NC}"

fclean: clean
	@rm -r libft.a
	@echo "${RED}All files removed.${NC}"

re: fclean all

.PHONY: all clean fclean re
