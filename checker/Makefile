NAME 		= 	checker
SRCS 		=	main.c \

LIBFT_DIR	= 	../libft
LIB		= 	../libft/libft.a
OBJ_DIR 	= 	obj
SRC_DIR 	= 	src
INCLUDE		= 	inc
CC		= 	clang
CFLAGS		= 	-g3 -Wall -Wextra -Werror
OBJ 		= 	$(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

all:			lib $(NAME)

lib:			
			make -C ${LIBFT_DIR}

$(NAME): 		$(OBJ)
			@${CC} $(CFLAGS) -I $(INCLUDE) $(OBJ) ${LIB} -o $(NAME)
			@echo "\n------------------------------"
			@echo "| => $(NAME) well created ! <= |"
			@echo "------------------------------\n"

$(OBJ_DIR)/%.o: 	$(SRC_DIR)/%.c
			@mkdir -p $(OBJ_DIR)
			@${CC} $(CFLAGS) -I $(INCLUDE) -c $< -o $@

clean:
			@rm -rf $(OBJ_DIR)
			make clean -C ${LIBFT_DIR}
			@echo "$(NAME) : obj deleted"

fclean:			clean
			@rm -rf $(NAME)
			make fclean -C ${LIBFT_DIR}
			@echo "\n=> [$(NAME)]: deleted <=\n"

re:			fclean all

.PHONY: 		all, clean, fclean, re
