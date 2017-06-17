# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 19:01:16 by jgeslin           #+#    #+#              #
#    Updated: 2016/02/03 19:42:54 by jgeslin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./sources/
INC_PATH = ./includes/
OBJ_PATH = ./obj/

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

SOURCES = ft_atoi.c ft_atoi_base.c ft_bzero.c ft_chrswap.c ft_convert_base.c\
	   ft_find_next_prime.c ft_is_prime.c ft_isalnum.c ft_isalpha.c\
	   ft_isascii.c ft_isdigit.c ft_isprint.c ft_iswap.c ft_itoa.c\
	   ft_itoa_base.c ft_lstadd.c ft_lstat.c ft_lstdel.c ft_lstdelone.c\
	   ft_lstend.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c\
	   ft_lstpushback.c ft_lstpushend.c ft_lstsize.c ft_memalloc.c\
	   ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c\
	   ft_memmove.c ft_memset.c ft_print_words_tables.c ft_putchar.c\
	   ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c\
	   ft_putnbr_base.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c\
	   ft_recursive_factorial.c ft_recursive_power.c ft_sqrt.c\
	   ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c\
	   ft_strdup.c ft_strdupclr.c ft_strndup.c ft_strequ.c ft_striter.c\
	   ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
	   ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c\
	   ft_strnequ.c ft_strnew.c ft_strnjoin.c ft_strnstr.c ft_strrchr.c\
	   ft_strrev.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c\
	   ft_strtrimy.c ft_strwjoin.c ft_strwnjoin.c ft_tolower.c ft_toupper.c\
	   ft_lstclrone.c ft_atol_base.c ft_btoa.c ft_dtobin.c ft_ltoa.c\
	   ft_printbtoa.c ft_ulpower.c ft_ultoa.c ft_putlong.c

OBJ_NAME = $(SOURCES:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SOURCES))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(OBJ)
	@ar -r $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Libft done Sir!"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2>/dev/null || echo "" > /dev/null
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@/bin/rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	@echo ".o cleaned Sir."

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "Libft erased Sir."

re: fclean all
	@echo "WTF?! All's right Sir!"

.PHONY: all clean fclean re
