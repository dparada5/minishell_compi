# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 10:33:13 by dparada           #+#    #+#              #
#    Updated: 2024/06/26 12:22:50 by malena-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
USER = malena-b
LIBFT = ./libft
CC = clang
CFLAGS = -Wall -Wextra -Werror -g
SRC_DIR = src/
OBJ_DIR = obj/
B_SRC_DIR = Bonus/

DEF_COLOR	= \033[0;39m
MAGENTA		= \033[0;35m
YELLOW		= \033[0;33m
GREEN		= \033[0;32m
WHITE		= \033[0;37m
RESET		= \033[0m
GRAY		= \033[0;90m
BLUE		= \033[0;34m
CYAN		= \033[0;37m
RED			= \033[0;31m
BOLD		= \033[1m

SRC_FILES = built_ins/cd built_ins/echo built_ins/env built_ins/exit \
	built_ins/export built_ins/pwd built_ins/unset utils/env_utils \
	utils/exec_utils utils/general_utils utils/tokens_utils executor \
BONUS_FILES =

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
BONUS_SRC = $(addprefix $(B_SRC_DIR), $(addsuffix .c, $(BONUS_FILES)))
BONUS_OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(BONUS_FILES)))

OBJF = .cache_exists

all: $(NAME)

$(NAME):	compiling	$(OBJ)
	@make all -C $(LIBFT)
	@echo
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft -o $(NAME)
	@echo "$(GREEN)COMPLETE!$(RESET)"
	@echo

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@echo "$(MAGENTA)COMPILING...		$(BLUE)$(notdir $<)$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(B_SRC_DIR)%.c | $(OBJF)
	@echo "$(MAGENTA)COMPILING...		$(BLUE)$(notdir $<)$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)

compiling:
	@echo "$(YELLOW)COMPILING PIPEX FILES:$(RESET)"

clean:
	@rm -frf $(OBJ_DIR)
	@make clean -C $(LIBFT)

fclean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)
	@rm -rf $(BONUS_NAME)
	@make fclean -C $(LIBFT)
	@echo "$(YELLOW)Pipex fclean:	 	$(GREEN)[COMPLETED]$(EC)"
	@echo

re: fclean all
	@echo "$(YELLOW)PIPEX: $(GREEN)[RECOMPILED]$(RESET)"

norm:
	@echo "Norminette of pipex files: "
	@norminette $(SRC_DIR)
	@norminette $(B_SRC_DIR)
	@echo
	@echo "Norminette of libft files: "
	@norminette $(LIBFT)
	@echo

bonus: $(BONUS_OBJ)
			@make -C $(LIBFT)
			@$(CC) $(CFLAGS) $(BONUS_OBJ) -L$(LIBFT) -lft -o $(BONUS_NAME)
			@echo "$(GREEN)BONUS COMPLETE!$(RESET)"
			@echo
.PHONY: all clean fclean re norm compiling bonus

