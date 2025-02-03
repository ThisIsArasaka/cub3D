# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olardeux <olardeux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 10:10:04 by olardeux          #+#    #+#              #
#    Updated: 2025/02/03 11:34:46 by olardeux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = clang
CFLAGS = -Wall -Wextra -Werror -g3
MLXFLAGS = -lXext -lX11 -lm -lz
MLX_DIR = ./mlx
MLX = $(MLX_DIR)/libmlx.a
SRC_DIR = ./src
OBJ_DIR = ./obj
INC_DIR = ./inc
SRC_FILE = main.c draw.c move.c init.c
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILE))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILE:.c=.o))

all: $(NAME)

$(NAME): $(MLX) $(OBJ)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -I $(MLX_DIR) $(OBJ) $(MLX) $(MLXFLAGS) -o $(NAME)
	@echo "\033[32m$(NAME) is compiled\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -I $(MLX_DIR) -c $< -o $@
	@echo "\033[33m$@ is compiled\033[0m"

$(MLX):
	@make -C $(MLX_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[31mObject files are removed\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31m$(NAME) is removed\033[0m"

re: fclean all
	@echo "\033[32m$(NAME) is recompiled\033[0m"

.PHONY: all clean fclean re