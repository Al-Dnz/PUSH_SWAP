NAME1 		= 	checker
NAME2		= 	push_swap
MAIN_FILE1	= 	assets/src/checker.c
MAIN_FILE2	= 	assets/src/push_swap.c

SRCS 		=	list_util.c \
				list_util_2.c \
				parser_util.c \
				switch_util.c \
				get_instruct.c \

LIBFT_DIR	= 	./libft
LIB			= 	./libft/libft.a
OBJ_DIR 	= 	assets/obj
SRC_DIR 	= 	assets/src
INCLUDE		= 	assets/inc
CC			= 	clang
CFLAGS		= 	-g3 -Wall -Wextra -Werror
OBJ 		= 	$(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

all:			lib $(NAME1) $(NAME2) rmdsym

lib:			
			make -C ${LIBFT_DIR}
rmdsym:
			@rm -rf *.dSYM

$(NAME1): 		$(OBJ)
			@${CC} $(CFLAGS) $(MAIN_FILE1) -I $(INCLUDE) $(OBJ) ${LIB} -o $(NAME1)
			@echo "----------------------------"
			@echo "=> $(NAME1) well created ! <= "
			@echo "----------------------------"

$(NAME2): 		$(OBJ)
			@${CC} $(CFLAGS) $(MAIN_FILE2) -I $(INCLUDE) $(OBJ) ${LIB} -o $(NAME2)
			@echo "------------------------------"
			@echo "=> $(NAME2) well created ! <= "
			@echo "------------------------------"

$(OBJ_DIR)/%.o: 	$(SRC_DIR)/%.c
			@mkdir -p $(OBJ_DIR)
			@${CC} $(CFLAGS) -I $(INCLUDE) -c $< -o $@

clean:
			@rm -rf $(OBJ_DIR)
			make clean -C ${LIBFT_DIR}
			@echo "obj deleted"

fclean:			clean
			@rm -rf $(NAME1)
			@rm -rf $(NAME2)
			make fclean -C ${LIBFT_DIR}
			@echo "=> [$(NAME1)]: deleted <="
			@echo "=> [$(NAME2)]: deleted <="

re:			fclean all

.PHONY: 		all, clean, fclean, re
