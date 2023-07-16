/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:12:41 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/16 21:23:42 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <time.h>
# include <sys/time.h>
# include <math.h>

// CAUTION /!/\/
# include <stdio.h>

# define WINDOW_WIDTH 1600
# define WINDOW_HEIGHT 800

# define CHUNK_SIZE 128

# define RATIO_PLAYER_SIZE_X 0.75
# define RATIO_PLAYER_SIZE_Y 0.90
// Size player = chunk size - X % chunk size

# define SPEED 700
// 300

# define SPEED_GUARD 450

# define FPS_CAP 125
// -> 0.008

# define SPRITES_PATH "assets/sprites/sprites/xpm/"

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
# define PATH_QTE				"pickpocket_qte/sprite_qte_by_frame"

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
# define PATH_LOSE_SCREEN		"end_screen/lose_screen_16_9"
# define PATH_WIN_SCREEN		"end_screen/win_screen_16_9"

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

# define FRAME_MOVEMENT 2 // TO DELETE


// |---- DYNAMITE ----|

# define FRAME_DYNAMITE 5
# define FRAME_EXPLOSION 1

// |---- PICKPOCKET_QTE ----|

# define FRAME_AREA_QTE 1
# define FRAME_QTE 1

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
# define FRAME_TUTORIAL 7
# define FRAME_BACKGROUND 1
# define FRAME_LOSE_SCREEN 3
# define FRAME_WIN_SCREEN 1

// ----------------------------------------------------------------

// |---- ANIMATION ----|

# define DELAY_ANIMATION 0.08

// |---- GUARD ----|

# define DELAY_TURN_GUARD 2.5
# define DELAY_GUARD_CHASE_PLAYER 6

// |---- INVINCIBILITY FRAME ----|

# define DELAY_IFRAMES 1.5

// |---- QTE ----|

# define DELAY_QTE	3
# define DELAY_REACTION 1

// |---- DYNAMITE ----|

# define BOMB_TIMING 1.3
# define BOMB_NUMBER 5
# define DELAY_BOMB_EXPLOSION 0.7

// ----------------------------------------------------------------

# define IS_DEBUG 0
# define IS_DEBUG_TIME 0

# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define BLACK 0x000000

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# define COLLECTABLE 20
# define COLLECTED 21
# define COLLECTED_ON_GUARD 22

enum e_assets_pos
{
	e_player_danny,
	e_player_rusty,
	e_player_linus,
	e_player_basher,
	e_dynamite,
	e_explosion,
	e_area_qte,
	e_qte,
	e_guards,
	e_guard_fov,
	e_button_pause,
	e_button_reset,
	e_button_quit,
	e_button_tutorial,
	e_plus_one,
	e_heart,
	e_box,
	e_selection_box,
	e_avatar_character,
	e_alphabet,
	e_special_character,
	e_background_text,
	e_talking_danny,
	e_talking_rusty,
	e_talking_linus,
	e_talking_basher,
	e_total_assets,
};

enum e_player_character
{
	e_main,
	e_eater,
	e_thief,
	e_bomber,
};
// e_main = danny
// e_eater = rusty
// e_thief = linus
// e_bomber = basher

enum e_texts
{
	// debug
	e_text_debug,
	// debug
	e_text_tutorial_1,
	e_text_tutorial_2,
	e_text_tutorial_3,
	e_text_tutorial_4,
	e_text_tutorial_5,
	e_text_tutorial_6,
	e_text_tutorial_7,
	e_text_start_danny,
	e_text_start_rusty,
	e_text_start_linus,
	e_text_start_basher,
	e_text_rusty_to_danny_1,
	e_text_rusty_to_danny_2,
	e_text_linus_to_danny_1,
	e_text_linus_to_danny_2,
	e_text_basher_to_danny_1,
	e_text_basher_to_danny_2,
	e_text_danny_to_rusty_1,
	e_text_danny_to_rusty_2,
	e_text_linus_to_rusty_1,
	e_text_linus_to_rusty_2,
	e_text_basher_to_rusty_1,
	e_text_basher_to_rusty_2,
	e_text_danny_to_linus_1,
	e_text_danny_to_linus_2,
	e_text_rusty_to_linus_1,
	e_text_rusty_to_linus_2,
	e_text_basher_to_linus_1,
	e_text_basher_to_linus_2,
	e_text_danny_to_basher_1,
	e_text_danny_to_basher_2,
	e_text_rusty_to_basher_1,
	e_text_rusty_to_basher_2,
	e_text_linus_to_basher_1,
	e_text_linus_to_basher_2,
	e_text_remain_one_collectible_danny,
	e_text_remain_zero_collectible_danny,
	e_text_remain_one_collectible_rusty,
	e_text_remain_zero_collectible_rusty,
	e_text_remain_one_collectible_linus,
	e_text_remain_zero_collectible_linus,
	e_text_remain_one_collectible_basher,
	e_text_remain_zero_collectible_basher,
	e_text_code,
	e_total_text_number,
};

