/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:32:51 by aoberon           #+#    #+#             */
/*   Updated: 2022/11/18 11:29:34 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include"libft/libft.h"
# include <stdarg.h>

int	ft_putnbr_int(int n);
int	ft_putchar_int(char c);
int	ft_putstr_int(char	*s);
int	ft_print_hexa_int(int nbr);
int	ft_printf(const char *string, ...) __attribute__((format(printf, 1, 2)));
int	ft_check_args(va_list args, char c);
int	ft_print_address_int(long unsigned int ptr);
int	ft_putnbr_base_int(unsigned long nbr, char *base);

#endif
