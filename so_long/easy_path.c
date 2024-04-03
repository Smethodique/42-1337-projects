/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:44:45 by stakhtou          #+#    #+#             */
/*   Updated: 2024/04/03 08:05:32 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	copy_lines(char **array2d, const char *start, int rows, int cols)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		array2d[i] = malloc((cols + 1) * sizeof(char));
		ft_strncpy(array2d[i], (char *)start, cols);
		array2d[i][cols] = '\0';
		start += cols + 1;
		i++;
	}
}

char	**convert2d(char *str, int *rows, int *cols)
{
	const char	*ptr = str;
	char		**array2d;
	const char	*start = str;

	*rows = 0;
	*cols = 0;
	while (*ptr != '\0')
	{
		if (*ptr++ == '\n')
		{
			(*rows)++;
			if (*cols == 0)
				*cols = ptr - str - 1;
		}
	}
	if (*cols == 0)
		*cols = ptr - str;
	(*rows)++;
	array2d = malloc(*rows * sizeof(char *));
	copy_lines(array2d, start, *rows, *cols);
	return (array2d);
}

char	**convert_map(t_flood_fill *fill)
{
	int		fd;
	char	*minc;
	char	**convert;

	fd = open(fill->arg, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error opening file");
		exit(1);
	}
	minc = file_to_str(fd);
	close(fd);
	convert = convert2d(minc, &(fill->rows), &(fill->cols));
	free(minc);
	return (convert);
}

void	flood_fill(t_flood_fill *fill)
{
	if (fill->x < 0 || fill->x >= fill->cols || fill->y < 0
		|| fill->y >= fill->rows || fill->map[fill->y][fill->x] == '1'
		|| fill->map[fill->y][fill->x] == '-'
		|| fill->map[fill->y][fill->x] == 'E')
		return ;
	fill->map[fill->y][fill->x] = '-';
	fill->x--;
	flood_fill(fill);
	fill->x += 2;
	flood_fill(fill);
	fill->x--;
	fill->y++;
	flood_fill(fill);
	fill->y -= 2;
	flood_fill(fill);
	fill->y++;
}

int	is_all_ones(const char *str)
{
	while (*str != '\0')
	{
		if (*str != '1')
		{
			return (0);
		}
		str++;
	}
	return (1);
}
