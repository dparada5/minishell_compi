# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dparada <dparada@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 11:04:19 by dparada           #+#    #+#              #
#    Updated: 2024/06/11 16:05:09 by dparada          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= clang
NAME 	= minishell
#NAME_BONUS = checker_bonus
USER 	= dparada
CFLAGS 	= -Wall -Wextra -Werror -g
LIBFT = lib/LIBFT
SRC_DIR = src/
BONUS_DIR = src_bonus/
OBJ_DIR = obj/
LIB = -lreadline

MAGENTA = \033[35;1m
YELLOW  = \033[33;1m
GREEN   = \033[32;1m
WHITE   = \033[37;1m
RESET   = \033[0m
GRAY 	= \033[0;90m
BLUE    = \033[34;1m
CYAN    = \033[37;1m
BOLD	= \033[1m
RED		= \033[31;1m

SRC_FILES = main token token_utils error env states actions prints \
redirecc free quotes pruebis

#SRC_FILES_BONUS = main 

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o,$(SRC_FILES)))

#SRC_BONUS = $(addprefix $(BONUS_DIR), $(addsuffix .c, $(SRC_FILES_BONUS)))
#OBJ_BONUS = $(addprefix $(OBJ_DIR), $(addsuffix .o,$(SRC_FILES_BONUS)))

OBJF = .cache_exists

all: $(NAME)

$(NAME): compiling $(OBJ)
		@echo
		@make all -C $(LIBFT)
		@$(CC) $(CFLAGS) $(OBJ) $(LIB) -L$(LIBFT) -lft -o $(NAME)
		@echo "$(MAGENTA)Minishell compiled!$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
		@echo "$(BLUE)Compiling: $(RESET)$(notdir $<)"
		@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(BONUS_DIR)%.c | $(OBJF)
		@echo "$(BLUE)Compiling: $(RESET)$(notdir $<)"
		@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
		@mkdir -p $(OBJ_DIR)

#bonus:	$(NAME_BONUS)

#$(NAME_BONUS): compiling_bonus $(OBJ_BONUS)
# @echo
# @$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)
# @echo "$(MAGENTA)Minishell bonus compiled!$(RESET)"

compiling:
		@echo "$(YELLOW)Compiling Minishell: $(RESET)"

#compiling_bonus:
#@echo "$(YELLOW)Compiling Minishell Bonus: $(RESET)"

clean:
		@rm -rf $(OBJ_DIR)
		@make clean -C $(LIBFT)
		@echo "$(RED)Cleaning Minishell's objects. $(RESET)"
		@echo

fclean:
		@rm -rf $(OBJ_DIR)
		@rm -rf $(NAME)
		@make fclean -C $(LIBFT)
		@echo "$(RED)Cleaning Minishell's executables.$(RESET)"

re: fclean all

.PHONY: all clean fclean re compiling bonus compiling_bonus
