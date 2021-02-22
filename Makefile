# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/09 16:32:57 by tjmari            #+#    #+#              #
#    Updated: 2021/02/22 12:01:22 by mmarzouk         ###   ########.fr        #
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

SRCS = ./srcs/minishell.c \
	./srcs/get_next_line.c ./srcs/u_prompt.c \
	./srcs/t_echo.c ./srcs/t_cd.c ./srcs/t_pwd.c ./srcs/t_export.c \
	./srcs/t_unset.c ./srcs/t_env.c ./srcs/t_exit.c \
	./srcs/m_parsing.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(INCLUDES) $(SRCS)
	@make -C ./libft
	@mv ./libft/$(LIBFT) ./
	@echo "$(GREEN)MINISHELL: ./$(LIBFT) moved to $(NAME)\n---------------------------------------$(NC)"
	@gcc $(FLAGS) $(SRCS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)MINISHELL: ./$(NAME) made\n---------------------------$(NC)"
	@sleep 1
	@clear
	@./minishell

san:
	@make -C ./libft
	@mv ./libft/$(LIBFT) ./
	@echo "$(GREEN)MINISHELL: ./$(LIBFT) moved to $(NAME)\n---------------------------------------$(NC)"
	@gcc $(FLAGS) $(SRCS) $(LIBFT) -o $(NAME) -fsanitize=address
	@echo "$(GREEN)MINISHELL: ./$(NAME) compiled with -fsanitize=address made\n------------------------------------------------------------$(NC)"
	@sleep 1
	@clear

deb:
	@make -C ./libft
	@mv ./libft/$(LIBFT) ./
	@echo "$(GREEN)MINISHELL: ./$(LIBFT) moved to $(NAME)\n---------------------------------------$(NC)"
	@gcc $(FLAGS) $(SRCS) $(LIBFT) -o $(NAME) -g
	@echo "$(GREEN)MINISHELL: ./$(NAME) compiled with -g\n---------------------------------------$(NC)"
	@sleep 1
	@clear

clean:
	@make clean -C ./libft
	@sleep 1
	@clear

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(RED)MINISHELL: ./$(LIBFT) deleted\n-----------------------------$(NC)"
	@rm -f $(NAME)
	@echo "$(RED)MINISHELL: ./$(NAME) deleted\n------------------------------$(NC)"
	@sleep 1
	@clear

re: fclean all

.PHONY: clean fclean re
