/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:32:34 by aoberon           #+#    #+#             */
/*   Updated: 2022/11/17 19:38:43 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putnbr_base_int(unsigned long nbr, char *base)
{
	int					return_int;
	unsigned long long	nbr_converted;
	size_t				base_length;

	return_int = 0;
	nbr_converted = nbr;
	base_length = ft_strlen(base);
	if (nbr_converted >= base_length)
		return_int += ft_putnbr_base_int(nbr_converted / base_length, base);
	return_int += ft_putchar_int(base[nbr_converted % base_length]);
	return (return_int);
}
