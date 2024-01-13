/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:42:02 by aoberon           #+#    #+#             */
/*   Updated: 2022/11/17 19:38:26 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_check_args(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar_int(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr_int(va_arg(args, char *)));
	if (c == 'p')
		return (ft_print_address_int(va_arg(args, long unsigned int)));
	if (c == 'd')
		return (ft_putnbr_int(va_arg(args, int)));
	if (c == 'i')
		return (ft_putnbr_int(va_arg(args, int)));
	if (c == 'u')
		return (ft_print_hexa_int(va_arg(args, int)));
	if (c == 'x')
		return (ft_putnbr_base_int(va_arg(args, unsigned int),
				"0123456789abcdef"));
	if (c == 'X')
		return (ft_putnbr_base_int(va_arg(args, unsigned int),
				"0123456789ABCDEF"));
	if (c == '%')
		return (ft_putchar_int('%'));
	return (0);
}
