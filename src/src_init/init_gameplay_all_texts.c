/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gameplay_all_texts.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:41:24 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/07 22:10:33 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Initialize the first part of the texts struct.
 * 
 * @param texts texts struct to initialize.
 */
static void	init_all_texts_part_1(t_text *texts)
{
	texts[e_text_start_danny].text = "Let's get this code to open the safe !";
	texts[e_text_start_rusty].text = "Qu'est ce que j'aime ce genre d'endroit. \
Bon, je dois aller ouvrir ce coffre. Je vais me faire discret\
et trouver le code.";
	texts[e_text_start_linus].text = "Ok, c'est parti. Faut pas que je me foire. \
Je dois trouver le code du coffre c'est ca ? Je peux surement le voler sur \
un des guards.";
	texts[e_text_start_basher].text = "Alors, alors. Ou est ce que tu te caches \
petit code du coffre fort.";
	texts[e_text_remain_one_collectible_danny].text = "One more to go !";
	texts[e_text_remain_zero_collectible_danny].text = "Perfect ! Now let's go \
to the safe.";
	texts[e_text_remain_one_collectible_rusty].text = "One more to go !";
	texts[e_text_remain_zero_collectible_rusty].text = "Perfect ! Now let's go \
to the safe.";
	texts[e_text_remain_one_collectible_linus].text = "One more to go !";
	texts[e_text_remain_zero_collectible_linus].text = "Perfect ! Now let's go \
to the safe.";
	texts[e_text_remain_one_collectible_basher].text = "One more to go !";
	texts[e_text_remain_zero_collectible_basher].text = "Perfect ! Now let's go \
to the safe.";
}

/**
 * @brief Initialize the second part of the texts struct.
 * 
 * @param texts texts struct to initialize.
 */
static void	init_all_texts_part_2(t_text *texts)
{
	texts[e_text_rusty_to_danny_1].text = "Aller on enchaine.";
	texts[e_text_rusty_to_danny_2].text = "C'est parti.";
	texts[e_text_linus_to_danny_1].text = "C'est a toi ?";
	texts[e_text_linus_to_danny_2].text = "Oui. Reste derriere.";
	texts[e_text_basher_to_danny_1].text = "J'espere que ton plan \
va fonctionner.";
	texts[e_text_basher_to_danny_2].text = "Fais moi confiance.";
	texts[e_text_danny_to_rusty_1].text = "A ton tour.";
	texts[e_text_danny_to_rusty_2].text = "C'est parti !";
	texts[e_text_linus_to_rusty_1].text = "Tu manges encore ?";
	texts[e_text_linus_to_rusty_2].text = "C'est quoi le probleme ?";
	texts[e_text_basher_to_rusty_1].text = "C'etait drole !";
	texts[e_text_basher_to_rusty_2].text = "Et c'est pas fini.";
}

/**
 * @brief Initialize the third part of the texts struct.
 * 
 * @param texts texts struct to initialize.
 */
static void	init_all_texts_part_3(t_text *texts)
{
	texts[e_text_danny_to_linus_1].text = "Tu sais, a ce jeu la \
tu perds ta concentration pendant un seconde, et quelqu'un ce \
blesse.";
	texts[e_text_danny_to_linus_2].text = "Je sais, je sais.";
	texts[e_text_rusty_to_linus_1].text = "C'est a toi. Et oublie \
pas que, sous aucune consideration, quoique tu fasses, ne vas jamais \
essayer de... *dring dring*";
	texts[e_text_rusty_to_linus_2].text = "Ne jamais quoi ..?";
	texts[e_text_basher_to_linus_1].text = "Fait pas de la merde.";
	texts[e_text_basher_to_linus_2].text = "Oui, pas besoin de me le dire.";
}

/**
 * @brief Initialize the fourth part of the texts struct.
 * 
 * @param texts texts struct to initialize.
 */
static void	init_all_texts_part_4(t_text *texts)
{
	texts[e_text_danny_to_basher_1].text = "Basher, c'est le moment.";
	texts[e_text_danny_to_basher_2].text = "Oui, laisse moi faire.";
	texts[e_text_rusty_to_basher_1].text = "Tu vas reussir a faire tout \
exploser ?";
	texts[e_text_rusty_to_basher_2].text = "Bien sur, c'est presque deja fait.";
	texts[e_text_linus_to_basher_1].text = "Je peux faire quelque chose ?";
	texts[e_text_linus_to_basher_2].text = "Non. Ne touche a rien.";
}

/**
 * @brief Init all texts of the game.
 * 
 * @param game game struct, used to exit game if a malloc fail.
 * @param gameplay gameplay struct, used to get all_texts to initialize.
 */
void	init_all_texts_of_the_game(t_game *game, t_gameplay *gameplay)
{
	int		i;
	t_text	*texts;

	texts = ft_calloc(sizeof(t_text), e_total_text_number);
	if (!texts)
		exit_game(*game, "Error of malloc.\n");
	gameplay->all_texts = texts;
	texts[e_text_debug].text = "abcdefghijqlmnopqrstuvwxyz  \
!\"#$%&'()*+,-./0123456789:;<=?>";
	init_all_texts_part_1(texts);
	init_all_texts_part_2(texts);
	init_all_texts_part_3(texts);
	init_all_texts_part_4(texts);
	i = 0;
	while (i < e_total_text_number)
	{
		texts[i].has_been_display = false;
		i++;
	}
}
