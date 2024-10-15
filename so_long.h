/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:22:57 by gonolive          #+#    #+#             */
/*   Updated: 2024/10/15 10:18:21 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

#include <Carbon/Carbon.h>

# if defined(__APPLE__) && defined(__MACH__)
#  include "mlx/mlx.h"
# else
#  include "mlx_linux/mlx.h"

# endif

# include "libft/libft.h"

# define ERROR_READ "Error: unsuccessfull file read\n"
# define ERROR_MALLOC "Error: memory allocation failed\n"
# define ERROR_EMPTY_LINE "Error: map has an empty line\n"
# define ERROR_CHARS "Error: map has invalid characters.\n"
# define ERROR_MALLOC "Error: memory allocation failed\n"
# define ERROR_COL_ROW "Error: map has less than 3 rows and/or 3 columns\n"
# define ERROR_RECTANGLE "Error: map must be a rectangle\n"
# define ERROR_WALLS "Error: map must be surrounded by walls\n"
# define ERROR_PLAYER "Error: you must have one player\n"
# define ERROR_COIN "Error: you need at least one collectable\n"
# define ERROR_EXIT "Error: you must have one exit\n"
# define ERROR_PATH "Error: map does not have a valid path\n"
# define ERROR_GAME_INIT "Error: game initialization failed\n"
# define ERROR_IMG_LOAD "Error: could not load image %s\n"

# define PIXEL 64

typedef	struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_img
{
	void	*img_ptr;
	int		bpp;
	int		line_len;
	int		endian;
	char	*addr;
	t_point	title_pos;
}	t_img;


typedef	struct s_map
{
	char	**matrix;
	int		row;
	int		col;
	t_point	position;
	int		count_p;
	int		count_c;
	int		count_e;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	t_map	*map;
	t_img	*img;
	void	*window;
	int		move_count;
}	t_game;


typedef struct s_var
{

}	t_var;

int	error(char *msg);

void	free_map_matrix(char **matrix);
void	free_map_struct(t_map *map);
void	free_structs(t_game *game);

char	**get_matrix(int fd);
int		count_rows(char **matrix);
t_point	player_position(char **matrix);
int	count_stuff(char **matrix, char c);

t_map	*init_map(char *filename);
void	init_tmp(t_map *tmp, t_map *map);
t_img	*init_img(t_game *game);
t_game	*init_game(t_map *map);

void	put_title(t_game *game, char *path, int x, int y);
void	render(t_game *game);

int	check_args(int argc, char *argv[]);

int	valid_map(t_map *map);
int	map_rectangle(t_map *map);
int	map_closed(t_map *map);
int	path_valid(t_map *map);

#endif