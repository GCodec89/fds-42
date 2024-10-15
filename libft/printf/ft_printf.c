/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:36:22 by gonolive          #+#    #+#             */
/*   Updated: 2024/08/02 11:56:51 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_arg(const char *format, int i, va_list ap)
{
	if (format[i + 1] == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (format[i + 1] == 's')
		return (ft_printstr(va_arg(ap, char *)));
	else if (format[i + 1] == 'p')
		return (ft_printptr(va_arg(ap, void *)));
	else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		return (ft_printnbr(va_arg(ap, int)));
	else if (format[i + 1] == 'u')
		return (ft_utoa(va_arg(ap, unsigned int)));
	else if (format[i + 1] == 'x')
		return (ft_putptrhex(va_arg(ap, unsigned int), 'x'));
	else if (format[i + 1] == 'X')
		return (ft_putptrhex(va_arg(ap, unsigned int), 'X'));
	else if (format[i + 1] == '%')
		return (ft_putchar(format[i + 1]));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		result;

	i = 0;
	result = 0;
	if (!format || *format == '\0')
		return (0);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			result += ft_arg(format, i, ap);
			i++;
		}
		else
		{
			result += ft_putchar(format[i]);
		}
		i++;
	}
	va_end(ap);
	return (result);
}
