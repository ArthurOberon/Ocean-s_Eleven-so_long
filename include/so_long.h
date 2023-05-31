/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthuroberon <arthuroberon@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:12:41 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/31 23:55:13 by arthurobero      ###   ########.fr       */
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

# define SPRITES_PATH "assets/sprites/xpm/"

# define PATH_WALL_CORNER_N_O	"wall/column_corner_N-O_64px"
# define PATH_WALL_CORNER_N_E	"wall/column_corner_N-E_64px"
# define PATH_WALL_CORNER_S_E	"wall/column_corner_S-E_64px"
# define PATH_WALL_CORNER_S_O	"wall/column_corner_S-O_64px"
# define PATH_WALL_SIDE_UP		"wall/column_side_up_64px"
# define PATH_WALL_SIDE_DOWN	"wall/column_side_down_64px"
# define PATH_WALL_SIDE_LEFT	"wall/column_side_left_64px"
# define PATH_WALL_SIDE_RIGHT	"wall/column_side_right_64px"
# define PATH_WALL_ROULETTE		"wall/roulette_table_64px"
# define PATH_WALL_POKER		"wall/poker_table_64px"

# define PATH_GROUND			"ground/carpet_64px"
# define PATH_COLLECT			"debug/test_32px"
# define PATH_EXIT				"debug/test"

# define PATH_PLAYER_DANNY		"player/danny/danny_64px"
# define PATH_PLAYER_RUSTY		"player/rusty/rusty_2_64px"
# define PATH_PLAYER_LINUS		"player/linus/linus_64px"
# define PATH_PLAYER_BASHER		"player/basher/basher_64px"

# define PATH_DYNAMITE			"dynamite/dynamite_64px"
# define PATH_EXPLOSION			"dynamite/explosion_64px"

# define PATH_AREA_QTE			"qte/area_64px"
# define PATH_QTE				"qte/now"

# define PATH_GUARD				"guard/guard_64px"
# define PATH_GUARD_FOV			"guard/fov_2_64px"

# define PATH_HEART				"ui/heart"
# define PATH_BOX				"ui/box_64px"
# define PATH_SELECTION_BOX		"ui/character_selection_box_64px"
# define PATH_AVATAR_CHARACTER	"ui/avatar_character_64px"

# define PATH_ALPHABET			"text_box/alphabet/alphabet_16px"
# define PATH_SPECIAL_CHAR		"text_box/special_char/special_character_16px"
# define PATH_BACKGROUND_TEXT	"text_box/background_text_3_64px"

# define PATH_BACKGROUND		"ground/carpet_64px"

# define FRAME_GROUND 1
# define FRAME_COLLECT 1
# define FRAME_EXIT 1

# define FRAME_PLAYER_DANNY 10
# define FRAME_PLAYER_RUSTY 1
# define FRAME_PLAYER_LINUS 1
# define FRAME_PLAYER_BASHER 1

# define FRAME_MOVEMENT 2

# define FRAME_DYNAMITE 5
# define FRAME_EXPLOSION 1

# define FRAME_AREA_QTE 1
# define FRAME_QTE 5

# define FRAME_GUARD 1
# define FRAME_GUARD_FOV 1

# define FRAME_HEART 1
# define FRAME_BOX 1
# define FRAME_SELECTION_BOX 2
# define FRAME_AVATAR_CHARACTER 1

# define FRAME_ALPHABET 26
# define FRAME_SPECIAL_CHAR 31
# define FRAME_BACKGROUND_TEXT 1

# define DELAY_ANIMATION 2

# define DELAY_TURN_GUARD 2.5
# define DELAY_GUARD_CHASE_PLAYER 6

# define DELAY_IFRAMES 1.5

# define DELAY_QTE	3
# define DELAY_REACTION 1

# define BOMB_TIMING 1.3
# define BOMB_NUMBER 5
# define DELAY_BOMB_EXPLOSION 0.7

# define IS_DEBUG 0
# define IS_DEBUG_TIME 0

# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define BLACK 0x000000

# define INT_MIN -2147483648
# define INT_MAX 2147483647

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
	e_heart,
	e_box,
	e_selection_box,
	e_avatar_character,
	e_alphabet,
	e_special_character,
	e_background_text,
	e_total_assets,
};

