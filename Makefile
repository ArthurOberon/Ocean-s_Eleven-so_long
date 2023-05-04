SO_LONG 		=	so_long

CC 				=	cc
CFLAGS 			=	-g -Wall -Wextra #-fsanitize=address #-Werror
INCLUDES_DIR 	=	include/
SRC_DIR 		=	src/
OBJ_DIR 		=	obj/
LIB_DIR 		=	lib/
INCLUDES_H		=	-I./$(INCLUDES_DIR) -I./$(LIB_DIR)
MLX_FLAGS 		=	-L$(LIB_DIR) -lmlx -lX11 -lXext
DEPS 			=	$(INCLUDES_DIR)so_long.h Makefile

SRC_CAMERA		= $(addprefix src_camera/, \
					camera.c\
					camera_chunks.c\
					camera_chunks_out_map.c\
					)

# SOURCES USE WHEN IS_DEBUG == 1
SRC_DEBUG		=	$(addprefix src_debug/, \
					debug_print.c \
					debug_display.c \
					)

# SOURCES USE TO DISPLAY THE GAME WITH THE MLX
SRC_DISPLAY		=	$(addprefix src_display_mlx/, \
				 	display.c \
				 	display_tools.c \
				 	display_sprites.c \
					)

# SOURCES USE FOR THE GAMEPLAY
SRC_GAMEPLAY	=	$(addprefix src_gameplay/, \
					handler.c \
					collider.c \
					move_player.c\
					collider_tools.c \
					gameplay_tools.c \
					move_player_tools.c\
					)

# SOURCES USE FOR GET_NEXT_LINE
SRC_GNL			=	$(addprefix src_gnl/, \
					get_next_line.c \
					get_next_line_utils.c \
					)

# SOURCES USE TO INIT VARIABLES FOR DISPLAY
SRC_INIT	=	$(addprefix src_init/, \
					init_game.c \
					init_camera.c \
					init_window.c \
					init_images.c \
					init_sprites.c \
					init_gameplay.c \
					init_sprites_assets.c \
					sprites_arrengement.c \
					)

# SOURCES USE TO READ AND PARSE THE MAP
SRC_PARSING		=	$(addprefix src_parsing/, \
					parse_map.c \
					lst_map_utils.c \
					parse_map_utils_check_map.c \
					parse_map_utils_char_manipulations.c \
					)

# SOURCES USE FOR THE ALGO A_STAR
SRC_PATH 		=	$(addprefix src_pathfinding/, \
					pathfinding.c \
					a_star_utils.c \
					a_star_algorithm.c \
					)

# SOURCES USEFULS
SRC_TOOLS		=	$(addprefix src_tools/, \
					exit.c \
					free.c \
					free_utils.c \
					mem_functions.c \
					print_functions.c \
					utils.c \
					)

# ALL SOURCES FOR SO_LONG
SL_SRCS 		=	$(addprefix $(SRC_DIR), \
					$(SRC_CAMERA) \
					$(SRC_DEBUG) \
					$(SRC_DISPLAY) \
					$(SRC_GAMEPLAY) \
					$(SRC_GNL) \
					$(SRC_INIT) \
					$(SRC_PARSING) \
					$(SRC_PATH) \
					$(SRC_TOOLS) \
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

$(SO_LONG): $(PS_OBJ) $(DEPS)
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
