/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:29:24 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/10 15:59:48 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_type(char a, va_list args)
{
	if (a == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (a == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (a == 'p')
		return (ft_putptr(va_arg(args, uintptr_t), "0123456789abcdef"));
	else if (a == 'd' || a == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (a == 'u')
		return (ft_put_unsigned(va_arg(args, unsigned int)));
	else if (a == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (a == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (a == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;

	va_start(args, str);
	i = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			i += check_type(*str, args);
			str++;
		}
		else
		{
			ft_putchar(*str);
			str++;
			i++;
		}
	}
	va_end(args);
	return (i);
}
