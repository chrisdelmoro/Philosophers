NAME			= philosophers

HEADER_DIR		= ./include/
HEADER			= philosophers.h
HEADER_PATH		= $(addprefix $(HEADER_DIR), $(HEADER))

SRC_DIR			= ./src/
SRC				= 	main.c \
					threads/threads.c \
					threads/philos_threads.c \
					threads/monitor_thread.c \
					utils/ft_isdigit.c \
					utils/ft_atoi.c \
					utils/initialization_utils.c \
					utils/free_utils.c \
					utils/time_utils.c \
					utils/print.c \
					validation/validation_utils.c
SRC_PATH		= $(addprefix $(SRC_DIR), $(SRC))

OBJ_DIR			= ./objs/
OBJ				=	main.o \
					threads.o \
					philos_threads.o \
					monitor_thread.o \
					ft_isdigit.o \
					ft_atoi.o \
					initialization_utils.o \
					free_utils.o \
					time_utils.o \
					print.o \
					validation_utils.o
OBJ_PATH		= $(addprefix $(OBJ_DIR), $(OBJ))

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -pthread -g3

BIN				= ./bin/
BINARY_OUT		= $(addprefix $(BIN), $(NAME))

all: $(BINARY_OUT)

$(BINARY_OUT): $(SRC_PATH) $(HEADER_PATH)
	@ $(CC) $(CFLAGS) -c $(SRC_PATH) -I $(HEADER_DIR)
	@ mkdir -p $(OBJ_DIR)
	@ mv $(OBJ) $(OBJ_DIR)
	@ $(CC) $(CFLAGS) $(OBJ_PATH) -o $(NAME)
	@ mkdir -p $(BIN)
	@ mv $(NAME) $(BIN)
	@ echo "$(NAME) compiled successfully!"

clean:
	@ rm -rf $(OBJ_DIR)
	@ echo "object files erased successfully!"

fclean: clean
	@ rm -f $(BINARY_OUT)
	@ rm -rf $(BIN)
	@ echo "$(NAME) binaries erased successfully!"

re: fclean all

leaks:
	@ mkdir -p $(BIN)
	@ $(CC) $(CFLAGS) -g $(SRC_PATH) -I $(HEADER_DIR) -I $(HEADER_LIBFT) -o $(NAME)
	@ mv $(NAME) $(BIN)
	@ echo "$(NAME) with leak check option compiled successfully!"

simple:
	@ mkdir -p $(BIN)
	@ $(CC) -g $(SRC_PATH) -I $(HEADER_DIR) -I $(HEADER_LIBFT) -o $(NAME)
	@ mv $(NAME) $(BIN)
	@ echo "$(NAME) without compile flags compiled successfully!"

.PHONY: all clean fclean re
