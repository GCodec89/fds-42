/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:48:51 by gonolive          #+#    #+#             */
/*   Updated: 2024/10/22 16:47:43 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_so_long.h"

int	map_closed(t_map *map)
{
	int		i;
	int		row;
	int		col;
	char	**mtx;

	mtx = map->matrix;
	col = map->col;
	row = map->row;
	i = 0;
	while (i < col)
	{
		if (mtx[0][i] != '1' || mtx[row - 1][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (i < row - 1)
	{
		if (mtx[i][0] != '1' || mtx[i][col - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	map_rectangle(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (map->matrix[row])
	{
		col = 0;
		while (map->matrix[row][col])
		{
			col++;
		}
		if (map->col != col)
		{
			return (0);
		}
		row++;
	}
	return (1);
}

int	check_path(t_map *tmp, int x, int y)
{
	if (x < 0 || y < 0 || x >= tmp->row || y >= tmp->col)
	{
		return (0);
	}
	if (tmp->matrix[x][y] == 'E')
	{
		tmp->count_e--;
	}
	if (tmp->count_c == 0 && tmp->count_e == 0)
	{
		return (1);
	}
	if (tmp->matrix[x][y] == '1')
	{
		return (0);
	}
	if (tmp->matrix[x][y] == 'C' && tmp->count_c > 0)
	{
		tmp->count_c--;
	}
	tmp->matrix[x][y] = '1';
	if (check_path(tmp, x - 1, y) || check_path(tmp, x + 1, y)
		|| check_path(tmp, x, y - 1) || check_path(tmp, x, y + 1))
		return (1);
	return (0);
}

int	path_valid(t_map *map)
{
	t_map	tmp;

	init_tmp(&tmp, map);
	if (!tmp.matrix)
	{
		return (ft_printf(ERROR_MALLOC), 0);
	}
	if (!check_path(&tmp, map->p_position.x, map->p_position.y))
	{
		free_map_matrix(tmp.matrix);
		return (0);
	}
	free_map_matrix(tmp.matrix);
	return (1);
}

int	valid_map(t_map *map)
{
	if (map->row < 3 || map->col < 3)
		return (ft_printf(ERROR_COL_ROW), 0);
	if (!map_rectangle(map))
		return (ft_printf(ERROR_RECTANGLE), 0);
	if (!map_closed(map))
		return (ft_printf(ERROR_WALLS), 0);
	if (map->count_p != 1)
		return (ft_printf(ERROR_PLAYER), 0);
	if (map->count_c < 1)
		return (ft_printf(ERROR_COIN), 0);
	if (map->count_e != 1)
		return (ft_printf(ERROR_EXIT), 0);
	if (count_stuff(map->matrix, 'R') == 0)
		return (ft_printf(ERROR_RENEMY), 0);
	if (!path_valid(map))
		return (ft_printf(ERROR_PATH), 0);
	return (1);
}
