/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_collectible_helper.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:49:18 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/19 20:50:24 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_all_collectible_has_been_collected(t_collectible *collectible,
	int size)
{
	int	i;

	// not commented
	i = 0;
	while (i < size)
	{
		if (collectible[i].state == COLLECTABLE)
			return (false);
		i++;
	}
	return (true);
}