typedef struct s_lst_map
{
	char				*line;
	struct s_lst_map	*next;
}	t_lst_map;

typedef struct s_map_flag
{
	int	bool_p;
	int	bool_e;
	int	number_c;
	int	bool_error;
}	t_map_flag;

typedef struct s_path_map
{
	int	has_been_check;
	int	dst_to_start;
	int	dst_to_end;
	int	f;
	int	parent;
}	t_path_map;

typedef struct s_vector_2
{
	int	x;
	int	y;
}	t_vector_2;

typedef struct s_f_vector_2
{
	double	x;
	double	y;
}	t_f_vector_2;

typedef struct s_collider
{
	int	n_w;
	int	n_e;
	int	s_w;
	int	s_e;
}	t_collider;

typedef struct s_stat_tiles
{
	int	exit;
	int	wall;
	int	ground;
	int	player;
	int	collect;
}	t_stat_tiles;

typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	t_vector_2	size;
}	t_img;

typedef struct s_sprite
{
	t_img			*sprite_img;
	int				frame;
	int				size;
	struct timeval	last_time;
}	t_sprite;

typedef struct s_level
{
	char			*map;
	t_path_map		*path_map;
	int				nb_cases;
	int				nb_collect;
	int				exit_pos;
	int				player_pos_tab;
	t_vector_2		map_vector;
	t_stat_tiles	stat_tiles;
}	t_level;

typedef struct s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_sprite	**map_sprites;
}	t_window;

typedef struct s_sprites_assets
{
	t_sprite	*wall_corner_n_w;
	t_sprite	*wall_corner_n_e;
	t_sprite	*wall_corner_s_e;
	t_sprite	*wall_corner_s_w;
	t_sprite	*wall_side_up;
	t_sprite	*wall_side_down;
	t_sprite	*wall_side_left;
	t_sprite	*wall_side_right;
	t_sprite	*wall_roulette;
	t_sprite	*wall_blackjack;
	t_sprite	*collectible_idle;
	t_sprite	*collectible_open_0;
	t_sprite	*collectible_open_1;
	t_sprite	*collectible_open_2;
	t_sprite	*collectible_open_3;
	t_sprite	*collectible_open_4;
	t_sprite	*collectible_open_5;
	t_sprite	*collectible_open_6;
	t_sprite	*collectible_open_7;
	t_sprite	*collectible_open_8;
	t_sprite	*collectible_open_9;
	t_sprite	*ground;
	t_sprite	*exit;
	t_sprite	*player_danny_idle;
	t_sprite	*player_danny_move_up;
	t_sprite	*player_danny_move_down;
	t_sprite	*player_danny_move_left;
	t_sprite	*player_danny_move_right;
	t_sprite	*player_rusty_idle;
	t_sprite	*player_rusty_move_up;
	t_sprite	*player_rusty_move_down;
	t_sprite	*player_rusty_move_left;
	t_sprite	*player_rusty_move_right;
	t_sprite	*player_linus_idle;
	t_sprite	*player_linus_move_up;
	t_sprite	*player_linus_move_down;
	t_sprite	*player_linus_move_left;
	t_sprite	*player_linus_move_right;
	t_sprite	*player_basher_idle;
	t_sprite	*player_basher_move_up;
	t_sprite	*player_basher_move_down;
	t_sprite	*player_basher_move_left;
	t_sprite	*player_basher_move_right;
	t_sprite	*player_danny; // TO DELETE
	t_sprite	*player_rusty; // TO DELETE
	t_sprite	*player_linus; // TO DELETE
	t_sprite	*player_basher; // TO DELETE
	t_sprite	*dynamite;
	t_sprite	*explosion;
	t_sprite	*area_qte;
	t_sprite	*qte;
	t_sprite	*guard_idle;
	t_sprite	*guard_move_up;
	t_sprite	*guard_move_down;
	t_sprite	*guard_move_left;
	t_sprite	*guard_move_right;
	t_sprite	*guard; // TO DELETE
	t_sprite	*guard_fov;
	t_sprite	*button_pause;
	t_sprite	*button_reset;
	t_sprite	*button_quit;
	t_sprite	*button_tutorial;
	t_sprite	*plus_one;
	t_sprite	*heart;
	t_sprite	*box;
	t_sprite	*selection_box;
	t_sprite	*avatar_character;
	t_sprite	*alphabet;
	t_sprite	*special_character;
	t_sprite	*background_text;
	t_sprite	*talking_danny;
	t_sprite	*talking_rusty;
	t_sprite	*talking_linus;
	t_sprite	*talking_basher;
	t_sprite	*title_screen;
	t_sprite	*tutorial;
	t_sprite	*background;
	t_sprite	*lose_screen;
	t_sprite	*win_screen;
}	t_sprites_assets;

