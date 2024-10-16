/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 22:53:01 by gonolive          #+#    #+#             */
/*   Updated: 2024/10/16 10:28:19 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	move_up(t_game *game)
{
	t_point	pos;
	char	**matrix;

	pos = game->map->position;
	matrix = game->map->matrix;
	if (matrix[pos.x - 1][pos.y] == 'C')
	{
		matrix[pos.x - 1][pos.y] = '0';
		game->map->count_c--;
	}
	put_title(game, "./img/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
	if (matrix[pos.x][pos.y] == 'E')
	{
		put_title(game, "./img/E.xpm", pos.y * PIXEL, pos.x * PIXEL);
	}
	if (game->player_state == 0)
	{
		put_title(game, "./img/p-tr1.xpm", pos.y * PIXEL, (pos.x - 1) * PIXEL);
		game->player_state = 1;
	}
	else
	{
		put_title(game, "./img/p-tr2.xpm", pos.y * PIXEL, (pos.x - 1) * PIXEL);
		game->player_state = 0;
	}
}

void	press_up(t_game *game)
{
	t_point	pos;
	char	**matrix;

	pos = game->map->position;
	matrix = game->map->matrix;
	if (matrix[pos.x - 1][pos.y] == '1')
		return ;
	move_up(game);
	game->move_count += 1;
	game->map->position.x -= 1;
	ft_printf("Move count: %d\n", game->move_count);
	if (matrix[pos.x - 1][pos.y] == 'E' && game->map->count_c == 0)
	{
		ft_printf(GAME_COMPLETE);
		close_window(game);
	}
}
