/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:17:43 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/26 15:39:37 by aoberon          ###   ########.fr       */
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
	i = 0;
	while (i < data.game.level.nb_cases + 1)
	{
		j = 0;
		while (j < data.map_sprites[i].size)
		{
			mlx_destroy_image(data.mlx_ptr,
				data.map_sprites[i].sprite_img[j].mlx_img);
			j++;
		}
		free(data.map_sprites[i].sprite_img);
		i++;
	}
	free(data.map_sprites);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
