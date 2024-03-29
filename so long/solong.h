/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:44:45 by stakhtou          #+#    #+#             */
/*   Updated: 2024/03/29 04:58:41 by stakhtou         ###   ########.fr       */
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
	char			*exit_pos;
	char			*collectible_pos;
	char			*start_pos;
	char			*zero_pos;
	char			*one_pos;
	int				exit_count;
}					t_map_info;
typedef struct s_c
{
	int				x;
	int				y;
}					t_c;
typedef struct s_flood_fill
{
	t_map_info		map_info;
	char			**map;
	const char		*arg;
	int				rows;
	int				cols;
	int				x;
	int				y;
	int				i;
	int				j;
}					t_flood_fill;

typedef struct s_validation_info
{
	int				line_num;
	int				fd;
	char			*line;
	int				length;
	int				first_len;
}					t_validation_info;

typedef struct s_data
{
	char			*convert;
	int				val;
	int				our_r;
	int				close;
}					t_data;
typedef struct t_mini
{
	void			*img_player;
	void			*door;
	void			*wall;
	void			*black;
	void			*coins;
	void			*init_ptr;
	int				*coins_num;
}					t_mini;
typedef struct s_draw_params
{
	void			*win;
	void			*mlx;
	void			*wall_img;
	void			*coin_img;
	void			*exit_img;
	void			*black_img;
	void			*ball_img;
	int				tile_size;
	int				window_width;
	int				window_height;
	int				draw_x;
	int				draw_y;
	t_mini			*d;
}					t_draw_params;

typedef struct s_fillP
{
	t_draw_params	*dp;
	t_flood_fill	*f;
}					t_fp;
char				*file_to_str(int fd);
int					first_line(const char *filename);
int					rect_check(const char *filename);
int					validate_map(const char *map);
int					last_line(const char *filename);
int					check_close(const char *filename);
void				copy_lines(char **array2d, const char *start, int rows,
						int cols);
char				**convert2d(char *str, int *rows, int *cols);
char				**convert_map(t_flood_fill *fill);
void				flood_fill(t_flood_fill fill);
int					eat_check(t_flood_fill fill);
void				find_player_coordinates(t_flood_fill *fill);
int					check_go(t_flood_fill *fill);
void				est_con(void **mlx);
void				init_map(t_mini *d);
void				draw_tile(t_flood_fill *fill, t_draw_params *params, int x,
						int y);
void				draw_tiles(t_flood_fill *fill, t_draw_params *params);
void				setup_and_run(const char *filename, t_flood_fill *fill);
void				move_player_right(t_flood_fill *fill,
						t_draw_params *params);
void				move_player_left(t_flood_fill *fill, t_draw_params *params);
void				move_player_up(t_flood_fill *fill, t_draw_params *params);
void				move_player_down(t_flood_fill *fill, t_draw_params *params);
int					eat_exit(t_flood_fill *fill);
int					destroy(int keycode, t_fp *params);
int					ends_with_ber(const char *filename);
int					if_eat(t_flood_fill *fill, t_fp *params);
int					ft_strcmp(const char *s1, const char *s2);
int					close_win(t_fp *params);
int					move_player(int keycode, t_fp *params);
void				check_and_increment_move(t_flood_fill *f);
int					check_size(t_flood_fill *fill);
#endif
