/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:03:15 by aoberon           #+#    #+#             */
/*   Updated: 2022/11/17 14:35:38 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_print_hexa_int(int nbr)
{
	unsigned int	hexa_nbr;
	int				return_int;
	char			*result;

	if (nbr < 0)
		hexa_nbr = (SIZE_MAX * 2) + 2 + nbr;
	else
		hexa_nbr = nbr;
	result = ft_itoa(hexa_nbr);
	return_int = ft_putstr_int(result);
	free(result);
	return (return_int);
}