typedef struct s_init_sprite_asset_args
{
	char		*path;
	int			size;
	t_vector_2	dst_size;
}	t_init_sprite_asset_args;

typedef struct s_text_box
{
	bool			is_display;
	bool			read_all;
	t_vector_2		pos_display_background;
	t_vector_2		pos_display_face;
	t_vector_2		pos_display_text;
	t_vector_2		margin_size;
	t_vector_2		characters_max;
	int				characters_max_one_box;
	int				size_one_alphabet;
	int				page_number;
	int				page_in;
	int				talking_character;
	char			*text;
	char			**text_pages;
}	t_text_box;

typedef struct s_texts_box_list
{
	t_text_box				*text_box;
	struct s_texts_box_list	*next;
	struct s_texts_box_list	*prev;
}	t_texts_box_list;

typedef struct s_text
{
	char	*text;
	bool	has_been_display;
}	t_text;

typedef struct s_qte
{
	bool				pressed;
	bool				time_to_press;
	bool				pressed_in_time;
	bool				is_pickpocketing;
	t_vector_2			pickpocket_area;
	t_vector_2			pickpocket_size;
	struct timeval		start_time;
	struct timeval		time;
}	t_qte;

typedef struct s_bomb
{
	int					bomb_plant;
	int					bomb_total;
	int					bomb_chunk_pos;
	t_vector_2			bomb_pos;
	struct timeval		time;
	struct timeval		last_time;
	t_vector_2			*explosion_pos;
	int					explosion_tab_size;
	struct timeval		time_explosion;
	struct timeval		start_time_explosion;
}	t_bomb;

typedef struct s_collectible
{
	int			code;
	int			state;
	int			pos;
	t_sprite	*sprite_open_animation;
}	t_collectible;

typedef struct s_personage_animation
{
	t_sprite	*idle;
	t_sprite	*move_up;
	t_sprite	*move_down;
	t_sprite	*move_left;
	t_sprite	*move_right;
}	t_avatar_animation;

typedef struct s_player
{
	int					player_character;
	int					hp;
	bool				has_been_hit;
	bool				iframes;
	int					iframes_flashing;
	struct timeval		iframes_start_time;
	struct timeval		iframes_time;
	t_qte				qte;
	t_bomb				bomb;
	t_vector_2			size;
	t_vector_2			player_look_dir;
	t_vector_2			player_dir;	
	t_vector_2			player_pos;
	t_vector_2			player_chunk_pos;
	t_f_vector_2		player_f_pos;
	t_sprite			*player_sprite;
}	t_player;
// iframe -> Invincibility Frames

typedef struct s_guard
{
	bool			chasing_player;
	bool			is_alive;
	bool			is_pickpocketable;
	bool			is_in_player;
	int				guard_pos_tab;
	t_vector_2		size;
	t_vector_2		guard_look_dir;
	t_f_vector_2	guard_f_dir;
	t_vector_2		guard_chunk_pos;
	t_vector_2		guard_pos;
	t_f_vector_2	guard_f_pos;
	t_vector_2		guard_fov_pos_1;
	t_vector_2		guard_fov_pos_2;
	t_f_vector_2	guard_fov_f_pos_1;
	t_f_vector_2	guard_fov_f_pos_2;
	t_sprite		*guard_sprite;
	struct timeval	time;
	struct timeval	last_time;
	struct timeval	chase_start_time;
	struct timeval	chase_time;
}	t_guard;
// fov -> Field Of View

