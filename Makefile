SO_LONG 		=	so_long

CC 				=	gcc
CFLAGS 			=	-g -Wall -Wextra #-Werror
INCLUDES_DIR 	=	include/
SRC_DIR 		=	src/
OBJ_DIR 		=	obj/
LIB_DIR 		=	lib/
INCLUDES_H		=	-I./$(INCLUDES_DIR) -I./$(LIB_DIR)
MLX_FLAGS 		=	-L$(LIB_DIR) -lmlx -lX11 -lXext
DEPS 			=	$(INCLUDES_DIR)so_long.h Makefile


# SOURCES USE TO EXIT WITH ERROR
ERROR_SRC 		=	$(addprefix error_src/, \
					exit.c \
					)

FREE_SRC		=	$(addprefix free_src/, \
					free.c \
					)

# SOURCES USE FOR GET_NEXT_LINE
GNL_SRC 		=	$(addprefix gnl_src/, \
					get_next_line.c \
					get_next_line_utils.c \
					)

# SOURCES USE FOR ALL TYPE OF LISTS
LST_SRC 		=	$(addprefix list_src/, \
					lst_map_utils.c \
					)

# SOURCES USE TO READ AND PARSE THE MAP
MAP_SRC 		=	$(addprefix map_src/, \
					parse_map.c \
					parse_map_utils_check_map.c \
					parse_map_utils_char_manipulations.c \
					)

# SOURCES USE TO READ AND PARSE THE MAP
PATH_SRC 		=	$(addprefix pathfinding_src/, \
					pathfinding.c \
					a_star_utils.c \
					a_star_algorithm.c \
					)

# IT'S IN THE NAME
UTILS_SRC 		=	$(addprefix utils_src/, \
					utils.c \
					mem_functions.c \
					print_functions.c \
					)

#SOURCES USE TO INIT AND DISPLAY SPRITES
SPRITES_SRC		=	$(addprefix sprites_src/, \
					init_images.c \
					init_sprites.c \
					sprites_arrengement.c \
					)

# SOURCES USE TO DISPLAY THE GAME
DISPLAY_SRC		=	$(addprefix display_src/, \
				 	display.c \
					display_debug.c \
				 	display_useful.c \
				 	display_sprites.c \
					)

MLX_SRC			=	$(addprefix mlx_src/, \
					handler.c \
					$(DISPLAY_SRC) \
					$(SPRITES_SRC) \
					)

# ALL SOURCES FOR SO_LONG
SL_SRCS 		=	$(addprefix $(SRC_DIR), \
					$(ERROR_SRC) \
					$(FREE_SRC) \
					$(GNL_SRC) \
					$(LST_SRC) \
					$(MAP_SRC) \
					$(MLX_SRC) \
					$(PATH_SRC) \
					$(UTILS_SRC) \
					so_long.c \
					\
					temporary.c \
					)

PS_OBJ 			=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o, $(SL_SRCS))

all: $(SO_LONG)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(DEPS)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES_H) -c -o $@ $<

$(SO_LONG): $(PS_OBJ)
	@echo "\e[36mMaking $(SO_LONG)...\e[0m"
	@$(CC) $(CFLAGS) $(INCLUDES_H) $(PS_OBJ) $(MLX_FLAGS) -o $(SO_LONG)
	@echo "\e[32mDone !\e[0m"

bonus: all

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\e[31mObject files removed.\e[0m"

fclean:	clean
	@rm -f $(SO_LONG)
	@echo "\e[31m$(SO_LONG) removed.\e[0m"

re:		fclean all

.PHONY = all bonus clean fclean re
