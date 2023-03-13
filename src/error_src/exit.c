/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:13:50 by aoberon           #+#    #+#             */
/*   Updated: 2023/03/13 15:17:39 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_arg_error(void)
{
	ft_putstr("Not the good number of arguments.\n");
	ft_putstr("Please use so_long with this format :\n");
	ft_putstr("./so_long 'mapfile.ber'\n");
	exit(EXIT_FAILURE);
}

void	exit_map_error(void)
{
	ft_putstr("Error\n");
	ft_putstr("Not a valid map.\n");
	ft_putstr("Please use a map : with .ber extenstion, rectangular, ");
	ft_putstr("close by 1, and line_to_tab");
	ft_putstr("with only one P and E, and at least 1 C\n");
	ft_putstr("for example :\n");
	ft_putstr("1111\n1P01\n10E1\n1111\n");
	exit(EXIT_FAILURE);
}
