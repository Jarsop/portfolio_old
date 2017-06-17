# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/15 12:36:55 by jgeslin           #+#    #+#              #
#    Updated: 2016/12/09 18:45:09 by jgeslin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./sources/
OBJ_PATH = ./obj/
INC_PATH = ./includes/
INC_LIBFT_PATH = ./libft/includes/
INC_MLX  = -I ./minilibx_macos/
LIB_PATH = ./libft/
MLX_PATH = ./minilibx_macos/
MLX = -L $(MLX_PATH) -lmlx -framework OpenGL -framework Appkit -lpthread -D_REENTRANT
DEBUG = -g -fsanitize=address

NAME = wolf3d
CC = gcc
CFGLAGS = -Werror -Wextra -Wall -O3

SDL2		= -framework SDL2
SDL2_MIXER	= -framework SDL2_mixer

SDL2_HEADER			= -I ~/Library/Frameworks/SDL2.framework/Headers/
SDL2_HEADER_MIXER	= -I ~/Library/Frameworks/SDL2_mixer.framework/Headers/

SDL			= -F ~/Library/Frameworks $(SDL2_MIXER) $(SDL2)
SDL_HEADER	= -F ~/Library/Frameworks $(SDL2_HEADER_MIXER) $(SDL2_HEADER)

SRC_NAME =	main.c\
			file.c\
			game.c\
			key.c\
			raycast.c\
			draw.c\
			tools.c\

OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = libft.a

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
INC_LIBFT = $(addprefix -I,$(INC_LIBFT_PATH))
LIB = $(LIB_PATH)$(LIB_NAME)

.PHONY: clean fclean re all ready

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	@make -C $(MLX_PATH)
	@$(CC) $(CFLAGS) $(LIB) $(MLX) $(OBJ) $(SDL) $(SDL_HEADER) -o $(NAME)
	@printf '\033[35m[ ✔ ] %s\n\033[0m' "$(NAME)'s MiniOns Created 😈"
	@printf '\033[32m[ ✔ ] %s\n\033[0m' "$(NAME) is done ! 😎"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2>/dev/null || echo "" > /dev/null
	@$(CC) $(CFLAGS) $(INC_MLX) $(SDL_HEADER) $(INC_LIBFT) $(INC) -o $@ -c $<
	@printf '\033[33m[ ✔ ] %s\n\033[0m' "$< 😈"

clean:
	@make clean -C $(LIB_PATH)
	@make clean -C $(MLX_PATH)
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "$(NAME)'s MiniOns Clean 😵"

fclean: clean
	@make fclean -C $(LIB_PATH)
	@rm -f $(NAME)
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "$(NAME) Fclean R.I.P ☠"

ready: re clean
	@printf '\033[32m[ ✔ ] %s\n\033[0m' "$(NAME) is ready ! 🍺  and cleaned poop 💩"

re: fclean all
	@printf '\033[32m[ ✔ ] %s\n\033[0m' "Drink's all round ! 🍺 🍺 🍺 🍺 🍺"

sdl_install :
	curl https://dl.dropboxusercontent.com/u/22561204/SDL/Archive.zip > /tmp/Archive.zip
	unzip -o /tmp/Archive.zip -d ~/Library/Frameworks/
