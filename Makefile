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
SRC_DISPLAY			=	$(addprefix src_display_mlx/, \
					 	display_player.c \
					 	display_sprites.c \
					 	display_tools_1.c \
					 	display_tools_2.c \
					 	display_features_main.c \
					 	display_features_bomb.c \
					 	display_features_ui_main.c \
					 	display_features_ui_boxs.c \
					 	display_features_qte_main.c \
					 	display_features_qte_launch.c \
					 	display_features_guards_main.c \
					 	display_features_dialogue_main.c \
					 	display_features_guards_turn_fov.c \
						display_features_character_on_map.c \
					 	display_features_dialogue_text_box.c \
						)

SRC_EVENT			=	$(addprefix src_events/, \
						events_dialogue_main.c \
						events_dialogue_tools.c \
						events_dialogue_utils.c \
						texts_box_list_utils_free.c \
						texts_box_list_utils_main.c \
						)

# SOURCES USE FOR THE GAMEPLAY
SRC_GAMEPLAY		=	$(addprefix src_gameplay/, \
						gameplay_tools.c \
						gameplay_features.c \
						gameplay_restart_game.c \
						gameplay_features_bomb.c \
						gameplay_collider_tools.c \
						gameplay_move_animation.c \
						gameplay_move_guard_main.c \
						gameplay_move_player_main.c \
						gameplay_move_guard_tools.c \
						gameplay_move_player_tools.c \
						gameplay_collider_positions.c \
						gameplay_collider_check_tile.c \
						gameplay_move_player_animation.c \
						gameplay_player_to_character_main.c \
						gameplay_player_to_character_functions.c \
						)

# SOURCES USE FOR GET_NEXT_LINE
SRC_GNL				=	$(addprefix src_gnl/, \
						get_next_line.c \
						get_next_line_utils.c \
						)

SRC_HANDLER			=	$(addprefix src_handler/, \
						handler.c \
						handler_bomb.c \
						handler_dialogue.c \
						handler_player_features.c \
						handler_player_movement.c \
						)

# SOURCES USE TO INIT VARIABLES FOR DISPLAY
SRC_INIT		=	$(addprefix src_init/, \
						init_game_main.c \
						init_game_camera.c \
						init_game_window.c \
						init_sprites_main.c \
						init_gameplay_main.c \
						init_gameplay_guard.c \
						init_gameplay_player.c \
						init_gameplay_all_texts.c \
						init_available_character.c \
						init_sprites_arrengement.c \
						init_assets_sprites_main.c \
						init_assets_sprites_tools.c \
						init_assets_sprites_images.c \
						init_gameplay_random_elements.c \
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
						utils.c \
						exit_game.c \
						free_utils.c \
						free_assets.c \
						mem_functions.c \
						positions_tools.c \
						vector_functions.c \
						exit_error_message.c \
						)

# ALL SOURCES FOR SO_LONG
SL_SRCS 			=	$(addprefix $(SRC_DIR), \
						$(SRC_CAMERA) \
						$(SRC_DEBUG) \
						$(SRC_DISPLAY) \
						$(SRC_EVENT) \
						$(SRC_GAMEPLAY) \
						$(SRC_GNL) \
						$(SRC_HANDLER) \
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
