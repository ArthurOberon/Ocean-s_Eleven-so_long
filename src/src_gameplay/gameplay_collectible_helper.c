/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_collectible_helper.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:49:18 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/20 09:54:46 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Check that all collectibles have been collected.
 * 
 * @param collectible collectible array.
 * @param size size of the collectible array.
 * @return bool, true when all collectibles have been collected, false otherwise.
 */
bool	check_all_collectibles_have_been_collected(t_collectible *collectible,
	int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (collectible[i].state == COLLECTABLE)
			return (false);
		i++;
	}
	return (true);
}