enum e_player_character
{
	e_main,
	e_eater,
	e_thief,
	e_bomber,
};

enum e_texts
{
	e_text_start,
	e_text_take_danny,
	e_text_remain_one_collectible,
	e_text_remain_zero_collectible,
	e_total_text_number,
};

// e_main = danny
// e_eater = rusty
// e_thief = linus
// e_bomber = basher

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
	t_sprite	*player_danny;
	t_sprite	*player_rusty;
	t_sprite	*player_linus;
	t_sprite	*player_basher;
	t_sprite	*exit;
	t_sprite	*collect;
	t_sprite	*ground;
	t_sprite	*guard;
	t_sprite	*guard_fov;
	t_sprite	*wall_corner_n_o;
	t_sprite	*wall_corner_n_e;
	t_sprite	*wall_corner_s_e;
	t_sprite	*wall_corner_s_o;
	t_sprite	*wall_side_up;
	t_sprite	*wall_side_down;
	t_sprite	*wall_side_left;
	t_sprite	*wall_side_right;
	t_sprite	*wall_roulette;
	t_sprite	*wall_poker;
	t_sprite	*dynamite;
	t_sprite	*explosion;
	t_sprite	*area_qte;
	t_sprite	*qte;
	t_sprite	*heart;
	t_sprite	*box;
	t_sprite	*selection_box;
	t_sprite	*avatar_character;
	t_sprite	*alphabet;
	t_sprite	*special_character;
	t_sprite	*background_text;
}	t_sprites_assets;

typedef struct s_text_box
{
	bool		is_display;
	bool		read_all;
	t_vector_2	pos_display_background;
	t_vector_2	pos_display_face;
	t_vector_2	pos_display_text;
	t_vector_2	margin_size;
	t_vector_2	characters_max;
	int			characters_max_one_box;
	int			size_one_alphabet;
	int			page_number;
	int			page_in;
	int			talking_character;
	char		*text;
	char		**text_pages;
}	t_text_box;

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
	struct timeval	time;
	struct timeval	last_time;
	struct timeval	chase_start_time;
	struct timeval	chase_time;
}	t_guard;
// fov -> Field Of View

