/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:17:43 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/27 20:51:46 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game(t_game game)
{
	int	i;
	int	j;

	free(game.level.map);
	free(game.level.path_map);
	free(game.chunks_pos);
	i = 0;
	while (i < game.level.nb_cases + 1)
	{
		j = 0;
		while (j < game.window.map_sprites[i].size)
		{
			mlx_destroy_image(game.window.mlx_ptr,
				game.window.map_sprites[i].sprite_img[j].mlx_img);
			j++;
		}
		free(game.window.map_sprites[i].sprite_img);
		i++;
	}
	free(game.window.map_sprites);
	mlx_destroy_display(game.window.mlx_ptr);
	free(game.window.mlx_ptr);
}
