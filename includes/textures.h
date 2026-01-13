/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:22:40 by aoberon           #+#    #+#             */
/*   Updated: 2026/01/13 17:30:37 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H


# define SPRITES_PATH "assets/sprites/xpm/"

// |---- WALL ----|

# define PATH_WALL_CORNER_N_W	"wall/wall_corner/wall_corner_n_w_64px"
# define PATH_WALL_CORNER_N_E	"wall/wall_corner/wall_corner_n_e_64px"
# define PATH_WALL_CORNER_S_E	"wall/wall_corner/wall_corner_s_e_64px"
# define PATH_WALL_CORNER_S_W	"wall/wall_corner/wall_corner_s_w_64px"
# define PATH_WALL_NORTH		"wall/wall/wall_north_64px"
# define PATH_WALL_SOUTH		"wall/wall/wall_south_64px"
# define PATH_WALL_EAST			"wall/wall/wall_east_64px"
# define PATH_WALL_WEST			"wall/wall/wall_west_64px"
# define PATH_WALL_ROULETTE		"wall/roulette_table/roulette_table_64px"
# define PATH_WALL_BLACKJACK	"wall/blackjack_table/blackjack_table_64px"

// |---- COLLECTIBLE ----|

# define PATH_COLLECT_IDLE		"collectible/letter_collectible_idle\
/letter_collectible_idle_64px"
# define PATH_COLLECT_OPEN_0 	"collectible/letter_collectible_open_0\
/letter_collectible_open_0_64px"
# define PATH_COLLECT_OPEN_1 	"collectible/letter_collectible_open_1\
/letter_collectible_open_1_64px"
# define PATH_COLLECT_OPEN_2 	"collectible/letter_collectible_open_2\
/letter_collectible_open_2_64px"
# define PATH_COLLECT_OPEN_3 	"collectible/letter_collectible_open_3\
/letter_collectible_open_3_64px"
# define PATH_COLLECT_OPEN_4 	"collectible/letter_collectible_open_4\
/letter_collectible_open_4_64px"
# define PATH_COLLECT_OPEN_5 	"collectible/letter_collectible_open_5\
/letter_collectible_open_5_64px"
# define PATH_COLLECT_OPEN_6 	"collectible/letter_collectible_open_6\
/letter_collectible_open_6_64px"
# define PATH_COLLECT_OPEN_7 	"collectible/letter_collectible_open_7\
/letter_collectible_open_7_64px"
# define PATH_COLLECT_OPEN_8 	"collectible/letter_collectible_open_8\
/letter_collectible_open_8_64px"
# define PATH_COLLECT_OPEN_9 	"collectible/letter_collectible_open_9\
/letter_collectible_open_9_64px"

// |---- GROUND ----|

# define PATH_GROUND			"ground/carpet_64px"
# define PATH_EXIT				"ground/safe/safe_64px"

// |---- PLAYER_DANNY ----|

# define PATH_PLAYER_DANNY_IDLE		"player/danny/idle/danny_idle_64px"
# define PATH_PLAYER_DANNY_MOVE_UP		"player/danny/move_up/\
danny_move_up_64px"
# define PATH_PLAYER_DANNY_MOVE_DOWN		"player/danny/move_down/\
danny_move_down_64px"
# define PATH_PLAYER_DANNY_MOVE_LEFT		"player/danny/move_left/\
danny_move_left_64px"
# define PATH_PLAYER_DANNY_MOVE_RIGHT		"player/danny/move_right/\
danny_move_right_64px"

// |---- PLAYER_RUSTY ----|

# define PATH_PLAYER_RUSTY_IDLE		"player/rusty/idle/rusty_idle_64px"
# define PATH_PLAYER_RUSTY_MOVE_UP		"player/rusty/move_up/\
rusty_move_up_64px"
# define PATH_PLAYER_RUSTY_MOVE_DOWN	"player/rusty/move_down/\
rusty_move_down_64px"
# define PATH_PLAYER_RUSTY_MOVE_LEFT	"player/rusty/move_left/\
rusty_move_left_64px"
# define PATH_PLAYER_RUSTY_MOVE_RIGHT	"player/rusty/move_right/\
rusty_move_right_64px"

// |---- PLAYER_LINUS ----|

# define PATH_PLAYER_LINUS_IDLE		"player/linus/idle/linus_idle_64px"
# define PATH_PLAYER_LINUS_MOVE_UP		"player/linus/move_up/\
linus_move_up_64px"
# define PATH_PLAYER_LINUS_MOVE_DOWN	"player/linus/move_down/\
linus_move_down_64px"
# define PATH_PLAYER_LINUS_MOVE_LEFT	"player/linus/move_left/\
linus_move_left_64px"
# define PATH_PLAYER_LINUS_MOVE_RIGHT	"player/linus/move_right/\
linus_move_right_64px"

// |---- PLAYER_BASHER ----|

# define PATH_PLAYER_BASHER_IDLE		"player/basher/idle/basher_idle_64px"
# define PATH_PLAYER_BASHER_MOVE_UP		"player/basher/move_up/\
basher_move_up_64px"
# define PATH_PLAYER_BASHER_MOVE_DOWN	"player/basher/move_down/\
basher_move_down_64px"
# define PATH_PLAYER_BASHER_MOVE_LEFT	"player/basher/move_left/\
basher_move_left_64px"
# define PATH_PLAYER_BASHER_MOVE_RIGHT	"player/basher/move_right/\
basher_move_right_64px"

// |---- DYNAMITE ----|

# define PATH_DYNAMITE			"dynamite/dynamite/dynamite_64px"
# define PATH_EXPLOSION			"dynamite/explosion_64px"

// |---- PICKPOCKET_QTE ----|

# define PATH_AREA_QTE			"pickpocket_qte/pickpocket_area_64px"
# define PATH_QTE				"pickpocket_qte/qte/qte"

// |---- GUARD ----|

# define PATH_GUARD_IDLE		"guard/idle/guard_idle_64px"
# define PATH_GUARD_MOVE_UP		"guard/move_up/guard_move_up_64px"
# define PATH_GUARD_MOVE_DOWN	"guard/move_down/guard_move_down_64px"
# define PATH_GUARD_MOVE_LEFT	"guard/move_left/guard_move_left_64px"
# define PATH_GUARD_MOVE_RIGHT	"guard/move_right/guard_move_right_64px"
# define PATH_GUARD_FOV			"guard/guard_fov_64px"

// |---- MENU_BUTTON ----|

# define PATH_BUTTON_PAUSE		"ui/menu/button_pause/button_pause_64px"
# define PATH_BUTTON_QUIT		"ui/menu/button_quit/button_quit_64px"
# define PATH_BUTTON_RESET		"ui/menu/button_reset/button_reset_64px"
# define PATH_BUTTON_TUTO		"ui/menu/button_tutorial/button_tuto_64px"

// |---- UI ----|

# define PATH_PLUS_ONE			"ui/+1_32px"
# define PATH_HEART				"ui/heart_64px"
# define PATH_BOX				"ui/small_box_64px"
# define PATH_SELECTION_BOX		"ui/character_selection_box/\
character_selection_box_64px"
# define PATH_AVATAR_CHARACTER	"ui/character_avatar_64px"

// |---- TEXT_BOX ----|

# define PATH_ALPHABET			"text_box/alphabet/alphabet_16px"
# define PATH_SPECIAL_CHAR		"text_box/special_character\
/special_character_16px"
# define PATH_BACKGROUND_TEXT	"text_box/background_text_64px"
# define PATH_TALKING_DANNY		"text_box/talking_character_danny/\
talking_character_danny_32px"
# define PATH_TALKING_RUSTY		"text_box/talking_character_rusty/\
talking_character_rusty_32px"
# define PATH_TALKING_LINUS		"text_box/talking_character_linus/\
talking_character_linus_32px"
# define PATH_TALKING_BASHER	"text_box/talking_character_basher/\
talking_character_basher_32px"

// |---- BIG_IMAGE ----|

# define PATH_TITLE_SCREEN		"start_screen/title_screen"
# define PATH_TUTORIAL			"start_screen/tutorial/tutorial_screen"
# define PATH_BACKGROUND		"background/game_background_64px"
# define PATH_LOSE_SCREEN		"end_screen/lose_screen"
# define PATH_WIN_SCREEN		"end_screen/win_screen"

// ----------------------------------------------------------------

// |---- WALL ----|

# define FRAME_WALL 1
# define FRAME_WALL_ROULETTE 40
# define FRAME_WALL_BLACKJACK 45

// |---- COLLECTIBLE ----|

# define FRAME_COLLECT_IDLE 20
# define FRAME_COLLECT_OPEN 28

// |---- GROUND ----|

# define FRAME_GROUND 1
# define FRAME_EXIT 12

// |---- PLAYER_MOVE ----|

# define FRAME_PLAYER_IDLE 12
# define FRAME_PLAYER_MOVE 6

# define FRAME_RUSTY_IDLE 33

// |---- DYNAMITE ----|

# define FRAME_DYNAMITE 5
# define FRAME_EXPLOSION 1

// |---- PICKPOCKET_QTE ----|

# define FRAME_AREA_QTE 1
# define FRAME_QTE 4

// |---- GUARD ----|

# define FRAME_GUARD_IDLE 4
# define FRAME_GUARD_MOVE 6
# define FRAME_GUARD_FOV 1

// |---- UI ----|

# define FRAME_MENU_BUTTON 2
# define FRAME_PLUS_ONE 1
# define FRAME_HEART 1
# define FRAME_BOX 1
# define FRAME_SELECTION_BOX 2
# define FRAME_AVATAR_CHARACTER 1

// |---- TEXT_BOX ----|

# define FRAME_ALPHABET 26
# define FRAME_SPECIAL_CHAR 31
# define FRAME_BACKGROUND_TEXT 1
# define FRAME_TALKING_CHARACTER 4

// |---- BIG_IMAGE ----|

# define FRAME_TITLE_SCREEN 1
# define FRAME_TUTORIAL 8
# define FRAME_BACKGROUND 1
# define FRAME_LOSE_SCREEN 2
# define FRAME_WIN_SCREEN 1

// ----------------------------------------------------------------

#endif