/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_press_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:25:32 by gonolive          #+#    #+#             */
/*   Updated: 2024/10/22 15:55:53 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_so_long.h"

static void	player_up(t_game *game, t_point pos)
{
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

static void	move_up(t_game *game, t_point pos, char **matrix)
{
	if (matrix[pos.x - 1][pos.y] == 'C')
	{
		matrix[pos.x - 1][pos.y] = '0';
		game->map->count_c -= 1;
		put_title(game, "./img/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
		player_up(game, pos);
	}
	else if (matrix[pos.x][pos.y] == 'R')
	{
		put_title(game, "./img/r-f1.xpm", pos.y * PIXEL, pos.x * PIXEL);
		player_up(game, pos);
	}
	else
	{
		put_title(game, "./img/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
		player_up(game, pos);
	}
	game->move_count += 1;
	game->map->p_position.x -= 1;
}

void	press_up(t_game *game)
{
	t_point	pos;
	t_point	e_pos;
	char	**matrix;

	pos = game->map->p_position;
	e_pos = game->map->e_position;
	matrix = game->map->matrix;
	if (matrix[pos.x - 1][pos.y] == '1')
		return ;
	move_up(game, pos, matrix);
	if (gameover(matrix, pos.x - 1, pos.y, game->map->count_c))
		close_window(game);
	matrix[pos.x - 1][pos.y] = 'P';
	if (pos.x == e_pos.x && pos.y == e_pos.y)
	{
		matrix[pos.x][pos.y] = 'E';
		put_title(game, "./img/E.xpm", pos.y * PIXEL, pos.x * PIXEL);
	}
	else
	{
		matrix[pos.x][pos.y] = '0';
	}
	print_move(game);
}