typedef struct s_gameplay
{
	bool					is_pause;
	bool					is_stop;
	bool					is_display_plus_one;
	bool					is_title_screen;
	bool					is_start;
	int						is_end;
	int						victory_text_status;
	int						tutorial_status;
	int						menu_status;
	int						available_character[4];
	int						chosen_character;
	t_collectible			*collectible;
	char					*collectible_code;
	t_text					*all_texts;
	t_texts_box_list		*dialogue;
	int						nb_collect_get;
	int						nb_collect_remain;
	int						nb_guard;
	int						nb_move;
	int						fps;
	char					*map_start_state;
	double					delta_time;
	t_vector_2				*chunks_pos;
	t_player				*player;
	t_guard					*guards;
	t_avatar_animation	*personage_animation;
}	t_gameplay;

typedef struct s_camera
{
	int				*chunks_to_display;
	int				nb_chunks_in_camera_total;
	t_img			img_background;
	t_vector_2		nb_chunks_in_camera;
	t_f_vector_2	camera_f_pos;
	t_f_vector_2	camera_f_size;
}	t_camera;

typedef struct s_game
{
	t_level				*level;
	t_window			*window;
	t_sprites_assets	*assets;
	t_gameplay			*gameplay;
	t_camera			*camera;
}	t_game;
// int		bpp; /* bits per pixel */

int					ft_printf(const char *string, ...);

// |================================================|
// |					SRC_CAMERA					|
// |================================================|

// |----------- CAMERA_CHUNKS ----------|

int					is_in_chunks_to_display(int *chunks_to_display,
						int size, int chunk);
void				get_chunks_to_display(t_game *game, t_camera *camera);

// |---------- CAMERA ----------|

void				display_background(t_window *window, t_img *img); //ERROR -> TEMPORARY
void				camera(t_game *game, t_camera *camera, t_player *player);

// |================================================|
// |					SRC_DEBUG					|
// |================================================|

// |----------- DEBUG_DISPLAY ----------|

void				display_map(t_img *img, t_game game);
void				display_debug(t_img *img, int color,
						t_vector_2 *chunk_pos, int size);
void				display_player_box_collider(t_img *img, t_player *player,
						int color);

// |---------- DEBUG_PRINT ---------|

void				debug_chunk_pos(t_game *game);
void				debug_stat_tiles(t_stat_tiles stat);

// |================================================|
// |					SRC_DISPLAY					|
// |================================================|

// |----------- DISPLAY_FEATURES_ANIMATION_MOVE --------|

int					get_guard_idle_frame(t_guard *guard);

t_sprite			*get_guard_move_animation(t_game *game, t_guard *guard,
						t_avatar_animation *animation);
t_sprite			*get_player_move_animation(t_game *game, t_player *player,
						t_avatar_animation *animation);

// |----------- DISPLAY_FEATURES_ANIMATION --------|

void				get_animation(t_game *game, t_gameplay *gameplay,
						t_sprite *sprite, int chunk_pos);

// |----------- DISPLAY_FEATURES_AT_START --------|

int					display_tutorial(t_game *game, t_gameplay *gameplay,
						t_window *window, int tutorial_status);

int					display_title_screen(t_game *game, t_window *window,
						int is_title_screen);

// |----------- DISPLAY_FEATURES_BOMB -----------|

void				display_bomb(t_player *player, t_bomb *bomb,
						t_game *game, t_window *window);

// |----------- DISPLAY_FEATURES_CHARACTER_ON_MAP -----------|

void				get_characters_on_map(t_game *game, t_window *window,
						t_gameplay *gameplay);

// |----------- DISPLAY_FEATURES_DIALOGUE_MAIN -----------|

void				display_dialogue(t_game *game,
						t_texts_box_list *texts_box_list);

// |----------- DISPLAY_FEATURES_DIALOGUE_TEXT_BOX -----------|

void				display_one_node_texts_box(t_game *game, t_window *window,
						t_text_box text_box);

void				display_character(t_game *game, t_window *window,
						t_vector_2 pos_display, char character);

// |----------- DISPLAY_FEATURES_ENDING_SCREEN -----------|

int					display_end_screen(t_game *game, int is_end);

// |----------- DISPLAY_GUARDS_MAIN ---------|

void				display_guards(t_game *game, t_gameplay *gameplay,
						t_window *window, t_guard *guards);

