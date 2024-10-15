/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:43:02 by gonolive          #+#    #+#             */
/*   Updated: 2024/05/06 15:05:31 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int nbr)
{
	int	result;

	result = 0;
	if (nbr == -2147483648)
	{
		result += write (1, "-2147483648", 11);
		return (result);
	}
	if (nbr < 0)
	{
		result += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr < 10)
	{
		result += ft_putchar(nbr + 48);
	}
	else
	{
		result += ft_printnbr(nbr / 10);
		result += ft_printnbr(nbr % 10);
	}
	return (result);
}
