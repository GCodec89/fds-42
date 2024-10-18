/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_move_renemy_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:05:28 by gonolive          #+#    #+#             */
/*   Updated: 2024/10/18 14:42:24 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_so_long.h"

int	renemy_left(t_game *game, t_point pos)
{
	char	**matrix;

	matrix = game->map->matrix;
	if (matrix[pos.x][pos.y - 1] != '0')
		return (0);
	if (matrix[pos.x][pos.y - 1] == 'P')
		return (ft_printf(GAME_LOST), 1);
	put_title(game, "./img/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
	if (game->renemy_state == 0)
	{
		put_title(game, "./img/r-e1.xpm", (pos.y - 1) * PIXEL, pos.x * PIXEL);
		game->renemy_state = 1;
	}
	else
	{
		put_title(game, "./img/r-e2.xpm", (pos.y - 1) * PIXEL, pos.x * PIXEL);
		game->renemy_state = 0;
	}
	matrix[pos.x][pos.y] = '0';
	matrix[pos.x][pos.y - 1] = 'R';
	return (0);
}

int	renemy_right(t_game *game, t_point pos)
{
	char	**matrix;

	matrix = game->map->matrix;
	if (matrix[pos.x][pos.y + 1] != '0')
	{
		return (0);
	}
	if (matrix[pos.x][pos.y + 1] == 'P')
	{
		return (ft_printf(GAME_LOST), 1);
	}
	put_title(game, "./img/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
	if (game->renemy_state == 0)
	{
		put_title(game, "./img/r-d1.xpm", (pos.y + 1) * PIXEL, pos.x * PIXEL);
		game->renemy_state = 1;
	}
	else
	{
		put_title(game, "./img/r-d2.xpm", (pos.y + 1) * PIXEL, pos.x * PIXEL);
		game->renemy_state = 0;
	}
	matrix[pos.x][pos.y] = '0';
	matrix[pos.x][pos.y + 1] = 'R';
	return (0);
}

int	renemy_down(t_game *game, t_point pos)
{
	char	**matrix;

	matrix = game->map->matrix;
	if (matrix[pos.x + 1][pos.y] != '0')
	{
		return (0);
	}
	if (matrix[pos.x + 1][pos.y] == 'P')
	{
		return (ft_printf(GAME_LOST), 1);
	}
	put_title(game, "./img/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
	if (game->renemy_state == 0)
	{
		put_title(game, "./img/r-f1.xpm", pos.y * PIXEL, (pos.x + 1) * PIXEL);
		game->renemy_state = 1;
	}
	else
	{
		put_title(game, "./img/r-f2.xpm", pos.y * PIXEL, (pos.x + 1) * PIXEL);
		game->renemy_state = 0;
	}
	matrix[pos.x][pos.y] = '0';
	matrix[pos.x + 1][pos.y] = 'R';
	return (0);
}

int	renemy_up(t_game *game, t_point pos)
{
	char	**matrix;

	matrix = game->map->matrix;
	if (matrix[pos.x - 1][pos.y] != '0')
	{
		return (0);
	}
	if (matrix[pos.x - 1][pos.y] == 'P')
	{
		return (ft_printf(GAME_LOST), 1);
	}
	put_title(game, "./img/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
	if (game->renemy_state == 0)
	{
		put_title(game, "./img/r-t1.xpm", pos.y * PIXEL, (pos.x - 1) * PIXEL);
		game->renemy_state = 1;
	}
	else
	{
		put_title(game, "./img/r-t2.xpm", pos.y * PIXEL, (pos.x - 1) * PIXEL);
		game->renemy_state = 0;
	}
	matrix[pos.x][pos.y] = '0';
	matrix[pos.x - 1][pos.y] = 'R';
	return (0);
}