// |----------- DISPLAY_FEATURES_GUARDS_TURN_FOV ---------|

void				turn_guards(t_guard *guard);

// |----------- DISPLAY_FEATURES_MAIN ----------|

void				display_gameplay_features(t_game *game,
						t_gameplay *gameplay, t_window *window);
void				display_hp(t_window *window, t_player *player, int color);

// |----------- DISPLAY_FEATURES_MENU ----------|

int					display_menu(t_game *game, t_window *window, int is_pause);

// |----------- DISPLAY_FEATURES_QTE_LAUNCH ---------|

void				launch_qte(t_game *game, t_qte *qte, t_guard *guard);

// |----------- DISPLAY_FEATURES_QTE_MAIN --------|

void				display_qte(t_game *game, t_qte *qte, t_player *player,
						t_guard *guards);

// |----------- DISPLAY_FEATURES_UI_BOXS ---------|

void				display_ui_boxs(t_game *game, t_window *window,
						t_gameplay *gameplay);

// |----------- DISPLAY_FEATURES_UI_MAIN ---------|

void				display_one_str(t_game *game, t_vector_2 pos_display,
						char *text, int size_letter);
void				display_ui(t_game *game, t_window *window,
						t_gameplay *gameplay);

// |----------- DISPLAY_PLAYER ---------|

void				display_player(t_game *game, t_window *window,
						t_player *player, t_sprite *sprite);

// |----------- DISPLAY_SPRITES --------|

void				update_frame(t_sprite *sprite);
void				display_sprites(t_game *game, t_camera *camera,
						t_window *window);

// |----------- DISPLAY_TOOLS_1 ----------|

void				img_pix_put(t_img *img, int x, int y, int color);
void				put_image_to_image(t_img *window_img,
						t_vector_2 pos, t_img *img);
void				memcpy_img(t_img *img_dst, t_vector_2 pos_dst,
						t_img *img_src, t_vector_2 *pos_src);

__uint32_t			get_color_pixel(t_img *img, int i, int j);

// |----------- DISPLAY_TOOLS_2 ----------|

void				display_one_sprite_with_transparency(t_window *window,
						t_sprite *sprite, t_vector_2 pos);

// |================================================|
// |					SRC_EVENT					|
// |================================================|

// |----------- EVENTS_DIALOGUE_MAIN -----------|

int					display_victory_text(t_game *game,
						int *victory_text_status);

void				set_tutorial_text_box(t_game *game);
void				set_text_box_events_start(t_game *game);
void				get_text_box_events(t_game *game, t_gameplay *gameplay);

// |----------- EVENTS_DIALOGUE_UTILS ----------|

void				get_text_box_events_remain_zero_collectible(t_game *game,
						t_gameplay *gameplay);
void				get_text_box_events_remain_one_collectible(t_game *game,
						t_gameplay *gameplay);

// |----------- EVENTS_DIALOGUE_TOOLS ----------|

void				add_one_text_to_dialogue(t_game *game,
						t_texts_box_list **texts_box_list, t_text *text);

// |----------- TEXTS_BOX_LIST_UTILS_FREE ----------|

void				ft_lstclear_texts_box(t_texts_box_list **lst);
void				ft_lstdelone_texts_box(t_texts_box_list *lst);

// |----------- TEXTS_BOX_LIST_UTILS_MAIN ----------|

int					ft_lstsize_texts_box(t_texts_box_list *lst);
void				ft_lstadd_back_texts_box(t_texts_box_list **lst,
						t_texts_box_list *new);

t_texts_box_list	*ft_lstnew_texts_box(t_text_box *text_box);
t_texts_box_list	*ft_lstlast_texts_box(t_texts_box_list *lst);
t_texts_box_list	*ft_lstfirst_texts_box(t_texts_box_list *lst);

// |====================================================|
// |					SRC_GAMEPLAY					|
// |====================================================|

// |--------- GAMEPLAY_COLLECTIBLE ----------|

void				collected_one_collectible(t_game *game,
						t_gameplay *gameplay, int pos, int new_state);

// |--------- GAMEPLAY_COLLIDER_CHECK_TILE ----------|

void				check_tile(t_game *game, char tile, int pos);

// |----------- GAMEPLAY_COLLIDER_TOOLS -----------|

int					check_wall_collider(char *map, t_collider chunks);

void				check_collider(t_game *game, t_player *player,
						t_guard *guards);

