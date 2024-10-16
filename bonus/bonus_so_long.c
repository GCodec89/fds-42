/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_so_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:36:10 by gonolive          #+#    #+#             */
/*   Updated: 2024/10/16 10:39:10 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_so_long.h"

int	check_args(int argc, char *argv[])
{
	if (argc < 2)
	{
		error("Provide map name and extension as argument\n\
Ex: ./so_long maps/map.ber");
	}
	if (argc > 2)
	{
		error("Too many arguments. Provide only map name and extension\n\
Ex: ./so_long maps/map.ber");
	}
	if (ft_strstr(argv[1], ".ber") == NULL)
	{
		error("Invalid map extension. Use .ber");
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	if (!check_args(argc, argv))
		return (EXIT_FAILURE);
}
