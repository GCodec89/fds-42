/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_hookie.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:00:13 by gonolive          #+#    #+#             */
/*   Updated: 2024/10/18 19:44:28 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_so_long.h"

int	close_window(t_game *game)
{
	free_structs(game);
	exit (0);
}

int	key_input(int keysym, t_game *game)
{
	if (keysym == ESC)
		close_window(game);
	if (keysym == A_KEY || keysym == LEFT_KEY)
		press_left(game);
	if (keysym == D_KEY || keysym == RIGHT_KEY)
		press_right(game);
	if (keysym == W_KEY || keysym == UP_KEY)
		press_up(game);
	if (keysym == S_KEY || keysym == DOWN_KEY)
		press_down(game);
	return (0);
}

int	gameover(char **matrix, int x, int y, int c_count)
{
	if (matrix[x][y] == 'R')
	{
		ft_printf(GAME_LOST);
		return (1);
	}
	if (matrix[x][y] == 'E' && c_count == 0)
	{
		ft_printf(GAME_COMPLETE);
		return (1);
	}
	return (0);
}
