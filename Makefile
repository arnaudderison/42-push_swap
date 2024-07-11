# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aderison <aderison@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 12:25:14 by arnaud            #+#    #+#              #
#    Updated: 2024/07/11 19:37:23 by aderison         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
OBJ_DIR = obj
CFLAGS = -Wall -Wextra -Werror
LIBFT_I = ./lib/libft/include/
PUSHSWAP_I = ./include/
INCLUDES = -I$(LIBFT_I) -I$(PUSHSWAP_I)

# Colors
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
CYAN=\033[0;36m
NC=\033[0m

#push_swap operation
PUSH_SWAP_OPE = $(addprefix operations/, )

#push_swap sort
PUSH_SWAP_SORT = $(addprefix sort/, )

#push_swap utils
PUSH_SWAP_UTILS = $(addprefix utils/, )

#push_swap main
PUSH_SWAP_MAIN = main.c 

# Push_swap sources
PUSH_SWAP_SRCS = $(addprefix src/, $(PUSH_SWAP_UTILS) \
$(PUSH_SWAP_SORT) $(PUSH_SWAP_OPE) $(PUSH_SWAP_MAIN))
PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:%c=obj/%o)

# Compilation rules
all: $(NAME)

$(NAME): $(PUSH_SWAP_OBJS)
	@mkdir -p $(dir $@)
	@cd ./lib/libft && make
	@cp ./lib/libft/libft.a ./libft.a
	@$(CC) $(CFLAGS) $(INCLUDES) $^ libft.a -o $@
	@echo "${YELLOW}Executable $(PUSH_SWAP) created.${NC}"

obj/%.o: %.c
	@mkdir -p $(dir $@)
	@cd ./lib/libft && make
	@cp ./lib/libft/libft.a ./libft.a
	@echo "\r${CYAN}Compiling $<...${NC}"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< libft.a -o $@
clean:
	@rm -rf obj
	@echo "${GREEN}Object files cleaned.${NC}"

clean-libft:
	@rm -rf ./lib/libft/obj
	@rm -f ./lib/libft/libft.a
	@echo "${RED}All files removed on libft.${NC}"

fclean: clean clean-libft
	@rm -f libft.a
	@rm -f $(NAME)
	@echo "${RED}All files removed.${NC}"

re: fclean all

.PHONY: all clean fclean re
