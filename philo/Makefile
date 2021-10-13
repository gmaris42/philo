# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmaris <gmaris@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 15:31:47 by gmaris            #+#    #+#              #
#    Updated: 2021/09/13 15:44:05 by gmaris           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc

FLAGS = -Wall -Werror -Wextra

INCLUDES = -I$(HEADERS_DIR)

HEADERS_LIST =	philo.h\

HEADERS_DIR = ./headers/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

SRC_LIST =	main.c\
			ft_get_info.c\
			ft_philo.c\
			ft_sleep.c\
			ft_eat.c\
			ft_event.c\
			ft_check_alive.c\
			ft_usleep.c


SRC_DIR = ./srcs/
SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ_DIR = .obj/
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

YELLOW = \033[033m
GREEN = \033[032m
BLUE = \033[36m
RED = \033[031m
PURPLE = \033[35m
RESET = \033[0m

all: $(NAME)

$(NAME):$(OBJ_DIR) $(OBJ) Makefile
	@echo "\n$(PURPLE)Sources compilation for $(NAME)\t$(RESET)[$(GREEN)OK$(RESET)]\n"
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJ) -o $(NAME)
	@echo "[$(GREEN)$(NAME) compiled$(RESET)]"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(BLUE)Obj directory...$(RESET)[$(GREEN)created$(RESET)]\n"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADERS) Makefile
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(YELLOW)$(notdir $(basename $@))...$(RESET)\t\t[$(GREEN)OK$(RESET)]"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\n$(RED)Obj directory...$(RESET)[$(PURPLE)deleted$(RESET)]\n"

fclean: clean
	@rm -f $(NAME)

re: fclean all

norme:
	norminette **/*[.c.h]

.PHONY: all clean fclean re norme
