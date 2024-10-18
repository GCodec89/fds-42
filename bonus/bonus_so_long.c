/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_so_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:36:10 by gonolive          #+#    #+#             */
/*   Updated: 2024/10/18 13:20:27 by gonolive         ###   ########.fr       */
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

void	print_move(t_game *game)
{
	//char	*font;
	char	*count;
	char	*c;

	//font = "-misc-fixed-bold-r-normal--18-120-100-100-c-90-iso8859-9";
	count = ft_itoa(game->move_count);
	c = ft_strjoin("Move count: ", count);
	mlx_put_image_to_window(game->mlx, game->window,
		game->img->block_ptr, 14, 5);
	//mlx_set_font(game->mlx, game->window, font);
	mlx_string_put(game->mlx, game->window, 20, 20, 0xFFFFFF, c);
	free(count);
	free(c);
}

int	random_move(t_game *game)
{
	time_t	r_curr_time;

	r_curr_time = time(NULL);
	if (r_curr_time - game->r_move_time >= RENEMY_INT)
	{
		move_renemy(game);
		game->r_move_time = r_curr_time;
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
	print_move(game);
	mlx_loop_hook(game->mlx, random_move, game);
	mlx_loop(game->mlx);
}
