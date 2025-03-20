/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:00:55 by stakhtou          #+#    #+#             */
/*   Updated: 2025/01/26 22:46:18 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "get_next_line.h"
# include "minirt.h"
# include <stdbool.h>
# include <stdint.h>

struct	s_config_data;

char	*get_next_line(int fd);
char	**ft_split(char const *s, const char *delim);
char	**free_2d(char **arr);
bool	validate_fields(char **fields, int8_t *err, int n);
int		conf_parse(char *file, struct s_config_data *data);
int		ft_atoi(const char *str, int8_t *err, int min, int max);
double	ft_atof(char *str, int8_t *err, double min, double max);
int		end_with(char *str, char *with);
void	parse_vector(double *vector, char **fields, int8_t *err);
void	parse_color(u_int8_t *color, char **fields, int8_t *err);
void	parse_position(double *position, char **fields, int8_t *err);
int		camera(char **fields, struct s_config_data *data);
int		sphere(char **fields, struct s_config_data *data);
int		plane(char **fields, struct s_config_data *data);
int		light(char **fields, struct s_config_data *data);
int		ambiante_light(char **fields, struct s_config_data *data);
int		is_space(char c);
int		check_sign(const char *str, int *i);
char	**free_arr(char **arr, int n);
#endif
