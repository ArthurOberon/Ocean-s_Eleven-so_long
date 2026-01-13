/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:24:37 by aoberon           #+#    #+#             */
/*   Updated: 2026/01/13 17:30:40 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

#include "libs.h"

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
	e_text_tutorial_1,
	e_text_tutorial_2,
	e_text_tutorial_3,
	e_text_tutorial_4,
	e_text_tutorial_5,
	e_text_tutorial_6,
	e_text_tutorial_7,
	e_text_tutorial_8,
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
	e_text_collect_steal_code,
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

typedef struct s_stat_tiles
{
	int	exit;
	int	wall;
	int	ground;
	int	player;
	int	collect;
}	t_stat_tiles;

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

typedef struct s_init_sprite_asset_args
{
	char		*path;
	int			size;
	t_vector_2	dst_size;
}	t_init_sprite_asset_args;

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

typedef struct s_avatar_animation
{
	t_sprite	*idle;
	t_sprite	*move_up;
	t_sprite	*move_down;
	t_sprite	*move_left;
	t_sprite	*move_right;
}	t_avatar_animation;

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

typedef struct s_collectible
{
	int			code;
	int			state;
	int			pos;
	t_sprite	*sprite_open_animation;
}	t_collectible;

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

typedef struct s_qte
{
	bool				pressed;
	bool				pressed_within_qte;
	bool				is_pickpocketing;
	int					loading_frame;
	int					loading_value;
	int					pixel_start;
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
	t_sprite			*player_sprite;
}	t_player;
// iframe -> Invincibility Frames

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
	t_sprite	*dynamite;
	t_sprite	*explosion;
	t_sprite	*area_qte;
	t_sprite	*qte;
	t_sprite	*guard_idle;
	t_sprite	*guard_move_up;
	t_sprite	*guard_move_down;
	t_sprite	*guard_move_left;
	t_sprite	*guard_move_right;
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
	t_sprite	*lose_screen;
	t_sprite	*win_screen;
	t_sprite	*background;
}	t_sprites_assets;

typedef struct s_gameplay
{
	bool				is_pause;
	bool				is_stop;
	bool				is_display_plus_one;
	bool				is_title_screen;
	bool				is_start;
	int					is_end;
	int					victory_text_status;
	int					tutorial_status;
	int					menu_status;
	int					available_character[4];
	int					chosen_character;
	int					nb_collect_get;
	int					nb_collect_remain;
	t_collectible		*collectible;
	char				*collectible_code;
	t_text				*all_texts;
	t_texts_box_list	*dialogue;
	t_player			*player;
	int					nb_guard;
	t_guard				*guards;
	int					nb_move;
	int					fps;
	double				delta_time;
	t_vector_2			*chunks_pos;
	t_avatar_animation	*avatar_animation;
	t_sprite			*talking_face[4];
	char				*map_start_state;
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

#endif