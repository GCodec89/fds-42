/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_so_long.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:33:04 by gonolive          #+#    #+#             */
/*   Updated: 2024/10/17 20:33:01 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_SO_LONG_H
# define BONUS_SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <time.h>

# if defined(__APPLE__) && defined(__MACH__)
#  include "mlx/mlx.h"
#  include <Carbon/Carbon.h>

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
# define GAME_COMPLETE "Congratulations! You completed the game!\n"

# if defined(__APPLE__) && defined(__MACH__)
#  define LEFT_KEY				123	
#  define RIGHT_KEY				124	
#  define UP_KEY				126
#  define DOWN_KEY				125	
#  define A_KEY					0
#  define S_KEY					1
#  define D_KEY					2
#  define W_KEY					13
#  define ESC 					53

# else
#  define LEFT_KEY				65361
#  define RIGHT_KEY				65363
#  define UP_KEY				65362
#  define DOWN_KEY				65364
#  define A_KEY					97
#  define W_KEY					119
#  define S_KEY					115
#  define D_KEY					100
#  define ESC					65307
# endif

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
	void	*block_ptr;
}	t_img;


typedef	struct s_map
{
	char	**matrix;
	int		row;
	int		col;
	t_point	p_position;
	t_point	e_position;
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
	int		player_state;
	time_t	r_move_time;
	time_t	c_move_time;
}	t_game;

int	error(char *msg);

void	free_map_matrix(char **matrix);
void	free_map_struct(t_map *map);
void	free_structs(t_game *game);

char	**get_matrix(int fd);
int	count_rows(char **matrix);
t_point	char_position(char **matrix, char c);
int	count_stuff(char **matrix, char c);

t_map	*init_map(char *filename);
void	init_tmp(t_map *tmp, t_map *map);
t_game	*init_game(t_map *map);
t_img	*init_img(t_game *game);
void	*init_count_block(t_game *game);

void	render(t_game *game);
void	put_title(t_game *game, char *path, int x, int y);

int	check_args(int argc, char *argv[]);
void	print_move(t_game *game);

int	valid_map(t_map *map);
int	map_rectangle(t_map *map);
int	map_closed(t_map *map);
int	path_valid(t_map *map);
int	check_path(t_map *tmp, int x, int y);

#endif