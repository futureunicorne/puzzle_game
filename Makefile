# puzzle

NAME = puzzle
SRC_PATH = ./src/
OBJ_PATH = ./objs/
INC_PATH = ./includes/

SRC_NAME =	main.c			\
			javelo.c		\
			javelo_colun.c	\
			recup.c			\
			solve.c			\


OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

# Files

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

# Flags

LDFLAGS = -L./libft/

LFT = -lft

CC = gcc -g

CFLAGS = -Wall -Wextra -Werror

# Rules

all: $(NAME)

$(NAME):  $(OBJ) $(INC_PATH)
	@make -C libft/
	@echo "\033[34mCreation of $(NAME) ...\033[0m"
	@$(CC) $(OBJ) $(LDFLAGS) $(LFT) -o $(NAME)
	@echo "\033[32m$(NAME) created\n\033[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@mkdir $(OBJ_PATH)/parse_opcode/ 2> /dev/null || true
	$(CC) -I$(INC_PATH) -o $@ -c $<

clean:
	@make clean -C libft/
	@echo "\033[33mRemoval of .o files of $(NAME) ...\033[0m"
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "\033[31mFiles .o deleted\n\033[0m"

fclean: clean fcleanlib
	@echo "\033[33mRemoval of $(NAME)...\033[0m"
	@rm -f ../$(NAME)
	@echo "\033[31mBinary $(NAME) deleted\n\033[0m"

fcleanlib:
	@make fclean -C libft/

re : fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

.PHONY : all clean fclean re
