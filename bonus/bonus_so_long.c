/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_so_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:36:10 by gonolive          #+#    #+#             */
/*   Updated: 2024/10/16 20:36:04 by gonolive         ###   ########.fr       */
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
	t_map	*map;
	t_game	*game;

	check_args(argc, argv);
	map = init_map(argv[1]);
	if (!map)
		return (EXIT_FAILURE);
	game = init_game(map);
	if (!game)
		return (ft_printf(ERROR_GAME_INIT), EXIT_FAILURE);
	srand(time(NULL));
	render(game);
	mlx_loop(game->mlx);
}
