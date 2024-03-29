/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 23:16:36 by stakhtou          #+#    #+#             */
/*   Updated: 2024/03/29 04:27:29 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	first_line(const char *filename)
{
	char	*line;
	int		i;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
		{
			free(line);
			close(fd);
			return (0);
		}
		i++;
	}
	free(line);
	close(fd);
	return (1);
}

int	last_line(const char *filename)
{
	char	*line;
	char	*last_one;
	int		fd;

	last_one = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (last_one != NULL)
			free(last_one);
		last_one = line;
		line = get_next_line(fd);
	}
	if (last_one == NULL)
		return (0);
	else
	{
		free(last_one);
		return (1);
	}
}

int	lf_char(const char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[0] != '1' || line[strlen(line) - 2] != '1')
		{
			free(line);
			close(fd);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	check_close(const char *filename)
{
	int	first;
	int	last;
	int	lf;

	first = first_line(filename);
	last = last_line(filename);
	lf = lf_char(filename);
	if (first == 0 || last == 0 || lf == 0)
		return (0);
	else
		return (1);
}

void	check_and_increment_move(t_flood_fill *f)
{
	static int	move = 0;

	if ((f->map[f->y - 1][f->x] != 'E') && (f->map[f->y + 1][f->x] != 'E')
		&& (f->map[f->y][f->x - 1] != 'E') && (f->map[f->y][f->x + 1] != 'E')
		&& (f->map[f->y - 1][f->x - 1] != 'E') && (f->map[f->y - 1][f->x
			+ 1] != 'E') && (f->map[f->y + 1][f->x - 1] != 'E') && (f->map[f->y
			+ 1][f->x + 1] != 'E'))
	{
		move++;
		ft_printf("Move : %d \n", move);
	}
}
