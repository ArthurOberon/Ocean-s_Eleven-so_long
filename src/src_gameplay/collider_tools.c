/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collider_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:31:49 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/01 19:32:05 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	get_tile(int x, int y, char *map, int x_max)
{
	return (map[x + (y * x_max)]);
}

double	double_modulo(double x, double y)
{
	return (x - ((int)(x / y) *x));
}
