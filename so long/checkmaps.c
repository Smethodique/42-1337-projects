/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmaps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:46:32 by stakhtou          #+#    #+#             */
/*   Updated: 2024/03/24 09:34:36 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	*file_to_str(int fd)
{
	char	*line;
	char	*ptr;
	size_t	total_len;
	size_t	len;
	char	*tmp;

	ptr = NULL;
	total_len = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		len = strlen(line);
		tmp = ptr;
		ptr = malloc(total_len + len + 1);
		if (tmp)
			memcpy(ptr, tmp, total_len);
		free(tmp);
		memcpy(ptr + total_len, line, len);
		total_len += len;
		ptr[total_len] = '\0';
		free(line);
		line = get_next_line(fd);
	}
	return (ptr);
}

int	validate_map(const char *map)
{
	t_map_info	info;
	const char	*ptr = map;

	info.exit_pos = ft_strchr(map, 'E');
	info.collectible_pos = ft_strchr(map, 'C');
	info.start_pos = ft_strchr(map, 'P');
	info.zero_pos = ft_strchr(map, '0');
	info.one_pos = ft_strchr(map, '1');
	info.exit_count = 0;
	if (!ptr)
		return (0);
	while (*ptr != '\0')
	{
		if (*ptr == 'E' || *ptr == 'P')
			info.exit_count++;
		ptr++;
		if (*ptr != '0' && *ptr != '1' && *ptr != 'P' && *ptr != 'E'
			&& *ptr != 'C' && *ptr != '\0' && *ptr != '\n')
			return (0);
	}
	if (info.exit_pos == NULL || info.collectible_pos == NULL
		|| info.start_pos == NULL || info.one_pos == NULL
		|| info.exit_count > 2)
		return (0);
	return (1);
}

int	rect_check(const char *filename)
{
	int		fd;
	char	*line;
	int		length;
	int		line_num;
	int		first_len;

	line_num = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		length = 0;
		while (line[length] != '\0' && line[length] != '\n')
			length++;
		if (line_num == 0)
			first_len = length;
		else if (length != first_len)
			return (0);
		free(line);
		line = get_next_line(fd);
		line_num++;
	}
	return (1);
}

void	all_func(const char *filename)
{
	t_data			data;
	t_flood_fill	fill;
	int				i;

	i = 0;
	fill.arg = filename;
	data.our_r = rect_check(filename);
	data.close = check_close(filename);
	fill.map = convert_map(&fill);
	if (data.our_r == 0 || data.close == 0 || check_go(&fill) == 0
		|| eat_check(fill) == 0)
	{
		while (i < fill.rows)
			free(fill.map[i++]);
		free(fill.map);
		ft_printf("Error\n");
		return ;
	}
	while (i < fill.rows)
		free(fill.map[i++]);
	free(fill.map);
	setup_and_run(filename,  &fill);
	while (i < fill.rows)
		free(fill.map[i++]);
	free(fill.map);
}

int	main(int ac, char **av)
{
	int		fd;
	t_data	data;
	int		val;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (1);
		data.convert = file_to_str(fd);
		val = validate_map(data.convert);
		if (val == 0)
		{
			printf("Error\n");
			return (0);
		}
		all_func(av[1]);
		return (0);
	}
	else if (ac != 2)
		return (0);
}
