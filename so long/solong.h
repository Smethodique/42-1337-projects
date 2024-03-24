/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:44:45 by stakhtou          #+#    #+#             */
/*   Updated: 2024/03/24 10:13:56 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "1337Libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_map_info
{
	char		*exit_pos;
	char		*collectible_pos;
	char		*start_pos;
	char		*zero_pos;
	char		*one_pos;
	int			exit_count;
}				t_map_info;

typedef struct s_flood_fill
{
	t_map_info	map_info;
	char		**map;
	const char	*arg;
	int			rows;
	int			cols;
	int			x;
	int			y;
	int			i;
	int			j;
}				t_flood_fill;

typedef struct s_data
{
	char		*convert;
	int			val;
	int			our_r;
	int			close;
}				t_data;
typedef struct t_mini
{
	void		*img_player;
	void		*door;
	void		*wall;
	void		*black;
	void		*coins;
	void		*init_ptr;
	int			*coins_num;
}				t_mini;
typedef struct s_draw_params
{
	void		*mlx;
	void		**win;
	void		*wall_img;
	void		*coin_img;
	void		*exit_img;
	void		*black_img;
	void		*ball_img;
	int			tile_size;
	int			window_width;
	int			window_height;
	int			draw_x;
	int			draw_y;
	t_mini 		*d;
}				t_draw_params;

char			*file_to_str(int fd);
int				first_line(const char *filename);
int				rect_check(const char *filename);
int				validate_map(const char *map);
int				last_line(const char *filename);
int				check_close(const char *filename);
void			copy_lines(char **array2d, const char *start, int rows,
					int cols);
char			**convert2d(char *str, int *rows, int *cols);
char			**convert_map(t_flood_fill *fill);
void			flood_fill(t_flood_fill fill);
int				eat_check(t_flood_fill fill);
void			find_player_coordinates(t_flood_fill *fill);
int				check_go(t_flood_fill *fill);
void			est_con(void **mlx);
void			init_map(t_mini *d);
void			draw_tile(t_flood_fill *fill, t_draw_params *params, int x,
					int y);
void			draw_tiles(t_flood_fill *fill, t_draw_params *params);
void			draw_map(t_flood_fill *fill, t_draw_params *params);
void			setup_and_run(const char *filename, t_flood_fill *fill);

#endif
