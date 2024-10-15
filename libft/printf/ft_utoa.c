/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:09:47 by gonolive          #+#    #+#             */
/*   Updated: 2024/05/06 16:43:08 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_usize(unsigned int nbr)
{
	unsigned int	count;

	count = 0;
	if (nbr == 0)
		count++;
	while (nbr)
	{
		count ++;
		nbr = nbr / 10;
	}
	return (count);
}

int	ft_pstr(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (!str)
	{
		result += write(1, "(null)", 6);
		return (result);
	}
	while (str[i])
	{
		result += write(1, &str[i], 1);
		i++;
	}
	return (result);
}

int	ft_utoa(unsigned int nbr)
{
	char	*str;
	int		size;
	int		result;

	size = ft_usize(nbr);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
	{
		return (0);
	}
	str[size] = '\0';
	if (nbr == 0)
	{
		str[0] = '0';
	}
	while (nbr)
	{
		size --;
		str[size] = (nbr % 10) + 48;
		nbr = nbr / 10;
	}
	result = ft_pstr(str);
	free(str);
	return (result);
}
