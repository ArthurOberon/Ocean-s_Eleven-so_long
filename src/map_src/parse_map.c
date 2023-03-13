/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:30:54 by aoberon           #+#    #+#             */
/*   Updated: 2023/03/13 15:10:49 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**list_to_map(t_lst_map *lst, int *x, int *y)
{
	t_lst_map	*lst_free_addr;
	char		**map;
	int			i;

	lst_free_addr = lst;
	*y = ft_lstsize(lst);
	*x = ft_strlen(lst->line) - 1;
	if (*x < 3 || *y < 3)
		return (NULL);
	if (!is_rectangle(lst, *x))
		return (NULL);
	map = malloc(sizeof(char *) * *y);
	if (!map)
		return (NULL);
	i = -1;
	while (++i < *y)
	{
		map[i] = line_to_tab(lst->line);
		if (!map[i])
			return (printf("PANIC ! Free tab 2D !\n"), NULL);
		lst = lst->next;
	}
	ft_lstclear(&lst_free_addr);
	return (map);
}

char	**read_map(int fd, int *x, int *y)
{
	char		*line;
	t_lst_map	*lst_map;
	t_lst_map	*tmp;

	lst_map = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
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

void	save_characters(t_map_flag *flag, char c)
{
	if (c == 'P')
		flag->bool_p += 1;
	else if (c == 'E')
		flag->bool_e += 1;
	else if (c == 'C')
		flag->bool_c += 1;
	else if (c != '0' && c != '1')
		flag->bool_error += 1;
}

int	has_all_characters(char **map, int x, int y)
{
	int			i;
	int			j;
	t_map_flag	flag;

	flag.bool_p = 0;
	flag.bool_e = 0;
	flag.bool_c = 0;
	flag.bool_error = 0;
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			save_characters(&flag, map[i][j]);
			j++;
		}
		i++;
	}
	if (flag.bool_p != 1 || flag.bool_e != 1
		|| flag.bool_c == 0 || flag.bool_error != 0)
		return (0);
	return (1);
}

int	parse_map(char *file_name)
{
	int		fd;
	int		x;
	int		y;
	char	**map;

	if (!is_ber(file_name))
		return (0);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	map = read_map(fd, &x, &y);
	if (!map)
		return (free_2d_char_tab(map, y), 0);
	ft_print_map(map, x, y);
	if (!is_closed(map, x, y))
		return (free_2d_char_tab(map, y), 0);
	if (!has_all_characters(map, x, y))
		return (free_2d_char_tab(map, y), 0);
	return (free_2d_char_tab(map, y), 1);
}
