/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeza.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:52:16 by gonolive          #+#    #+#             */
/*   Updated: 2024/10/22 15:35:57 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
	{
		return ;
	}
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	free_map_struct(t_map *map)
{
	if (map)
	{
		if (map->matrix)
		{
			free_map_matrix(map->matrix);
		}
		free(map);
	}
	free(map);
}

void	free_structs(t_game *game)
{
	if (game)
	{
		if (game->map)
		{
			if (game->map->matrix)
				free_map_matrix(game->map->matrix);
			free(game->map);
		}
		if (game->img)
		{
			if (game->img->img_ptr)
				mlx_destroy_image(game->mlx, game->img->img_ptr);
			free(game->img);
		}
		if (game->window)
			mlx_destroy_window(game->mlx, game->window);
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		free(game);
	}
}
