# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abferrer <abferrer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/12 12:12:12 by abferrer          #+#    #+#              #
#    Updated: 2025/11/03 17:21:13 by abferrer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
SRC = utils.c pipex.c
OBJ = $(SRC:.c=.o)
HEADER = pipex.h

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

GREEN = \033[32m
YELLOW = \033[33m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "  ______ _ _____          _ _ _        "
	@echo " |  ____| |  __ \\        | (_) |       "
	@echo " | |__  | | |__) |__ _ __| |_| |_ __ _ "
	@echo " |  __| | |  ___/ _ \\ '__| | | __/ _\` |"
	@echo " | |____| | |  |  __/ |  | | | || (_| |"
	@echo " |______|_|_|   \\___|_|  |_|_|\\__\\__,_|"
	@echo "$(YELLOW)     To' Compilao Cabesa                $$$ Joseador de Codigo $$$$"


$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -f $(OBJ)
	@echo  "$(GREEN)🧹"
	@echo  "$(YELLOW)  To' Limpio Cabezon"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
