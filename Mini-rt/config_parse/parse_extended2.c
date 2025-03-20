/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_extended2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 09:53:25 by stakhtou          #+#    #+#             */
/*   Updated: 2025/01/25 10:00:47 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"

char	**free_2d(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (NULL);
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}

void	parse_vector(double *vector, char **fields, int8_t *err)
{
	int	i;

	i = 0;
	while (fields[i])
		i++;
	if (i != 3)
	{
		*err = PARSE_ERROR;
		return (free_2d(fields), (void)0);
	}
	vector[X] = ft_atof(fields[X], err, -1.0, 1.0);
	vector[Y] = ft_atof(fields[Y], err, -1.0, 1.0);
	vector[Z] = ft_atof(fields[Z], err, -1.0, 1.0);
	free_2d(fields);
}

void	parse_color(u_int8_t *color, char **fields, int8_t *err)
{
	int	i;

	i = 0;
	while (fields[i])
		i++;
	if (i != 3)
	{
		*err = PARSE_ERROR;
		return (free_2d(fields), (void)0);
	}
	color[R] = ft_atoi(fields[R], err, 0, 255);
	color[G] = ft_atoi(fields[G], err, 0, 255);
	color[B] = ft_atoi(fields[B], err, 0, 255);
	free_2d(fields);
}

void	parse_position(double *position, char **fields, int8_t *err)
{
	int	i;

	i = 0;
	while (fields[i])
		i++;
	if (i != 3)
	{
		*err = PARSE_ERROR;
		return (free_2d(fields), (void)0);
	}
	position[X] = ft_atof(fields[X], err, -10000.0, 10000.0);
	position[Y] = ft_atof(fields[Y], err, -10000.0, 10000.0);
	position[Z] = ft_atof(fields[Z], err, -10000.0, 10000.0);
	free_2d(fields);
}

int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}
