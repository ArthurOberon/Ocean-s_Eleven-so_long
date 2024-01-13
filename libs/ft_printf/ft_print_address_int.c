/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:47:12 by aoberon           #+#    #+#             */
/*   Updated: 2022/11/17 19:38:34 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_print_address_int(long unsigned int ptr)
{
	int					return_int;

	if (!ptr)
		return (ft_putstr("(nil)"), ft_strlen("(nil)"));
	return_int = ft_putstr_int("0x");
	return_int += ft_putnbr_base_int(ptr, "0123456789abcdef");
	return (return_int);
}
