/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmaps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:46:32 by stakhtou          #+#    #+#             */
/*   Updated: 2024/05/10 07:14:03 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	*file_to_str(int fd)
{
	char	*line;
	char	*ptr;
	char	*tmp;

	ptr = NULL;
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_strjoin2(ptr, line);
		if (ptr)
			free(ptr);
		ptr = tmp;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
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
		if (((*ptr != '0' && *ptr != '1' && *ptr != 'P' && *ptr != 'E'
					&& *ptr != 'C' && *ptr != '\0' && *ptr != '\n')
				|| (*ptr == '\n' && *(ptr + 1) == '\n'))
			|| info.exit_pos == NULL || info.collectible_pos == NULL
			|| info.start_pos == NULL || info.one_pos == NULL
			|| info.exit_count > 2)
			return (0);
	}
	return (1);
}

int	rect_check(const char *filename)
{
	t_validation_info	info;

	info.line_num = 0;
	info.fd = open(filename, O_RDONLY);
	info.line = get_next_line(info.fd);
	while (info.line != NULL)
	{
		info.length = 0;
		while (info.line[info.length] != '\0' && info.line[info.length] != '\n')
			info.length++;
		if (info.line_num == 0)
			info.first_len = info.length;
		else if (info.length != info.first_len)
		{
			free(info.line);
			close(info.fd);
			return (0);
		}
		free(info.line);
		info.line = get_next_line(info.fd);
		info.line_num++;
	}
	free(info.line);
	close(info.fd);
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
		|| eat_check(fill) == 0 || ends_with_ber(filename) == 0
		|| check_size(&fill) == 0)
	{
		while (i < fill.rows)
			free(fill.map[i++]);
		free(fill.map);
		ft_printf("Error\nmap is not valid");
		return ;
	}
	setup_and_run(filename, &fill);
	i = 0;
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
		if (fd < 0)
			return (ft_printf("Error\ninvalid file"));
		data.convert = file_to_str(fd);
		val = validate_map(data.convert);
		if (val == 0)
		{
			ft_printf("Error\nmap is not valid");
			return (free(data.convert), 0);
		}
		free(data.convert);
		all_func(av[1]);
		return (0);
	}
	else if (ac != 2)
		return (0);
}
