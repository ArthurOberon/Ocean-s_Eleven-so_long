/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_gameplay_elements.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:34:28 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/16 18:37:00 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// Not use
void	display_hp(t_window *window, t_player *player, int color)
{
	if (player->hp == 2)
		mlx_string_put(window->mlx_ptr, window->win_ptr, WINDOW_WIDTH - 40, 44,
			color, "HP : 2");
	if (player->hp == 1)
		mlx_string_put(window->mlx_ptr, window->win_ptr, WINDOW_WIDTH - 40, 44,
			color, "HP : 1");
	if (player->hp == 0)
		mlx_string_put(window->mlx_ptr, window->win_ptr, WINDOW_WIDTH - 40, 44,
			color, "HP : 0");
}

void	display_nb_move(t_game *game)
{
	char	*string_nb;

	string_nb = ft_itoa(game->gameplay->nb_move);
	if (!string_nb)
		free_game(*game, "Error of malloc.\n");
	mlx_string_put(game->window->mlx_ptr, game->window->win_ptr, 10, 44, BLUE,
		string_nb);
	free(string_nb);
}

void	display_gameplay_elements(t_game *game, t_gameplay *gameplay,
	t_window *window)
{
	if (gameplay->nb_collect_remain == 0)
		window->map_sprites[game->level->exit_pos] = game->assets->collect;
	display_guards(game, gameplay, window, gameplay->guards);
	display_bomb(gameplay->player, &gameplay->player->bomb, game, window);
	display_qte(game, &gameplay->player->qte, gameplay->player,
		gameplay->guards);
}
