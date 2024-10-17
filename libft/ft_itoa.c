/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:19:39 by gonolive          #+#    #+#             */
/*   Updated: 2024/10/17 20:29:28 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		++len;
	}
	while (n != 0)
	{
		n = n / 10;
		++len;
	}
	return (len);
}

static void	ft_res(int n, int len, int i, char *result)
{
	while (len > i)
	{
		result[len - 1] = n % 10 + '0';
		n = n / 10;
		--len;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	int		i;

	if (n == -2147483647)
	{
		result = ft_strdup("-2147483647");
		return (result);
	}
	len = intlen(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
	{
		return (NULL);
	}
	i = 0;
	if (n < 0)
	{
		result[0] = '-';
		i = 1;
		n = n * -1;
	}
	ft_res(n, len, i, result);
	result[len] = '\0';
	return (result);
}
