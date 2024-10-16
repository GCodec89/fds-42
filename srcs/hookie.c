/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookie.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:18:17 by gonolive          #+#    #+#             */
/*   Updated: 2024/10/15 23:03:23 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(t_game *game)
{
	free_structs(game);
	exit(0);
}

int	input_key(int keysym, t_game *game)
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