t_collider			get_collider_on_move(t_f_vector_2 *move, t_player *player,
						int x_max);

// |---------- GAMEPLAY_COLLIDER_POSITIONS ----------|

int					is_inside_area(t_f_vector_2 pos, t_f_vector_2 pos_size,
						t_f_vector_2 area, t_f_vector_2 size_area);

void				check_collider_positions(t_game *game,
						t_player *player, t_guard *guards);

// |---------- GAMEPLAY_FEATURES_BOMB ----------|

void				make_bomb_explode(t_game *game, t_bomb bomb);
void				set_bomb_position(t_bomb *bomb, t_player *player,
						t_game *game);

// |----------- GAMEPLAY_FEATURES ----------|

void				gameplay_features(t_game *game, t_gameplay *gameplay);

// |---------- GAMEPLAY_MOVE_ANIMATION ---------|

void				move_animation(t_vector_2 look_dir, t_sprite *sprite);

// |----------- GAMEPLAY_RESTART_GAME ----------|

void				restart_the_game(t_game *game);

// |---------- GAMEPLAY_MOVE_GUARD ---------|

void				move_guard(t_game *game, t_guard *guard, t_player *player);

// |----------- GAMEPLAY_MOVE_GUARD_TOOLS ----------|

void				set_guard_pos(t_game *game, t_guard *guard,
						t_f_vector_2 move);
void				set_guard_look_dir(t_guard *guard, t_player *player,
						t_f_vector_2 move);
void				set_move_guard(t_guard *guard, t_f_vector_2 *move,
						double delta_time, t_vector_2 axe);
void				restrict_move_guard(t_f_vector_2 *move, t_guard *guard,
						t_vector_2 collider, t_vector_2 axe);

t_collider			get_collider_guard_on_move(t_f_vector_2 *move,
						t_guard *guard, int x_max);

// |---------- GAMEPLAY_MOVE_PLAYER_ANIMATION ----------|

void				move_player_animation(t_player *player, t_sprite *sprite);

// |----------- GAMEPLAY_MOVE_PLAYER -----------|

void				move_player(t_game *game, t_player *player);

// |---------- GAMEPLAY_MOVE_PLAYER_TOOLS ----------|

void				set_player_look_dir(t_player *player);
void				set_player_pos(t_player *player, t_f_vector_2 move);
void				set_move_player(t_player *player, t_f_vector_2 *move,
						double delta_time, t_vector_2 axe);
void				restrict_move(t_f_vector_2 *move, t_player *player,
						t_vector_2 collider, t_vector_2 axe);

// |---------- GAMEPLAY_PLAYER_TO_CHARACTER_FUNCTIONS ----------|

void				set_player_to_main(t_game *game, t_gameplay *gameplay,
						t_player *player);
void				set_player_to_eater(t_game *game, t_gameplay *gameplay,
						t_player *player);
void				set_player_to_thief(t_game *game, t_gameplay *gameplay,
						t_player *player);
void				set_player_to_bomber(t_game *game, t_gameplay *gameplay,
						t_player *player);

// |----------- GAMEPLAY_PLAYER_TO_CHARACTER_MAIN ----------|

void				set_player_to_character(t_game *game, t_gameplay *gameplay,
						t_player *player, int character);

// |---------- GAMEPLAY_TOOLS ----------|

void				calculate_fps(int *fps, double *delta_time);

// |============================================|
// |					SRC_GNL					|
// |============================================|

char				*get_next_line(int fd);

// |================================================|
// |					SRC_HANDLER					|
// |================================================|

// |----------- HANDLER_BOMB -----------|

void				handle_bomb(int keysym, t_game *game);

// |----------- HANDLER_DIALOGUE -----------|

int					handle_dialogue_next_text_box(t_game *game);
int					handle_dialogue(int keysym, t_game *game);

// |---------- HANDLER_GAME_FEATURES ---------|

int					close_game(t_game *game);
int					secure_lost_focus(t_game *game);
int					handle_end_screen(int keysym, t_game *game);
int					handle_title_screen(int keysym, t_game *game);

void				handle_out_game_features(int keysym, t_game *game);

// |----------- HANDLER_PAUSE_MENU -----------|

void				handle_pause_menu(int keysym, t_game *game);

// |---------- HANDLER_PLAYER_FEATURES ---------|

void				handle_pickpocket(int keysym, t_game *game);
void				handle_change_character_player(int keysym, t_game *game,
						t_gameplay *gameplay, t_player *player);

