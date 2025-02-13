#---------------COLORS---------------#
BLACK=	$(shell tput -Txterm setaf 0)
RED= 	$(shell tput -Txterm setaf 1)
GREEN= 	$(shell tput -Txterm setaf 2)
WHITE= 	$(shell tput -Txterm setaf 7)
YELLOW=	$(shell tput -Txterm setaf 3)
BLUE=	$(shell tput -Txterm setaf 6)
PURPLE=	$(shell tput -Txterm setaf 5)
END= 	$(shell tput -Txterm sgr0)
BOLD=   \033[1m
#---------------COLORS---------------#

CC = cc

FLAG = -Wall -Werror -Wextra -g3

SUPFLAG = -lXext -lX11 -lm -lz

INCLUDE = -I . -I lib/libft/ -I ./inc

NAME = cub3D

SOURCES = main.c \
destroyer.c \
src/parsing/init.c \
src/parsing/map_check.c \
src/parsing/parsing.c \
src/parsing/utils1.c \
src/parsing/utils2.c \
src/parsing/utils3.c \
src/parsing/verify.c \
src/raycasting/dda.c \
src/raycasting/draw.c \
src/raycasting/init.c \
src/raycasting/minimap.c \
src/raycasting/move.c \
src/raycasting/pixel.c \
src/raycasting/wall_utils.c \


OBJ = $(SOURCES:%.c=obj/%.o)

DEP = $(OBJ:.o=.d)

OBJPATH = obj

BAR_SIZE = 50

TOTAL_FILES		:= $(words $(SOURCES))

COMPILED_FILES	:= 0

all : $(NAME)
	@echo "$(BOLD)$(GREEN)Compilation Done.\n$(END)"

$(NAME) : compile $(OBJ) 
	@make bonus -sC lib/libft/
	@mv lib/libft/libft.a obj/lib.a
	@make fclean -sC lib/libft
	@echo "$(BOLD)$(GREEN)Lib compiled.\n$(END)"
	@$(CC) $(OBJ) $(SUPFLAG) -o $(NAME) obj/lib.a  ./lib/mlx/libmlx.a

-include $(DEP)

compile : 
	@make -sC ./lib/mlx/

$(OBJPATH)/%.o : %.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAG) -c -MMD -MP $< -o $@ $(INCLUDE)
	@$(eval COMPILED_FILES := $(shell echo $$(($(COMPILED_FILES)+1))))
	@echo -n ""
	@for i in `seq 1 $(shell echo "$$(($(COMPILED_FILES)*$(BAR_SIZE)/$(TOTAL_FILES)))")`; do \
		echo -n "$(GREEN)▰$(END)" ; \
	done
	@for i in `seq 1 $(shell echo "$$(($(BAR_SIZE)-$(COMPILED_FILES)*$(BAR_SIZE)/$(TOTAL_FILES)))")`; do \
		echo -n "▱" ; \
	done
	@echo -n " [$(shell echo "scale=2; $(COMPILED_FILES)/$(TOTAL_FILES) * 100" | bc)%] "
	@printf "\e[0K\r"

clean :
	@make clean -sC lib/libft/
	@make clean -sC lib/mlx/
	@rm -r $(OBJPATH)

fclean : clean
	@make fclean -sC lib/libft/
	@rm -f $(NAME) obj/lib.a
	@echo "$(GREEN)Cleaning Done.$(END)"

re : fclean all

.PHONY : re fclean clean all