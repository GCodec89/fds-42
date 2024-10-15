/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:04:56 by gonolive          #+#    #+#             */
/*   Updated: 2024/05/03 14:20:15 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(void *nbr)
{
	int				result;
	unsigned long	n;

	n = (unsigned long)nbr;
	result = 0;
	if (!n)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	result += ft_printstr("0x");
	if (n == 0)
	{
		result += ft_putchar(0);
	}
	else
	{
		result += ft_putptrhex(n, 'x');
	}
	return (result);
}
