/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gameplay_guard_helper.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:43:48 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/19 20:44:18 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	random_look_direction(t_guard *guard)
{
	int	random;

	// not commented
	guard->guard_look_dir.x = 0;
	guard->guard_look_dir.y = 0;
	random = rand() % 4;
	if (random == 0)
		guard->guard_look_dir.x = -1;
	else if (random == 1)
		guard->guard_look_dir.y = 1;
	else if (random == 2)
		guard->guard_look_dir.x = 1;
	else if (random == 3)
		guard->guard_look_dir.y = -1;
}