typedef struct s_gameplay
{
	bool				is_pause;
	bool				is_stop;
	bool				display_plus_one;
	int					available_character[4];
	int					chosen_character;
	t_text_box			text_box;
	t_text				*texts;
	int					nb_collect_get;
	int					nb_collect_remain;
	int					nb_guard;
	int					nb_move;
	int					fps;
	char				*map_start_state;
	double				delta_time;
	t_vector_2			*chunks_pos;
	t_player			*player;
	t_guard				*guards;
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

// |================================================|
// |					SRC_CAMERA					|
// |================================================|

// |------------------------------------|
// |			CAMERA_CHUNKS			|
// |------------------------------------|

int					is_in_chunks_to_display(int *chunks_to_display,
						int size, int chunk);
void				get_chunks_to_display(t_game *game, t_camera *camera);

// |----------------------------|
// |			CAMERA			|
// |----------------------------|

void				camera(t_game *game, t_camera *camera, t_player *player);

// |================================================|
// |					SRC_DEBUG					|
// |================================================|

// |------------------------------------|
// |			DEBUG_DISPLAY			|
// |------------------------------------|

void				display_map(t_img *img, t_game game);
void				display_debug(t_img *img, int color,
						t_vector_2 *chunk_pos, int size);
void				display_player_box_collider(t_img *img, t_player *player,
						int color);

// |--------------------------------|
// |			DEBUG_PRINT			|
// |--------------------------------|

void				debug_chunk_pos(t_game *game);
void				debug_stat_tiles(t_stat_tiles stat);

// |====================================================|
// |					SRC_DISPLAY_MLX					|
// |====================================================|

// |------------------------------------|
// |			DISPLAY_BOMB			|
// |------------------------------------|

void				display_bomb(t_player *player, t_bomb *bomb,
						t_game *game, t_window *window);

// |------------------------------------------------|
// |			DISPLAY_GAMEPLAY_ELEMENTS			|
// |------------------------------------------------|

void				display_nb_move(t_game *game);
void				display_gameplay_elements(t_game *game,
						t_gameplay *gameplay, t_window *window);
void				display_hp(t_window *window, t_player *player, int color);

// |------------------------------------|
// |			DISPLAY_GUARDS			|
// |------------------------------------|

void				display_guards(t_game *game, t_gameplay *gameplay,
						t_window *window, t_guard *guards);

// |------------------------------------|
// |			DISPLAY_PLAYER			|
// |------------------------------------|

void				display_player(t_game *game, t_window *window,
						t_player *player, t_sprite *sprite);

// |--------------------------------|
// |			DISPLAY_QTE			|
// |--------------------------------|

void				display_qte(t_game *game, t_qte *qte, t_player *player,
						t_guard *guards);

// |------------------------------------|
// |			DISPLAY_SPRITES			|
// |------------------------------------|

void				update_frame(t_sprite *sprite);
void				display_sprites(t_game *game, t_camera *camera,
						t_window *window);

// |----------------------------------------|
// |			DISPLAY_TEXT_BOX			|
// |----------------------------------------|

void				display_text_box(t_game *game, t_window *window,
						t_text_box text_box);

void				display_character(t_game *game, t_window *window,
						t_vector_2 pos_display, char character);

// |------------------------------------|
// |			DISPLAY_TOOLS			|
// |------------------------------------|

void				background(t_img *img, int color);
void				img_pix_put(t_img *img, int x, int y, int color);
void				put_image_to_image(t_img *window_img,
						t_vector_2 pos, t_img *img);
void				memcpy_img(t_img *img_dst, t_vector_2 pos_dst,
						t_img *img_src, t_vector_2 *pos_src);

__uint32_t			get_color_pixel(t_img *img, int i, int j);

// |--------------------------------|
// |			DISPLAY_UI			|
// |--------------------------------|

void				display_one_str(t_game *game, t_vector_2 pos_display,
						char *text, int size_letter);
void				display_ui(t_game *game, t_window *window,
						t_gameplay *gameplay);

// |====================================================|
// |					SRC_GAMEPLAY					|
// |====================================================|

// |----------------------------|
// |			BOMB			|
// |----------------------------|

void				make_bomb_explode(t_game *game, t_bomb bomb);
void				get_bomb_position(t_bomb *bomb, t_player *player,
						t_game *game);

// |----------------------------------------|
// |			COLLIDER_POSITIONS			|
// |----------------------------------------|

int					is_inside_area(t_f_vector_2 pos, t_f_vector_2 pos_size,
						t_f_vector_2 area, t_f_vector_2 size_area);

void				check_collider_positions(t_game *game,
						t_player *player, t_guard *guards);

// |--------------------------------|
// |			COLLIDER			|
// |--------------------------------|

int					check_wall_collider(char *map, t_collider chunks);

void				check_collider(t_game *game, t_player *player,
						t_guard *guards);

t_collider			get_collider_on_move(t_f_vector_2 *move, t_player *player,
						int x_max);

// |----------------------------------------|
// |			GAMEPLAY_ELEMENTS			|
// |----------------------------------------|

void				gameplay_elements(t_game *game, t_gameplay *gameplay);

// |------------------------------------|
// |			GAMEPLAY_TOOLS			|
// |------------------------------------|

void				restart(t_game *game);
void				calculate_fps(int *fps, double *delta_time);
void				set_player_to_character(t_game *game, t_gameplay *gameplay,
						t_player *player, int character);

// |----------------------------------------|
// |			HANDLER_GAMEPLAY			|
// |----------------------------------------|

void				handle_bomb(int keysym, t_game *game);
void				handle_pickpocket(int keysym, t_game *game);
void				handle_player_move(int keysym, t_game *game);
void				handle_player_move_release(int keysym, t_game *game);
void				handle_change_character_player(int keysym, t_game *game,
						t_gameplay *gameplay, t_player *player);

// |----------------------------|
// |			HANDLER			|
// |----------------------------|

int					close_game(t_game *game);
int					secure_lost_focus(t_game *game);
int					handle_keypress(int keysym, t_game	*game);
int					handle_keyrelease(int keysym, t_game *game);

// |----------------------------------------|
// |			MOVE_GUARD_TOOLS			|
// |----------------------------------------|

void				set_guard_pos(t_game *game, t_guard *guard,
						t_f_vector_2 move);
void				get_move_guard(t_guard *guard, t_f_vector_2 *move,
						double delta_time, t_vector_2 axe);
void				restrict_move_guard(t_f_vector_2 *move, t_guard *guard,
						t_vector_2 collider, t_vector_2 axe);

t_collider			get_collider_guard_on_move(t_f_vector_2 *move,
						t_guard *guard, int x_max);

// |--------------------------------|
// |			MOVE_GUARD			|
// |--------------------------------|

void				move_guard(t_game *game, t_guard *guard, t_player *player);

// |----------------------------------------|
// |			MOVE_PLAYER_TOOLS			|
// |----------------------------------------|

void				set_player_look_dir(t_player *player);
void				move_animation(t_player *player, t_sprite *sprite);
void				set_player_pos(t_player *player, t_f_vector_2 move);
void				get_move_player(t_player *player, t_f_vector_2 *move,
						double delta_time, t_vector_2 axe);
void				restrict_move(t_f_vector_2 *move, t_player *player,
						t_vector_2 collider, t_vector_2 axe);

// |--------------------------------|
// |			MOVE_PLAYER			|
// |--------------------------------|

void				move_player(t_game *game, t_player *player);

// |------------------------------------|
// |			POSITIONS_TOOLS			|
// |------------------------------------|

int					pos_to_chunk(int x, int y, int x_max);

t_vector_2			chunk_to_pixel_pos(int chunk, int x_max);
t_f_vector_2		chunk_to_pixel_f_pos(int chunk, int x_max);

// |------------------------------------|
// |			TEXT_BOX_EVENTS			|
// |------------------------------------|

void				text_box_events(t_game *game, t_gameplay *gameplay);

// |--------------------------------|
// |			TEXT_BOX			|
// |--------------------------------|

void				set_text_box(t_game *game, t_text_box *text_box,
						char *text);
void				display_text(t_game *game, t_text_box *text_box,
						t_text *text, bool not_display_again);

// |============================================|
// |					SRC_GNL					|
// |============================================|

char				*get_next_line(int fd);

// |================================================|
// |					SRC_INIT					|
// |================================================|

// |--------------------------------------------|
// |			GET_AVAILABLE_CHARACTER			|
// |--------------------------------------------|

int					*get_available_character(char **argv, int *argc_map,
						int *chosen_character);

// |--------------------------------|
// |			INIT_CAMERA			|
// |--------------------------------|

void				init_camera(t_game *game);

// |--------------------------------|
// |			INIT_GAME			|
// |--------------------------------|

void				init_game(t_game *game, int *available_character,
						int chosen_character);
void				bzero_game(t_game *game);

// |------------------------------------|
// |			INIT_GAMEPLAY			|
// |------------------------------------|

void				init_gameplay(t_game *game, int *available_character,
						int chosen_character);

// |--------------------------------|
// |			INIT_GUARD			|
// |--------------------------------|

void				set_guard_fov_direction(t_guard *guard);
void				init_guards(t_game *game, t_guard *guards);

// |--------------------------------|
// |			INIT_IMAGES			|
// |--------------------------------|

void				init_xpm_file(t_game *game, void *ptr, char *path,
						t_img *img);
void				init_new_resize_img(t_game *game, void *ptr, t_img *new_img,
						t_vector_2 new_size);

char				*find_sprite_path(t_game *game, char *start_path,
						int frame);

t_img				new_resize_img(t_game *game, void *ptr, t_img *src,
						t_vector_2 dst_size);



// |--------------------------------|
// |			INIT_PLAYER			|
// |--------------------------------|

void				init_player(t_game *game, t_player *player,
						int chosen_character);
void				init_explosion_pos(t_game *game, t_bomb *bomb, bool alloc);

// |--------------------------------------------|
// |			INIT_RANDOM_ELEMENTS			|
// |--------------------------------------------|

void				put_unavailable_character_on_map(t_game *game,
						t_gameplay *gameplay);

// |----------------------------------------|
// |			INIT_SPRITES_ASSETS			|
// |----------------------------------------|


void				init_sprites_assets(t_game *game);

// |------------------------------------|
// |			INIT_SPRITES			|
// |------------------------------------|

void				init_sprites(t_game *game);
void				init_sprite(t_img *image_asset, t_sprite *sprite, int size);

// |--------------------------------|
// |			INIT_WINDOW			|
// |--------------------------------|

void				init_window(t_game *game);

// |----------------------------------------|
// |			SPRITES_ARRENGEMENT			|
// |----------------------------------------|

void				get_wall_image(t_game *game, t_sprite **sprite, int pos);

// |================================================|
// |					SRC_PARSING					|
// |================================================|

// |------------------------------------|
// |			LST_MAP_UTILS			|
// |------------------------------------|

int					ft_lstsize(t_lst_map *lst);

void				ft_lstclear(t_lst_map **lst);
void				ft_lstadd_back(t_lst_map **lst, t_lst_map *new);

t_lst_map			*ft_lstnew(void *content);
t_lst_map			*ft_lstlast(t_lst_map *lst);

// |--------------------------------------------------------|
// |			PARSE_MAP_UTILS_CHAR_MANIPULATIONS			|
// |--------------------------------------------------------|

void				free_2d_char_tab(char **tab, int y);

char				*line_to_tab(char *line);
char				*char_2d_to_1d(char **map_2d, int x, int y);

// |------------------------------------------------|
// |			PARSE_MAP_UTILS_check_MAP			|
// |------------------------------------------------|

int					is_ber(char *file_name);
int					is_closed(char **map, int x, int y);
int					is_rectangle(t_lst_map *lst, int size);
int					has_all_characters(char **map, int x, int y);

// |--------------------------------|
// |			PARSE_MAPS			|
// |--------------------------------|

void				parse_map(char *file_name, char **map,
						t_vector_2 *map_vector);

// |====================================================|
// |					SRC_PATHFINDING					|
// |====================================================|

// |----------------------------------------|
// |			A_STAR_ALGORITHM			|
// |----------------------------------------|

int					a_star(t_level *level, int pos, int end_pos);

// |------------------------------------|
// |			A_STAR_UTILS			|
// |------------------------------------|

int					dst_to_end(int pos, int end, int x);
int					calculate_dir_pos(int dir, int pos, int x);
int					find_character(t_level *level, char searched_char);

t_path_map			*init_path_map(t_level *level);

// |--------------------------------|
// |			PATHFINDING			|
// |--------------------------------|

void				pathfinding(t_game *game);

// |================================================|
// |					SRC_TOOLS					|
// |================================================|

// |----------------------------|
// |			EXIT			|
// |----------------------------|

void				exit_arg_error(void);
void				exit_map_error(char **map_2d, int y);
void				exit_pathfinding_error(t_level *level, char flag,
						int pos_error);

// |--------------------------------|
// |			FREE_UTILS			|
// |--------------------------------|

void				free_text_box(t_text_box *text_box);
void				free_one_sprite(void *ptr, t_sprite *sprite);
void				free_assets(void *ptr, t_sprites_assets *assets);

// |----------------------------|
// |			FREE			|
// |----------------------------|

void				free_game(t_game game, const char *error);

// |------------------------------------|
// |			MEM_FUNCTIONS			|
// |------------------------------------|

char				*ft_strdup(const char *s);

void				ft_bzero(void *s, size_t n);
void				ft_memset(void *addr, int value, size_t n);

void				*ft_calloc(size_t nmemb, size_t size);
void				*ft_memcpy(void *dest, const void *src, size_t n);

// |------------------------------------|
// |			PRINT_FUNCTIONS			|
// |------------------------------------|

void				ft_putnbr(int nb);
void				ft_putstr(char *s);
void				ft_putchar(char c);

size_t				ft_strlen(const char *s);

// |----------------------------|
// |			UTILS			|
// |----------------------------|

int					ft_nbrlen(int nb);
int					is_equals(char *s1, char *s2);

char				*ft_itoa(int n);
char				*ft_strjoin(char const *s1, char const *s2);

long unsigned int	ft_abs(long n);

// |----------------------------------------|
// |			VECTOR_FUNCTIONS			|
// |----------------------------------------|

t_f_vector_2		normalize(t_vector_2 vector);
t_f_vector_2		direction_normalized(t_vector_2 src, t_vector_2 dest);

//========================================

// |----------------------------|
// |			GAME			|
// |----------------------------|

void				start_game(t_game *game);

// |----------------------------|
// |			SO_LONG			|
// |----------------------------|

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
