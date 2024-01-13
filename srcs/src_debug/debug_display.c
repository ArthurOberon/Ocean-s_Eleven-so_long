/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:09:46 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/20 13:16:13 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	debug_fps(t_game *game)
{
	char	string_fps[10];

	if (game->gameplay->fps < 0)
		return ;
	ft_itoa(game->gameplay->fps, string_fps);
	mlx_string_put(game->window->mlx_ptr, game->window->win_ptr, 10, 22, RED,
		string_fps);
}
