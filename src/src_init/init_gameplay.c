/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gameplay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:18:56 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/06 11:45:27 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_chunk_positions(t_game *game, t_vector_2 **chunk_pos,
	t_vector_2 size, int nb)
{
	int	i;
	int	j;
	int	x;
	int	y;

	(*chunk_pos) = ft_calloc(sizeof(t_vector_2), nb);
	if (!*chunk_pos)
		exit_game(*game, "Error of malloc.\n");
	i = 0;
	y = 0;
	while (i < size.y)
	{
		j = 0;
		x = 0;
		while (j < size.x)
		{
			(*chunk_pos)[(i * size.x) + j] = (t_vector_2){x, y};
			j++;
			x += CHUNK_SIZE;
		}
		i++;
		y += CHUNK_SIZE;
	}
}

void	init_text_box(t_game *game, t_window *window, t_gameplay *gameplay,
	t_text_box *text_box)
{
	t_sprite	*background;
	t_sprite	*sprite_face;

	background = window->map_sprites[game->level->nb_cases + e_background_text];
	sprite_face = game->window->map_sprites[game->level->nb_cases
		+ game->gameplay->player->player_character];
	text_box->is_display = false;
	text_box->read_all = false;
	text_box->pos_display_background = (t_vector_2){20,
		WINDOW_HEIGHT - 50 - background->sprite_img->size.y};
	text_box->margin_size.x = 20;
	text_box->margin_size.y = 30;
	text_box->pos_display_face.x = text_box->pos_display_background.x + text_box->margin_size.x;
	text_box->pos_display_face.y = text_box->pos_display_background.y + text_box->margin_size.y;
	text_box->pos_display_text = text_box->pos_display_face;
	text_box->pos_display_text.x += sprite_face->sprite_img->size.x;
	text_box->size_one_alphabet = window->map_sprites[game->level->nb_cases
		+ e_alphabet]->sprite_img->size.x;
	text_box->characters_max.x = (background->sprite_img->size.x
			- text_box->pos_display_text.x) / text_box->size_one_alphabet;
	text_box->characters_max.y = (background->sprite_img->size.y
			- (text_box->margin_size.y * 2))
		/ (text_box->size_one_alphabet + 10);
	text_box->characters_max_one_box = text_box->characters_max.x
		* text_box->characters_max.y;
	text_box->page_number = 0;
	text_box->page_in = 0;
	text_box->talking_character = gameplay->player->player_character;
	text_box->text = NULL;
	text_box->text_pages = NULL;
}

