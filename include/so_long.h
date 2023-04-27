/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:12:41 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/27 12:43:30 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <time.h>

// CAUTION /!/\/
# include <stdio.h>

# define WINDOW_WIDTH 1600
# define WINDOW_HEIGHT 800

# define CHUNK_SIZE 128

# define SPRITES_PATH "sprites/"
# define FRAME_EXIT 1
# define FRAME_PLAYER 1
# define FRAME_GROUND 2
# define FRAME_COLLECT 1

# define DELAY_ANIMATION 2

# define IS_DEBUG 1

# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define BLACK 0x000000

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_lst_map
{
	char				*line;
	struct s_lst_map	*next;
}	t_lst_map;

typedef struct s_map_flag
{
	int	bool_p;
	int	bool_e;
	int	bool_c;
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
	t_img	*sprite_img;
	int		frame;
	int		size;
	double	last_time;
}	t_sprite;

typedef struct s_level
{
	char		*map;
	t_vector_2	map_vector;
	int			nb_cases;
	int			player_pos_tab;
	int			exit_pos;
	t_path_map	*path_map;
}	t_level;

typedef struct s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_sprite	*map_sprites;
}	t_window;

typedef struct s_game
{
	t_level		level;
	t_window	window;
	t_vector_2	player_pos;
	t_vector_2	*chunks_pos;
}	t_game;

	// int		bpp; /* bits per pixel */

// |====================================================|
// |					SRC_DISPLAY_MLX					|
// |====================================================|

// |------------------------------------|
// |			DISPLAY_DEBUG			|
// |------------------------------------|

void				display_map(t_img *img, t_game game);
void				display_debug(t_img *img, int color,
						t_vector_2 *chunk_pos, int size);

// |------------------------------------|
// |			DISPLAY_SPRITES			|
// |------------------------------------|

void				display_sprites(t_game *game);

// |------------------------------------|
// |			DISPLAY_TOOLS			|
// |------------------------------------|

void				background(t_img *img, int color);
void				img_pix_put(t_img *img, int x, int y, int color);

__uint32_t			get_color_pixel(t_img *img, int i, int j);

// |----------------------------|
// |			DISPLAY			|
// |----------------------------|

void				display(t_game *game);

// |====================================================|
// |					SRC_GAMEPLAY					|
// |====================================================|

// |----------------------------|
// |			HANDLER			|
// |----------------------------|

int					close_window(t_window *window);
int					handle_keypress(int keysym, t_game	*game);

// |============================================|
// |					SRC_GNL					|
// |============================================|

char				*get_next_line(int fd);

// |====================================================|
// |					SRC_INIT_MLX					|
// |====================================================|

// |--------------------------------|
// |			INIT_DATA			|
// |--------------------------------|

t_window			init_window(t_game *game);

// |--------------------------------|
// |			INIT_IMAGES			|
// |--------------------------------|

void				init_xpm_file(void *ptr, char *path, t_img *img);
void				init_new_resize_img(void *ptr, t_img *new_img,
						t_vector_2 new_size);

t_img				resize_img(void *ptr, t_img *src, t_vector_2 dst_size);

// |------------------------------------|
// |			INIT_SPRITES			|
// |------------------------------------|

void				init_sprites(t_game *game);
void				init_sprite(void *ptr, t_sprite *sprite, int size,
						char *path);

// |----------------------------------------|
// |			SPRITES_ARRENGEMENT			|
// |----------------------------------------|

void				get_wall_image(t_game *game, t_sprite *sprite, int pos);

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

// |--------------------------------------------------------|T
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

int					parse_map(char *file_name, char **map,
						t_vector_2 *map_vector);

// |====================================================|
// |					SRC_PATHFINDING					|
// |====================================================|

// |----------------------------------------|
// |			A_STAR_ALGORITHM			|
// |----------------------------------------|

int					a_star(t_level level, int pos, int end_pos);

// |------------------------------------|
// |			A_STAR_UTILS			|
// |------------------------------------|

int					dst_to_end(int pos, int end, int x);
int					calculate_dir_pos(int dir, int pos, int x);
int					find_character(t_level level, char searched_char);

t_path_map			*init_path_map(t_level level);

// |--------------------------------|
// |			PATHFINDING			|
// |--------------------------------|

int					pathfinding(t_game *game);

// |================================================|
// |					SRC_TOOLS					|
// |================================================|

// |----------------------------|
// |			EXIT			|
// |----------------------------|

void				exit_arg_error(void);
void				exit_map_error(void);
void				exit_pathfinding(t_level level, char flag, int pos_error);

// |----------------------------|
// |			FREE			|
// |----------------------------|

void				free_game(t_game game);

// |------------------------------------|
// |			MEM_FUNCTIONS			|
// |------------------------------------|
void				ft_bzero(void *s, size_t n);

void				ft_memset(void *addr, size_t n, int value);

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

int					is_equals(char *s1, char *s2);

char				*ft_itoa(int n);
char				*ft_strjoin(char const *s1, char const *s2);

long unsigned int	ft_abs(long n);

//========================================

// |----------------------------|
// |			SO_LONG			|
// |----------------------------|

//------------------------------------------

// |================================================|
// |					TEMPORARY					|
// |================================================|

void				ft_print_1d_to_2d(t_level level);
void				ft_print_path_map(t_level level, int end_pos);
void				ft_print_lst_map(t_lst_map *lst_map);
void				ft_print_map(char **map, int x, int y);
void				ft_print_path_map_status(t_level level);
void				ft_print_chunk_pos(t_vector_2 *chunk_pos, int c_count);
void				ft_print_collectibles_pos(t_vector_2 *c_pos, int c_count);

#endif
