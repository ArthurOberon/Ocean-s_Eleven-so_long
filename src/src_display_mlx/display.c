/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:18:02 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/29 23:42:43 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	calculate_fps(int *fps, double *delta_time)
{
	static double	last_time = 0;
	double			now;

	if (last_time == 0)
		last_time = clock();
	now = clock();
	*delta_time = (now - last_time) / CLOCKS_PER_SEC;
	while (*delta_time < 0.008)
	{
		now = clock();
		*delta_time = (now - last_time) / CLOCKS_PER_SEC;
	}
	*fps = (int)(1.0 / *delta_time);
	last_time = now;
}

void	bzero_dir_press(t_dir_press *dir)
{
	dir->up = 0;
	dir->down = 0;
	dir->left = 0;
	dir->right = 0;
}

static void	check_move_player(t_game *game)
{
	if (game->gameplay->dir_player.up)
		game->gameplay->player_pos.y -= 300 * game->gameplay->delta_time;
	if (game->gameplay->dir_player.down)
		game->gameplay->player_pos.y += 300 * game->gameplay->delta_time;
	if (game->gameplay->dir_player.left)
		game->gameplay->player_pos.x -= 300 * game->gameplay->delta_time;
	if (game->gameplay->dir_player.right)
		game->gameplay->player_pos.x += 300 * game->gameplay->delta_time;
	bzero_dir_press(&game->gameplay->dir_player);
}

static int	on_update(t_game *game)
{
	if (!game->window->win_ptr)
		return (0);
	background(&game->window->img, 0xE0E0E0);
	check_move_player(game);
	display_sprites(game);
	if (IS_DEBUG)
	{
		display_debug(&game->window->img, GREEN, game->gameplay->chunks_pos,
			game->level->nb_cases);
		display_player_box_collider(&game->window->img,
			game->gameplay->player_pos, 0x800080);
	}
	mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr,
		game->window->img.mlx_img, 0, 0);
	calculate_fps(&game->gameplay->fps, &game->gameplay->delta_time);
	if (IS_DEBUG)
		mlx_string_put(game->window->mlx_ptr, game->window->win_ptr,
			12, 22, RED, ft_itoa(game->gameplay->fps));
	return (0);
}

void	display(t_game *game)
{
	mlx_hook(game->window->win_ptr, DestroyNotify, KeyPressMask, close_window,
		&game->window);
	mlx_hook(game->window->win_ptr, KeyPress, KeyPressMask, &handle_keypress,
		game);
	mlx_loop_hook(game->window->mlx_ptr, &on_update, game);
	mlx_loop(game->window->mlx_ptr);
	mlx_destroy_image(game->window->mlx_ptr, game->window->img.mlx_img);
}
