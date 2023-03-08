/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:55:43 by aoberon           #+#    #+#             */
/*   Updated: 2023/03/08 15:56:13 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_ber(char *file_name)
{
	size_t	size;

	size = ft_strlen(file_name);
	if (size <= 3)
		return (0);
	return (is_equals(file_name + size - 4, ".ber"));
}

int	is_rectangle(t_lst_map *lst, int size)
{
	while (lst)
	{
		if ((int)ft_strlen(lst->line) != size)
			return (0);
		lst = lst->next;
	}
	return (1);
}
