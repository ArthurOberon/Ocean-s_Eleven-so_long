/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_features_dialogue_main.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:51:32 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/16 19:07:21 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Display dialogue, list of texts box.
 * 
 * @param game game struct, used to get the window struct.
 * @param dialogue list of text_box to display,
 * all node regrouped together create the dialogue.
 */
void	display_dialogue(t_game *game, t_texts_box_list *dialogue)
{
	if (dialogue == NULL)
		return ;
	display_one_node_texts_box(game, game->window, *dialogue->text_box);
}
