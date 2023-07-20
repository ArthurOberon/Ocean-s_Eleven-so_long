/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:30:54 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/20 12:28:09 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Converts a list to a 2 dimensional array of chars.
 * 
 * @param lst list to convert.
 * @param x size of the map on x (width).
 * @param y size of the map on y (height).
 * @return char** converted map.
 */
char	**list_to_map(t_lst_map *lst, int *x, int *y)
{
	t_lst_map	*lst_free_addr;
	char		**map;
	int			i;

	if (!lst)
		return (NULL);
	lst_free_addr = lst;
	*y = ft_lstsize(lst);
	*x = ft_strlen(lst->line);
	if ((*x < 3 || *y < 3) || !is_rectangle(lst, *x))
		return (ft_lstclear(&lst_free_addr), NULL);
	map = ft_calloc(sizeof(char *), *y);
	if (!map)
		return (NULL);
	i = -1;
	while (++i < *y)
	{
		map[i] = line_to_tab(lst->line);
		if (!map[i])
			return (free_2d_char_tab(map, *y), NULL);
		lst = lst->next;
	}
	ft_lstclear(&lst_free_addr);
	return (map);
}

/**
 * @brief Reads (with get_next_line) the map from the file descriptor
 * fills a list with the lines and returns it as a 2d char array.
 * 
 * @param fd file descriptor to read from.
 * @param x size of the map on x (width).
 * @param y size of the map on y (height).
 * @return char** 2 dimensional array of chars representing the map.
 */
char	**read_map(int fd, int *x, int *y)
{
	char		*line;
	t_lst_map	*lst_map;
	t_lst_map	*tmp;
	size_t		line_size;

	lst_map = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_size = ft_strlen(line);
		if (line[line_size - 1] == '\n')
			line[line_size - 1] = 0;
		tmp = ft_lstnew(line);
		if (!tmp)
		{
			ft_lstclear(&lst_map);
			close(fd);
			return (NULL);
		}
		ft_lstadd_back(&lst_map, tmp);
		line = get_next_line(fd);
	}
	close(fd);
	return (list_to_map(lst_map, x, y));
}

/**
 * @brief Parses the map and checks for errors.
 * 
 * @param file_name name of the map file to parse.
 * @param map map to be filled in a 2 dimensional array of char.
 * @param map_vector size of the map on x and y in a vector.
 * @return int 1 if the map is valid, 0 otherwise.
 */
int	parse_map(char *file_name, char **map, t_vector_2 *map_vector)
{
	int		fd;
	int		x;
	int		y;
	char	**map_2d;

	if (!is_ber(file_name))
		return (exit_map_error(NULL, 0));
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (exit_map_error(NULL, 0));
	map_2d = read_map(fd, &x, &y);
	if (!map_2d)
		return (exit_map_error(map_2d, y));
	if (!is_closed(map_2d, x, y))
		return (exit_map_error(map_2d, y));
	if (!has_all_characters(map_2d, x, y))
		return (exit_map_error(map_2d, y));
	*map = char_2d_to_1d(map_2d, x, y);
	if (!map)
		return (exit_map_error(map_2d, y));
	*map_vector = (t_vector_2){x, y};
	free_2d_char_tab(map_2d, y);
	return (1);
}
