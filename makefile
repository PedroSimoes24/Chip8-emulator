OBJ_dir = obj
SRC_dir = src
BIN_dir = bin
INC_dir = inc


CC = gcc

# Flags
CFLAGS = -Wall -Wextra -Werror -I $(INC_dir) -g 

OBJECTS = $(OBJ_dir)/chip8.o \
		  $(OBJ_dir)/main.o \
		  $(OBJ_dir)/stack.o

chip8: $(OBJECTS)
	@mkdir -p $(BIN_dir)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(BIN_dir)/run -lSDL2

$(OBJ_dir)/%.o: $(SRC_dir)/%.c
	@mkdir -p $(OBJ_dir)
	$(CC) $(CFLAGS) -c $< -o $@
