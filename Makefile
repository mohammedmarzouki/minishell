# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/22 20:07:24 by tjmari            #+#    #+#              #
#    Updated: 2021/05/27 11:27:35 by tjmari           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NC = \033[0m
RED = \033[1;31m
GREEN = \033[1;32m
ORANGE = \033[1;33m

NAME = minishell
LIBFT = libft.a

FLAGS = -Wall -Wextra -Werror

INCLUDES = ./includes/minishell.h \

SRCS = ./srcs/main.c ./srcs/get_next_line.c \
	./srcs/m_parsing.c ./srcs/m_tools.c ./srcs/m_tools2.c \
	./srcs/m_assign.c ./srcs/m_splitting.c \
	\
	./srcs/t_executing.c ./srcs/t_redirection.c ./srcs/t_pipe.c \
	./srcs/t_infork.c \
	./srcs/t_builtin.c ./srcs/t_echo.c ./srcs/t_cd.c \
	./srcs/t_pwd.c ./srcs/t_export.c ./srcs/t_unset.c \
	./srcs/t_env.c ./srcs/t_exit.c \
	./srcs/t_charp.c \

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(INCLUDES) $(SRCS)
	@make -C ./libft
	@mv ./libft/$(LIBFT) ./
	@echo "$(GREEN)MINISHELL: ./$(LIBFT) moved to $(NAME)\n---------------------------------------$(NC)"
	@gcc $(FLAGS) $(SRCS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)MINISHELL: ./$(NAME) made\n---------------------------$(NC)"

debug:
	@make -C ./libft
	@mv ./libft/$(LIBFT) ./
	@echo "$(GREEN)MINISHELL: ./$(LIBFT) moved to $(NAME)\n---------------------------------------$(NC)"
	@gcc $(FLAGS) $(SRCS) $(LIBFT) -o $(NAME) -g -fsanitize=address
	@echo "$(GREEN)MINISHELL: ./$(NAME) compiled with -g -fsanitize=address made\n---------------------------------------------------------------$(NC)"

clean:
	@make clean -C ./LIBFT

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(RED)MINISHELL: ./$(LIBFT) deleted\n-----------------------------$(NC)"
	@rm -f $(NAME)
	@echo "$(RED)MINISHELL: ./$(NAME) deleted\n------------------------------$(NC)"
	@rm -rf .vscode $(NAME).dSYM
	@echo "$(RED)MINISHELL: debugging files deleted\n----------------------------------$(NC)"

re: fclean all

.PHONY: all clean fclean re