static void	init_texts(t_game *game, t_gameplay *gameplay)
{
	int		i;
	t_text	*texts;

	texts = ft_calloc(sizeof(t_text), e_total_text_number);
	if (!texts)
		exit_game(*game, "Error of malloc.\n");
	gameplay->all_texts = texts;
	// debug
	texts[e_text_debug].text = "abcdefghijqlmnopqrstuvwxyz  !\"#$%&'()*+,-./0123456789:;<=?>";
	// debug

	texts[e_text_start_danny].text = "Let's get this code to open the safe !";
	texts[e_text_start_rusty].text = "Qu'est ce que j'aime ce genre d'endroit. Bon, je dois aller ouvrir ce coffre. Je vais me faire discret et trouver le code.";
	texts[e_text_start_linus].text = "Ok, c'est parti. Faut pas que je me foire. Je dois trouver le code du coffre c'est ca ? Je peux surement le voler sur un des guards.";
	texts[e_text_start_basher].text = "Alors, alors. Ou est ce que tu te caches petit code du coffre fort.";


	texts[e_text_remain_one_collectible_danny].text = "One more to go !";
	texts[e_text_remain_zero_collectible_danny].text = "Perfect ! Now let's go to the safe.";
	
	texts[e_text_remain_one_collectible_rusty].text = "One more to go !";
	texts[e_text_remain_zero_collectible_rusty].text = "Perfect ! Now let's go to the safe.";
	
	texts[e_text_remain_one_collectible_linus].text = "One more to go !";
	texts[e_text_remain_zero_collectible_linus].text = "Perfect ! Now let's go to the safe.";


	texts[e_text_remain_one_collectible_basher].text = "One more to go !";
	texts[e_text_remain_zero_collectible_basher].text = "Perfect ! Now let's go to the safe.";


	texts[e_text_rusty_to_danny_1].text = "Aller on enchaine.";
	texts[e_text_rusty_to_danny_2].text = "C'est parti.";
	texts[e_text_linus_to_danny_1].text = "C'est a toi ?";
	texts[e_text_linus_to_danny_2].text = "Oui. Reste derriere.";
	texts[e_text_basher_to_danny_1].text = "J'espere que ton plan va fonctionner.";
	texts[e_text_basher_to_danny_2].text = "Fais moi confiance.";

	texts[e_text_danny_to_rusty_1].text = "A ton tour.";
	texts[e_text_danny_to_rusty_2].text = "C'est parti !";
	texts[e_text_linus_to_rusty_1].text = "Tu manges encore ?";
	texts[e_text_linus_to_rusty_2].text = "C'est quoi le probleme ?";
	texts[e_text_basher_to_rusty_1].text = "C'etait drole !";
	texts[e_text_basher_to_rusty_2].text = "Et c'est pas fini.";

	texts[e_text_danny_to_linus_1].text = "Tu sais, a ce jeu la tu perds ta concentration pendant un seconde, et quelqu'un ce blesse.";
	texts[e_text_danny_to_linus_2].text = "Je sais, je sais.";
	texts[e_text_rusty_to_linus_1].text = "C'est a toi. Et oublie pas que, sous aucune consideration, quoique tu fasses, ne vas jamais essayer de... *dring dring*";
	texts[e_text_rusty_to_linus_2].text = "Ne jamais quoi ..?";
	texts[e_text_basher_to_linus_1].text = "Fait pas de la merde.";
	texts[e_text_basher_to_linus_2].text = "Oui, pas besoin de me le dire.";

	texts[e_text_danny_to_basher_1].text = "Basher, c'est le moment.";
	texts[e_text_danny_to_basher_2].text = "Oui, laisse moi faire.";
	texts[e_text_rusty_to_basher_1].text = "Tu vas reussir a faire tout exploser ?";
	texts[e_text_rusty_to_basher_2].text = "Bien sur, c'est presque deja fait.";
	texts[e_text_linus_to_basher_1].text = "Je peux faire quelque chose ?";
	texts[e_text_linus_to_basher_2].text = "Non. Ne touche a rien.";
	i = 0;
	while (i < e_total_text_number)
	{
		texts[i].has_been_display = false;
		i++;
	}
}

void	init_gameplay(t_game *game, int *available_character,
			int chosen_character)
{
	t_gameplay	*gameplay;

	gameplay = ft_calloc(sizeof(t_gameplay), 1);
	if (!gameplay)
		exit_game(*game, "Error of malloc\n");
	game->gameplay = gameplay;
	gameplay->is_pause = false;
	gameplay->is_stop = false;
	gameplay->is_display_plus_one = false;
	gameplay->available_character[0] = available_character[0];
	gameplay->available_character[1] = available_character[1];
	gameplay->available_character[2] = available_character[2];
	gameplay->available_character[3] = available_character[3];
	gameplay->chosen_character = chosen_character;
	gameplay->fps = 0;
	gameplay->delta_time = 0;
	gameplay->nb_collect_get = 0;
	gameplay->nb_collect_remain = game->level->nb_collect;
	gameplay->nb_move = 0;
	get_chunk_positions(game, &gameplay->chunks_pos, game->level->map_vector,
		game->level->nb_cases);
	gameplay->map_start_state = ft_strdup(game->level->map);
	init_player(game, gameplay->player, chosen_character);
	init_guards(game, gameplay->guards);
	gameplay->dialogue = NULL;
	init_texts(game, gameplay);
	if (IS_DEBUG)
		debug_chunk_pos(game);
}
