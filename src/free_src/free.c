/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:17:43 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/25 19:36:10 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_data(t_data data)
{
	int	i;
	int	j;

	free(data.game.level.map);
	free(data.game.level.path_map);
	free(data.game.chunks_pos);
	free(data.mlx_ptr);
	i = 0;
	while (i < data.game.level.nb_cases + 1)
	{
		j = 0;
		while (j < data.map_sprites[i].size)
		{
			free(data.map_sprites[i].sprite_img[j].mlx_img);
			// free(data.map_sprites[i].sprite_img[j].addr);
			j++;
		}
		// free(data.map_sprites);
		i++;
	}
}