// |---------- HANDLER_PLAYER_MOVEMENT ---------|

void				handle_player_move_press(int keysym, t_game *game);
void				handle_player_move_release(int keysym, t_game *game);

// |---------- HANDLER ---------|

int					handle_keypress(int keysym, t_game	*game);
int					handle_keyrelease(int keysym, t_game *game);

// |---------- HANDLER_TUTORIAL ---------|

int					handle_tutorial(int keysym, t_game *game);

// |================================================|
// |					SRC_INIT					|
// |================================================|

// |---------- INIT_ASSETS_SPRITES_ANIMATIONS ----------|

void				init_sprites_animations(t_game *game, t_sprite *sprite,
						char character);

// |----------- INIT_SPRITES_ASSETS_HELPER_COLLECTIBLES -----------|

void				init_sprites_assets_collectibles(t_game *game,
						t_sprites_assets *assets);

// |----------- INIT_SPRITES_ASSETS_HELPER_OTHERS -----------|

void				init_sprites_assets_others(t_game *game,
						t_sprites_assets *assets);

// |----------- INIT_SPRITES_ASSETS_HELPER_PLAYER -----------|

void				init_sprites_assets_player(t_game *game,
						t_sprites_assets *assets);

// |----------- INIT_SPRITES_ASSETS_HELPER_UI_TEXT_BOX -----------|

void				init_sprites_assets_ui_text_box(t_game *game,
						t_sprites_assets *assets);

// |----------- INIT_SPRITES_ASSETS_HELPER_WALLS -----------|

void				init_sprites_assets_walls(t_game *game,
						t_sprites_assets *assets);

// |---------- INIT_ASSETS_SPRITES_IMAGES ----------|

void				init_xpm_file(t_game *game, void *ptr, char *path,
						t_img *img);

char				*find_sprite_path(t_game *game, char *start_path,
						int frame);

t_img				new_resize_img(t_game *game, void *ptr, t_img *src,
						t_vector_2 dst_size);

// |----------- INIT_SPRITES_ASSETS_MAIN -----------|

void				init_sprites_assets(t_game *game);

// |----------- INIT_SPRITES_ASSETS_TOOLS ----------|

void				init_one_sprite_asset(t_game *game, t_sprite **sprite,
						t_init_sprite_asset_args init_sprite_asset_args);

// |---------- GET_AVAILABLE_CHARACTER ---------|

int					*get_available_character(char **argv, int *argc_index,
						int *chosen_character);

// |----------- INIT_GAME_CAMERA -----------|

void				init_camera(t_game *game);

// |---------- INIT_GAME_MAIN ----------|

void				init_game(t_game *game, int *available_character,
						int chosen_character);
void				bzero_game(t_game *game);

// |----------- INIT_GAME_WINDOW -----------|

void				init_window(t_game *game);

// |---------- INIT_GAMEPLAY_ALL_TEXTS ---------|

void				init_all_texts_of_the_game(t_game *game,
						t_gameplay *gameplay);

// |---------- INIT_GAMEPLAY_COLLECTIBLE ---------|

void				init_collectible(t_game *game, t_gameplay *gameplay,
						t_collectible *collectible, char *collectible_code);

// |---------- INIT_GAMEPLAY_GUARD ---------|

void				set_guard_fov_direction(t_guard *guard);
void				init_guards(t_game *game, t_guard *guards);

// |---------- INIT_GAMEPLAY_MAIN ----------|

void				init_gameplay(t_game *game, int *available_character,
						int chosen_character);

void				init_one_text_box(t_game *game, t_window *window,
						t_gameplay *gameplay, t_text_box *text_box);

// |---------- INIT_GAMEPLAY_PERSONAGE_ANIMATION ----------|

t_avatar_animation	*init_avatar_animation(t_game *game,
						t_sprites_assets *assets);

// |----------- INIT_GAMPEPLAY_PLAYER ----------|

void				init_player(t_game *game, t_player *player,
						int chosen_character);
void				init_explosion_pos(t_game *game, t_bomb *bomb, bool alloc);

// |----------- INIT_GAMEPLAY_RANDOM_ELEMENTS ----------|

void				put_unavailable_character_on_map(t_game *game,
						t_gameplay *gameplay);

// |----------- INIT_SPRITES_MAIN ----------|

