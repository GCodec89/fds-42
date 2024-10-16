/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_right.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 22:52:34 by gonolive          #+#    #+#             */
/*   Updated: 2024/10/15 23:02:22 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	move_right(t_game *game)
{
	t_point	pos;
	char	**matrix;

	pos = game->map->position;
	matrix = game->map->matrix;
	if (matrix[pos.x][pos.y + 1] == 'C')
	{
		matrix[pos.x][pos.y + 1] = '0';
		game->map->count_c--;
	}
	put_title(game, "./img/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
	if (matrix[pos.x][pos.y] == 'E')
	{
		put_title(game, "./img/E.xpm", pos.y * PIXEL, pos.x * PIXEL);
	}
	if (game->player_state == 0)
	{
		put_title(game, "./img/p-dt1.xpm", (pos.y + 1) * PIXEL, pos.x * PIXEL);
		game->player_state = 1;
	}
	else
	{
		put_title(game, "./img/p-dt2.xpm", (pos.y + 1) * PIXEL, pos.x * PIXEL);
		game->player_state = 0;
	}
}

void	press_right(t_game *game)
{
	t_point	pos;
	char	**matrix;

	pos = game->map->position;
	matrix = game->map->matrix;
	if (matrix[pos.x][pos.y + 1] == '1')
		return ;
	else
		move_right(game);
	game->move_count += 1;
	game->map->position.y += 1;
	ft_printf("Move count: %d\n", game->move_count);
	if (matrix[pos.x][pos.y + 1] == 'E' && game->map->count_c == 0)
	{
		ft_printf(GAME_COMPLETE);
		close_window(game);
	}
}
