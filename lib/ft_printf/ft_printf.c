/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:32:01 by aoberon           #+#    #+#             */
/*   Updated: 2022/11/18 11:11:47 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, string);
	while (string[i])
	{
		if (string[i] == '%')
			count += ft_check_args(args, string[++i]);
		else
		{
			write(1, &string[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
