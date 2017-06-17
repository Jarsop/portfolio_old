# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgeslin  <jgeslin@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/15 12:36:55 by jgeslin           #+#    #+#              #
#    Updated: 2016/03/25 19:16:41 by jgeslin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./sources/
OBJ_PATH = ./obj/
INC_PATH = ./includes/
INC_LIBFT_PATH = ./libft/includes/
LIB_PATH = ./libft/

NAME = ft_ls
CC = gcc
CFGLAGS = -Werror -Wextra -Wall -g

SRC_NAME = main.c\
		   ft_lsstart.c\
		   ft_lspushback.c\
		   ft_lsnew.c\
		   ft_job.c\
		   ft_lsfree.c\
		   ft_puts.c\
		   ft_recup.c\
		   ft_right.c\
		   ft_putls.c\
		   ft_color.c\
		   ft_tools.c\
		   ft_open.c\
		   ft_space.c\
		   ft_puttool.c\

OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = libft.a

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
INC_LIBFT = $(addprefix -I,$(INC_LIBFT_PATH))
LIB = $(LIB_PATH)$(LIB_NAME)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	@$(CC) $(CFLAGS) $(LIB) $(INC_LIBFT) $(INC) $(OBJ) -o $(NAME)
	@echo $(NAME) "done."

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2>/dev/null || echo "" > /dev/null
	$(CC) $(CFLAGS) $(INC_LIBFT) $(INC) -o $@ -c $<
	@echo "\033[A\033[K\033[A"

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean: clean
	@make fclean -C $(LIB_PATH)
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
