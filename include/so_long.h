/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:12:41 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/03 16:26:05 by aoberon          ###   ########.fr       */
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

// CAUTION /!/\/
# include <stdio.h>

# define WINDOW_WIDTH 1600
# define WINDOW_HEIGHT 800

# define IS_DEBUG 0

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

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

typedef struct s_vector_2
{
	int	x;
	int	y;
}	t_vector_2;

typedef struct s_path_map
{
	int	has_been_check;
	int	dst_to_start;
	int	dst_to_end;
	int	f;
	int	parent;
}	t_path_map;

typedef struct s_level
{
	char		*map;
	t_vector_2	map_vector;
	int			nb_cases;
	int			player_pos;
	int			exit_pos;
	t_path_map	*path_map;
}	t_level;

typedef struct s_game
{
	t_level	level;
}	t_game;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_game		game;
}	t_data;

	// int		bpp; /* bits per pixel */

// |============================================|
// |					GNL_SRC					|
// |============================================|

char				*get_next_line(int fd);

// |============================================|
// |					MAP_SRC					|
// |============================================|

// |--------------------------------|
// |			PARSE_MAPS			|
// |--------------------------------|

int					parse_map(char *file_name, char **map,
						t_vector_2 *map_vector);

// |------------------------------------------------|
// |			PARSE_MAP_UTILS_check_MAP			|
// |------------------------------------------------|

int					is_ber(char *file_name);
int					is_closed(char **map, int x, int y);
int					is_rectangle(t_lst_map *lst, int size);
int					has_all_characters(char **map, int x, int y);

// |--------------------------------------------------------|T
// |			PARSE_MAP_UTILS_CHAR_MANIPULATIONS			|
// |--------------------------------------------------------|

char				*line_to_tab(char *line);
void				free_2d_char_tab(char **tab, int y);
char				*char_2d_to_1d(char **map_2d, int x, int y);

// |================================================|
// |					ERROR_SRC					|
// |================================================|

void				exit_arg_error(void);
void				exit_map_error(void);
void				exit_pathfinding(t_level level, char flag, int pos_error);

// |================================================|
// |					UTILS_SRC					|
// |================================================|

// |----------------------------|
// |			UTILS			|
// |----------------------------|

int					is_equals(char *s1, char *s2);
long unsigned int	ft_abs(long n);

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

// |================================================|
// |					LIST_SRC					|
// |================================================|

// |------------------------------------|
// |			LST_MAP_UTILS			|
// |------------------------------------|

int					ft_lstsize(t_lst_map *lst);

void				ft_lstclear(t_lst_map **lst);
void				ft_lstadd_back(t_lst_map **lst, t_lst_map *new);

t_lst_map			*ft_lstnew(void *content);
t_lst_map			*ft_lstlast(t_lst_map *lst);

// |================================================|
// |					DISPLAY_SRC					|
// |================================================|

// |----------------------------|
// |			HANDLER			|
// |----------------------------|

int					close_window(t_data *data);
int					handle_keypress(int keysym, t_data *data);

// |----------------------------|
// |			DISPLAY			|
// |----------------------------|

void				display(t_game *game);

// |====================================================|
// |					PATHFINDING_SRC					|
// |====================================================|

// |--------------------------------|
// |			PATHFINDING			|
// |--------------------------------|

int					pathfinding(t_game *game);

// |------------------------------------|
// |			A_STAR_UTILS			|
// |------------------------------------|

int					dst_to_end(int pos, int end, int x);
int					calculate_dir_pos(int dir, int pos, int x);
int					find_character(t_level level, char searched_char);

t_path_map			*init_path_map(t_level level);

// |----------------------------------------|
// |			A_STAR_ALGORITHM			|
// |----------------------------------------|

int					a_star(t_level level, int end_pos);

//========================================

// |----------------------------|
// |			SO_LONG			|
// |----------------------------|

//------------------------------------------

// |================================================|
// |					TEMPORARY					|
// |================================================|

void				ft_print_path_map(t_level level, int end_pos);
void				ft_print_lst_map(t_lst_map *lst_map);
void				ft_print_map(char **map, int x, int y);
void				ft_print_path_map_status(t_level level);
void				ft_print_collectibles_pos(t_vector_2 *c_pos, int c_count);

#endif