void				init_sprites(t_game *game);
void				init_sprite(t_img *image_asset, t_sprite *sprite, int size);

// |----------- INIT_SPRITES_ORGANIZATION -----------|

void				get_wall_image(t_game *game, t_sprite **sprite, int pos);

// |================================================|
// |					SRC_PARSING					|
// |================================================|

// |----------- LST_MAP_UTILS ----------|

int					ft_lstsize(t_lst_map *lst);

void				ft_lstclear(t_lst_map **lst);
void				ft_lstadd_back(t_lst_map **lst, t_lst_map *new);

t_lst_map			*ft_lstnew(void *content);
t_lst_map			*ft_lstlast(t_lst_map *lst);

// |----------- PARSE_MAP_UTILS_CHAR_MANIPULATIONS ---------|

char				*line_to_tab(char *line);
char				*char_2d_to_1d(char **map_2d, int x, int y);

// |----------- PARSE_MAP_UTILS_CHECK_MAP ----------|

int					is_ber(char *file_name);
int					is_closed(char **map, int x, int y);
int					is_rectangle(t_lst_map *lst, int size);
int					has_all_characters(char **map, int x, int y);

// |----------- PARSE_MAPS ---------|

void				parse_map(char *file_name, char **map,
						t_vector_2 *map_vector);

// |====================================================|
// |					SRC_PATHFINDING					|
// |====================================================|

// |----------- A_STAR_ALGORITHM -----------|

int					a_star(t_level *level, int pos, int end_pos);

// |----------- A_STAR_UTILS -----------|

int					dst_to_end(int pos, int end, int x);
int					calculate_dir_pos(int dir, int pos, int x);
int					find_character(t_level *level, char searched_char);

t_path_map			*init_path_map(t_level *level);

// |---------- PATHFINDING ---------|

void				pathfinding(t_game *game);

// |================================================|
// |					SRC_TOOLS					|
// |================================================|

// |---------- EXIT_ERROR_MESSAGE ----------|

void				exit_arg_error(void);
void				exit_map_error(char **map_2d, int y);
void				exit_option_error(int *available_character);
void				exit_pathfinding_error(t_level *level, char flag,
						int pos_error);

// |---------- FREE_ASSETS ---------|

void				free_assets(void *ptr, t_sprites_assets *assets);

// |---------- FREE_UTILS ----------|

void				free_2d_char_tab(char **tab, int y);
void				free_dialogue(t_texts_box_list *dialogue);
void				free_text_box_text_pages(t_text_box *text_box);

// |----------- FREE -----------|

void				exit_game(t_game game, const char *error);

// |----------- MEM_FUNCTIONS ----------|

char				*ft_strdup(const char *s);

void				ft_bzero(void *s, size_t n);
void				ft_memset(void *addr, int value, size_t n);

void				ft_memcpy(void *dest, const void *src, size_t n);

void				*ft_calloc(size_t nmemb, size_t size);

// |---------- POSITIONS_TOOLS----------|

int					pos_to_chunk(int x, int y, int x_max);

t_vector_2			chunk_to_pixel_pos(int chunk, int x_max);
t_f_vector_2		chunk_to_pixel_f_pos(int chunk, int x_max);

// |----------- UTILS ----------|

int					ft_nbrlen(int nb);
int					is_equals(char *s1, char *s2);

void				ft_itoa(int n, char result[10]);

char				*ft_strjoin(char const *s1, char const *s2);

size_t				ft_strlen(const char *s);

// |----------- VECTOR_FUNCTIONS -----------|

t_f_vector_2		normalize(t_vector_2 vector);
t_f_vector_2		direction_normalized(t_vector_2 src, t_vector_2 dest);

//========================================

// |----------- GAME -----------|

void				start_game(t_game *game);

// |---------- SO_LONG ---------|

//------------------------------------------

// |================================================|
// |					TEMPORARY					|
// |================================================|

void				debug_fps(t_game *game);
void				ft_print_1d_to_2d(t_level *level);
void				ft_print_lst_map(t_lst_map *lst_map);
void				ft_print_map(char **map, int x, int y);
void				ft_print_path_map_status(t_level *level);
void				debug_player_box_collider(t_player *player);
void				ft_print_path_map(t_level *level, int end_pos);
void				ft_print_chunk_pos(t_vector_2 *chunk_pos, int c_count);
void				ft_print_collectibles_pos(t_vector_2 *c_pos, int c_count);

#endif
