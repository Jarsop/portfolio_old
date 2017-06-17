SRC_PATH = ./sources/
INC_PATH = ./includes/
OBJ_PATH = ./obj/
INC_LIBFT_PATH = ./libft/includes/
LIB_PATH = ./libft/

NAME = game_2048
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC_NAME =

OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = libft.a

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
INC_LIBFT = $(addprefix -I,$(INC_LIBFT_PATH))
LIB = $(LIB_PATH)$(LIB_NAME)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIB_PATH)
	@echo "Libft Lib. Ready."
	@$(CC) $(CFLAGS) $(LIB) $(INC_LIBFT) $(INC) $(OBJ) -o $(NAME)
	@echo "MiniOns Arrived!"
	@echo "A New Challenger ! Let's ft_printf !"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2>/dev/null || echo "" > /dev/null
	$(CC) $(CFLAGS) $(INC_LIBFT) $(INC) -o $@ -c $<

clean :
	@rm -rf $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	@echo "MiniOns Died!"

fclean : clean
	@make fclean -C $(LIB_PATH)
	@rm -rf $(NAME)
	@echo "All's Destroyed! R.I.P :'("

re : fclean all
	@echo "Ft_printf Ready Again! ^^"

.PHONY: all clean fclean re
