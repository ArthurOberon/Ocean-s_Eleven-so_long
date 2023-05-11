/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temporary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:52:59 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/11 16:13:38 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*\*/

#include "so_long.h"

void	ft_print_map(char **map, int x, int y)
{
	int	i;
	int	j;

	if (map == NULL)
		return ;
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			printf("%c ", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	ft_print_lst_map(t_lst_map *lst_map)
{
	while (lst_map != NULL)
	{
		printf("%s", lst_map->line);
		lst_map = lst_map->next;
	}
}

void	ft_print_path_map(t_level *level, int end_pos)
{
	int	i;

	i = 0;
	while (i < level->nb_cases)
	{
		if (i == end_pos && level->map[i] == 'E')
			printf("E!");
		else if (i == end_pos && level->map[i] == 'C')
			printf("C!");
		else if (level->path_map[i].has_been_check == 1 && level->map[i] == 'C')
			printf("CK");
		else if (level->path_map[i].has_been_check == 1 && level->map[i] == 'E')
			printf("EK");
		else if (level->map[i] == 'P')
			printf("P_");
		else if (level->map[i] == 'E')
			printf("E_");
		else if (level->map[i] == 'C')
			printf("C_");
		else if (level->path_map[i].f == -1)
			printf("##");
		else if (level->path_map[i].has_been_check == 1)
			printf("OK");
		else if (level->path_map[i].f != 0)
			printf("??");
		else
			printf("__");
		printf(" ");
		i++;
		if (i % level->map_vector.x == 0)
			printf("\n");
	}
	printf("\n");
}

void	ft_print_path_map_status(t_level *level)
{
	int	i;

	i = 0;
	while (i < level->nb_cases)
	{
		if (level->path_map[i].has_been_check == 0
			&& level->path_map[i].dst_to_start == 0)
			printf("Box [%d] is empty\n", i);
		else
		{
			printf("\n");
			printf("Box number : [%d]\n", i);
			printf("	has been check : [%d]\n",
				level->path_map[i].has_been_check);
			printf("	dst_to_start :[%d]\n", level->path_map[i].dst_to_start);
			printf("	dst_to_end : [%d]\n", level->path_map[i].dst_to_end);
			printf("	f : [%d]\n", level->path_map[i].f);
			printf("	parent : [%d]\n", level->path_map[i].parent);
			printf("\n");
		}
		i++;
	}
}

void	ft_print_collectibles_pos(t_vector_2 *c_pos, int c_count)
{
	int	i;

	i = 0;
	while (i < c_count)
	{
		printf("collectibles %d : x : [%d]  y : [%d]\n", i + 1,
			c_pos[i].x, c_pos[i].y);
		i++;
	}
}

void	ft_print_chunk_pos(t_vector_2 *chunk_pos, int c_count)
{
	int	i;

	i = 0;
	while (i < c_count)
	{
		printf("chunk %d : x : [%d]  y : [%d]\n", i + 1,
			chunk_pos[i].x, chunk_pos[i].y);
		i++;
	}
	printf("\n");
}

void	ft_print_1d_to_2d(t_level *level)
{
	int	i;
	int	j;

	j = 0;
	while (j < level->map_vector.y * level->map_vector.x)
	{
		i = 0;
		while (i < level->map_vector.x)
		{
			printf("%c ", level->map[i + j]);
			i++;
		}
		j += level->map_vector.x;
		printf("\n");
	}
	printf("\n");
}

void	debug_chunk_pos(t_game *game)
{
	ft_print_chunk_pos(game->gameplay->chunks_pos, game->level->nb_cases);
	ft_print_1d_to_2d(game->level);
}

void	debug_stat_tiles(t_stat_tiles stat)
{
	printf("Number of :\nexit :[%d]\nwall :[%d]\n", stat.exit, stat.wall);
	printf("ground : [%d] \nplayer : [%d]\n", stat.ground, stat.player);
	printf("collectibles : [%d]\n", stat.player);
	printf("TOTAL : [%d]\n", stat.exit + stat.wall + stat.ground + stat.player
		+ stat.collect);
}

void	debug_player_box_collider(t_player *player)
{
	printf("player pos : x : %f y : %f\n", player->player_f_pos.x,
		player->player_f_pos.y);
	printf("collider player : \n");
	printf("N_O : x : %f y : %f\n", player->player_f_pos.x,
			player->player_f_pos.y);
	printf("N_E : x : %f y : %f\n", (player->player_f_pos.x + CHUNK_SIZE),
		player->player_f_pos.y);
	printf("S_O : x : %f y : %f\n", player->player_f_pos.x,
		(player->player_f_pos.y + CHUNK_SIZE));
	printf("S_E : x : %f y : %f\n\n", (player->player_f_pos.x + CHUNK_SIZE),
		(player->player_f_pos.y + CHUNK_SIZE));
}

void	debug_fps(t_game *game)
{
	char	*string_fps;

	if (game->gameplay->fps < 0)
		return ;
	string_fps = ft_itoa(game->gameplay->fps);
	if (!string_fps)
		free_game(*game, "Error of malloc.\n");
	mlx_string_put(game->window->mlx_ptr, game->window->win_ptr, 10, 22, RED,
		string_fps);
	free(string_fps);
}
/**/
