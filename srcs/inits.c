/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:14:05 by gonolive          #+#    #+#             */
/*   Updated: 2024/10/10 17:22:15 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_map	*init_map(char *filename)
{
	t_map	*map;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_printf(ERROR_READ), NULL);
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (ft_printf(ERROR_MALLOC), NULL);
	map->matrix = get_matrix(fd);
	close(fd);
	if (!map->matrix)
		return (free(map), NULL);
	map->row = count_rows(map->matrix);
	map->col = ft_strlen(map->matrix[0]);
	map->position = player_position(map->matrix);
	map->count_p = count_stuff(map->matrix, 'P');
	map->count_c = count_stuff(map->matrix, 'C');
	map->count_e = count_stuff(map->matrix, 'E');
	if (!valid_map(map))
	{
		free_map_matrix(map->matrix);
		return (free(map), NULL);
	}
	return (map);
}

void	init_tmp(t_map *tmp, t_map *map)
{
	int	i;

	i = 0;
	tmp->matrix = malloc(sizeof(char *) * (map->row + 1));
	if (!tmp->matrix)
		return ;
	while (i < map->row)
	{
		tmp->matrix[i] = ft_strdup(map->matrix[i]);
		if (!tmp->matrix[i])
		{
			while (i > 0)
				free(tmp->matrix[--i]);
			free(tmp->matrix);
			return ;
		}
		i++;
	}
	tmp->matrix[i] = NULL;
	tmp->row = map->row;
	tmp->col = map->col;
	tmp->position = map->position;
	tmp->count_p = map->count_p;
	tmp->count_c = map->count_c;
	tmp->count_e = map->count_e;
}

t_img	*init_img(t_game *game)
{
	game->img->img_ptr = mlx_new_image(game->mlx,
			(game->map->col * PIXEL), (game->map->row * PIXEL));
	if (!game->img->img_ptr)
		return (NULL);
	game->img->bpp = 0;
	game->img->line_len = 0;
	game->img->endian = 0;
	game->img->addr = mlx_get_data_addr(game->img->img_ptr, &game->img->bpp,
			&game->img->line_len, &game->img->endian);
	if (!game->img->addr)
		return (NULL);
	game->img->title_pos.x = 0;
	game->img->title_pos.y = 0;
	return (game->img);
}

t_game	*init_game(t_map *map)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (free_map_struct(map), NULL);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (free_structs(game), NULL);
	game->window = mlx_new_window(game->mlx, (map->col * PIXEL),
			(map->row * PIXEL), "so_long");
	if (!game->window)
		return (free_structs(game), NULL);
	game->map = map;
	game->img = (t_img *)malloc(sizeof(t_img));
	if (!game->img)
		return (NULL);
	game->img = init_img(game);
	if (!game->img)
		return (free_structs(game), NULL);
	game->move_count = 0;
	return (game);
}
