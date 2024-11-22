NAME = 			push_swap

CC = 			cc
#CFLAGS = 		-Wall -Wextra -Werror

GREEN = 		\\033[0;32m
YELLOW = 		\\033[0;33m
RED = 			\\033[0;31m
BLUE = 			\\033[0;34m
MAGENTA = 		\033[0;35m
CYAN = 			\033[0;36m
RESET = 		\\033[0m

LIBFT_DIR =		libft
INCLUDES =		includes/
SRC_DIR =		src/
OBJ_DIR =		obj/

MOVES_DIR =		moves/
MOVES_FILES =	push.c swap.c rotate.c reverse_rotate.c

SRC_FILES = main.c check_input.c push_swap_utils.c short_sort.c utils_sort.c push_swap.c init_func.c math_func.c debug.c \
			$(addprefix $(MOVES_DIR), $(MOVES_FILES))
OBJ_FILES = $(SRC_FILES:.c=.o)

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

LIBFT = $(LIBFT_DIR)/libft.a

# Compter le nombre total de fichiers sources pour le calcul de la barre de progression
TOTAL_STEPS = $(words $(SRC))
CURRENT_STEP = 0

all: setup $(LIBFT) $(NAME)

setup:
	@mkdir -p $(OBJ_DIR) $(OBJ_DIR)/moves

$(LIBFT):
	@echo "$(CYAN)Compiling libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)Program $(NAME) has been created.$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/moves/
	@$(CC) $(CFLAGS) -I $(INCLUDES) -I $(LIBFT_DIR) -o $@ -c $<
	@$(eval CURRENT_STEP=$(shell echo $$(( $(CURRENT_STEP) + 1 ))))
	@$(eval PROGRESS_BAR = $(shell echo $$(( $(CURRENT_STEP) * 100 / $(TOTAL_STEPS) )) ))
	@echo "$(CYAN)[$(PROGRESS_BAR)%]$(RESET) Compiling $<"

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(YELLOW)Object files removed.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo  "$(RED)Program $(NAME) has been deleted.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
