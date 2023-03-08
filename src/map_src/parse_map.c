/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:30:54 by aoberon           #+#    #+#             */
/*   Updated: 2023/03/08 18:31:45 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*line_to_tab(char *line)
{
	int		i;
	int		size;
	char	*tab;

	size = ft_strlen(line);
	tab = malloc(sizeof(char) * size);
	i = -1;
	while (++i < size - 1)
	{
		tab[i] = line[i];
	}
	tab[i] = 0;
	return (tab);
}

char	**list_to_map(t_lst_map *lst, int *x, int *y)
{
	char	**map;
	int		i;

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
			return (NULL);
		}
		ft_lstadd_back(&lst_map, tmp);
		line = get_next_line(fd);
	}
	close(fd);
	return (list_to_map(lst_map, x, y));
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
	ft_print_map(map);
	if (!is_closed(map, x, y))
		return (0);
	return (1);
}
