/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:21:23 by gonolive          #+#    #+#             */
/*   Updated: 2024/04/30 13:29:01 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c);
static int	n_len(const char *s, char c);
static char	*fill_word(const char *s, int a);
static char	**free_array(const char **s, int a);

char	**ft_split(char const *str, char c)
{
	int		i;
	int		word;
	int		len;
	char	**array;

	i = 0;
	word = count_words(str, c);
	array = (char **)malloc((sizeof(char *) * (word + 1)));
	if (!array)
		return (0);
	while (word--)
	{
		while (*str && *str == c)
			str++;
		len = n_len(str, c);
		array[i] = fill_word((const char *)str, len);
		if (!array[i])
			return (free_array((const char **)array, i));
		i++;
		while (*str && *str != c)
			str++;
	}
	array[i] = 0;
	return (array);
}

static int	count_words(const char *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c)
			word++;
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
	}
	return (word);
}

static int	n_len(const char *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

static char	*fill_word(const char *s, int a)
{
	int		i;
	char	*to_array;

	i = 0;
	to_array = (char *)malloc(sizeof(char) * (a + 1));
	if (!to_array)
		return (0);
	while (a)
	{
		to_array[i] = s[i];
		i++;
		a--;
	}
	to_array[i] = 0;
	return (to_array);
}

static char	**free_array(const char **s, int a)
{
	while (a > 0)
	{
		a--;
		free((void *)s[a]);
	}
	free(s);
	return (NULL);
}
