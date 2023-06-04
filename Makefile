SO_LONG 			=	so_long

CC 					=	cc
CFLAGS 				=	-g -Wall -Wextra #-fsanitize=address #-Werror #-03
INCLUDES_DIR 		=	include/
SRC_DIR 			=	src/
OBJ_DIR 			=	.obj/
LIB_DIR 			=	lib/
LIB_DIR_MLX			=	$(LIB_DIR)
LIB_DIR_PRINTF		=	$(LIB_DIR)ft_printf/
INCLUDES_H			=	-I./$(INCLUDES_DIR) -I./$(LIB_DIR)
MLX_FLAGS 			=	-L$(LIB_DIR_MLX) -lmlx -lX11 -lXext -lm
FT_PRINTF_FLAGS		=	-L$(LIB_DIR_PRINTF) -lftprintf
DEPS 				=	$(INCLUDES_DIR)so_long.h Makefile

SRC_CAMERA			= $(addprefix src_camera/, \
						camera.c \
						camera_chunks.c \
						)

# SOURCES USE WHEN IS_DEBUG == 1
SRC_DEBUG			=	$(addprefix src_debug/, \
						debug_print.c \
						debug_display.c \
						)

# SOURCES USE TO DISPLAY THE GAME WITH THE MLX
SRC_DISPLAY_GAME	=	$(addprefix src_display_game/, \
						)

# SOURCES USE TO DISPLAY THE GAMEPLAY FEATURES
SRC_DIS_GAMEPLAY	=	$(addprefix src_display_gameplay_features/, \
					 	display_ui.c \
					 	display_qte.c \
					 	display_bomb.c \
					 	display_tools.c \
					 	display_player.c \
					 	display_guards.c \
					 	display_sprites.c \
					 	display_dialogue.c \
					 	display_text_box.c \
					 	display_launch_qte.c \
						display_character_on_map.c \
					 	display_gameplay_elements.c \
						)

# SOURCES USE FOR THE GAMEPLAY
SRC_GAMEPLAY		=	$(addprefix src_gameplay/, \
						bomb.c \
						handler.c \
						collider.c \
						text_box.c \
						move_guard.c \
						move_player.c \
						texts_box_list.c \
						gameplay_tools.c \
						positions_tools.c \
						text_box_events.c \
						handler_gameplay.c \
						move_guard_tools.c \
						gameplay_elements.c \
						move_player_tools.c \
						collider_positions.c \
						set_player_to_character.c \
						)

# SOURCES USE FOR GET_NEXT_LINE
SRC_GNL				=	$(addprefix src_gnl/, \
						get_next_line.c \
						get_next_line_utils.c \
						)

# SOURCES USE TO INIT VARIABLES FOR DISPLAY
SRC_INIT		=	$(addprefix src_init/, \
						init_game.c \
						init_guard.c \
						init_player.c \
						init_camera.c \
						init_window.c \
						init_images.c \
						init_sprites.c \
						init_gameplay.c \
						sprites_arrengement.c \
						init_sprites_assets.c \
						init_random_elements.c \
						get_available_character.c \
						)

# SOURCES USE TO READ AND PARSE THE MAP
SRC_PARSING			=	$(addprefix src_parsing/, \
						parse_map.c \
						lst_map_utils.c \
						parse_map_utils_check_map.c \
						parse_map_utils_char_manipulations.c \
						)

# SOURCES USE FOR THE ALGO A_STAR
SRC_PATH 			=	$(addprefix src_pathfinding/, \
						pathfinding.c \
						a_star_utils.c \
						a_star_algorithm.c \
						)

# SOURCES USEFULS
SRC_TOOLS			=	$(addprefix src_tools/, \
						exit.c \
						free.c \
						utils.c \
						free_utils.c \
						mem_functions.c \
						print_functions.c \
						vector_functions.c \
						)

# ALL SOURCES FOR SO_LONG
SL_SRCS 			=	$(addprefix $(SRC_DIR), \
						$(SRC_CAMERA) \
						$(SRC_DEBUG) \
						$(SRC_DISPLAY_GAME) \
						$(SRC_DIS_GAMEPLAY) \
						$(SRC_GAMEPLAY) \
						$(SRC_GNL) \
						$(SRC_INIT) \
						$(SRC_PARSING) \
						$(SRC_PATH) \
						$(SRC_TOOLS) \
					 	game.c \
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
	@make -s -C $(LIB_DIR_PRINTF)
	@echo "\e[36mMaking $(SO_LONG)...\e[0m"
	@$(CC) $(CFLAGS) $(INCLUDES_H) $(PS_OBJ) $(MLX_FLAGS) $(FT_PRINTF_FLAGS) -o $(SO_LONG)
	@echo "\e[32mDone !\e[0m"

bonus: all

clean:
	@make -s -C $(LIB_DIR_PRINTF) clean
	@rm -rf $(OBJ_DIR)
	@echo "\e[31mObject files removed.\e[0m"

fclean:	clean
	@make -s -C $(LIB_DIR_PRINTF) fclean
	@rm -f $(SO_LONG)
	@echo "\e[31m$(SO_LONG) removed.\e[0m"

re:		fclean all

.PHONY = all bonus clean fclean re
