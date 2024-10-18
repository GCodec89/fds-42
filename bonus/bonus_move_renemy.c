/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_move_renemy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:54:03 by gonolive          #+#    #+#             */
/*   Updated: 2024/10/18 13:50:49 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_so_long.h"

static int	validate_move_renemy(t_game *game, t_point *renemy, int count)
{
	int	i;
	int	dir;
	int	game_over;

	i = 0;
	game_over = 0;
	while (i < count)
	{
		dir = rand() % 4;
		if (dir == 0)
			game_over = renemy_left(game, renemy[i]);
		else if (dir == 1)
			game_over = renemy_right(game, renemy[i]);
		else if (dir == 2)
			game_over = renemy_up(game, renemy[i]);
		else if (dir == 3)
			game_over = renemy_down(game, renemy[i]);
		if (game_over)
			return (0);
		i++;
	}
	return (1);
}

void	move_renemy(t_game *game)
{
	t_point	*renemy;
	int		count;

	renemy = find_renemy(game->map->matrix, &count, 'R');
	if (!renemy)
	{
		return ;
	}
	if (!validate_move_renemy(game, renemy, count))
	{
		free(renemy);
		close_window(game);
	}
	free(renemy);
}
