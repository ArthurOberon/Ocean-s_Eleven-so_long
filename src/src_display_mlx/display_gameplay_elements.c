/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_gameplay_elements.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:34:28 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/26 15:53:12 by aoberon          ###   ########.fr       */
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

// Not use
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

static void	display_plus_one_collectible(t_game *game, t_gameplay *gameplay,
	t_player *player)
{
	static struct timeval	start_time = {0, 0};
	struct timeval			time;
	double					delay;
	t_vector_2				pos_display;

	if (gameplay->display_plus_one == false)
		return ;
	pos_display.x = player->player_pos.x - game->camera->camera_f_pos.x - (CHUNK_SIZE / 5);
	pos_display.y = player->player_pos.y - game->camera->camera_f_pos.y - (CHUNK_SIZE / 5);
	display_one_str(game, pos_display,
	 	"+1", game->window->map_sprites[game->level->nb_cases + e_alphabet]->sprite_img->size.x);
	if (!start_time.tv_sec)
		gettimeofday(&start_time, NULL);
	gettimeofday(&time, NULL);
	delay = (((double)(time.tv_usec - start_time.tv_usec) / CLOCKS_PER_SEC)
			+ time.tv_sec - start_time.tv_sec);
	if (delay >= 2)
	{
		start_time = (struct timeval){0, 0};
		gameplay->display_plus_one = false;
	}
}

void	display_available_character(t_game *game, t_window *window,
	t_gameplay *gameplay)
{
	int			i;
	t_vector_2	pos_tmp;
	t_sprite	*sprite;

	if ((gameplay->available_character[0] == 1
			|| gameplay->available_character[0] == 3)
		&& (gameplay->available_character[1] == 1
			|| gameplay->available_character[1] == 3)
		&& (gameplay->available_character[2] == 1
			|| gameplay->available_character[2] == 3)
		&& (gameplay->available_character[3] == 1
			|| gameplay->available_character[3] == 3))
		return ;
	i = 0;
	while (i < game->level->nb_cases)
	{
		sprite = NULL;
		if (game->level->map[i] == 'D')
			sprite = window->map_sprites[game->level->nb_cases
				+ e_main];
		else if (game->level->map[i] == 'R')
			sprite = window->map_sprites[game->level->nb_cases
				+ e_eater];
		else if (game->level->map[i] == 'L')
			sprite = window->map_sprites[game->level->nb_cases
				+ e_thief];
		else if (game->level->map[i] == 'B')
			sprite = window->map_sprites[game->level->nb_cases
				+ e_bomber];
		if (sprite != NULL)
		{
			pos_tmp = chunk_to_pixel_pos(i, game->level->map_vector.x);
			pos_tmp.x = pos_tmp.x - game->camera->camera_f_pos.x;
			pos_tmp.y = pos_tmp.y - game->camera->camera_f_pos.y;
			if (pos_tmp.x > game->camera->camera_f_size.x)
				pos_tmp.x = game->camera->camera_f_size.x - 1;
			if (pos_tmp.y > game->camera->camera_f_size.y)
				pos_tmp.y = game->camera->camera_f_size.y - 1;
			if ((pos_tmp.x + CHUNK_SIZE < window->img.size.x
					&& pos_tmp.y + CHUNK_SIZE < window->img.size.y)
				&& (pos_tmp.x > 0 && pos_tmp.y > 0))
			{
				put_image_to_image(&window->img, pos_tmp,
					&(sprite->sprite_img)[sprite->frame]);
			}
		}
		i++;
	}
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
	display_plus_one_collectible(game, gameplay, gameplay->player);
	display_available_character(game, window, gameplay);
}
