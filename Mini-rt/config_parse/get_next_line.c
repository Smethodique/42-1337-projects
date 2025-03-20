/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baarif <baarif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:39:31 by baarif            #+#    #+#             */
/*   Updated: 2025/01/25 10:00:34 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t limit)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < limit)
		limit = ft_strlen(s) - start;
	str = (char *)malloc(limit - start + 1);
	if (!str)
		return (NULL);
	while (start < limit && s[start])
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

char	*handle_end(char **slice, char **buffer)
{
	char	*tmp;

	tmp = ft_strdup(*slice);
	free(*buffer);
	free(*slice);
	*slice = NULL;
	return (tmp);
}

char	*handle_new_line(char **slice, char **buffer)
{
	char	*another_tmp;
	char	*tmp;

	tmp = ft_substr(*slice, 0, has(*slice, '\n') + 1);
	another_tmp = ft_strdup(*slice);
	free(*slice);
	if (ft_strchr(another_tmp, '\n'))
		*slice = ft_strdup(ft_strchr(another_tmp, '\n') + 1);
	else
		*slice = ft_strdup(ft_strchr(another_tmp, '\0') + 1);
	free(another_tmp);
	free(*buffer);
	*buffer = NULL;
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*slice[1024];
	char		*buffer;
	int			bytes_red;

	if (BUFFER_SIZE <= 0 || (BUFFER_SIZE > 2147483647))
		return (NULL);
	buffer = (char *)malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (!buffer)
		return (NULL);
	fset(buffer, 0, (sizeof(char) * BUFFER_SIZE) + 1);
	bytes_red = read(fd, buffer, BUFFER_SIZE);
	if ((fd > 1024) || (!slice[fd] && bytes_red <= 0))
		return (free(buffer), NULL);
	if (bytes_red <= 0 && slice[fd] && slice[fd][0] == '\0')
		return (free(buffer), free(slice[fd]), (NULL));
	if (!slice[fd])
		slice[fd] = ft_strdup("");
	while (1)
	{
		slice[fd] = ft_strjoin(slice[fd], buffer, has(buffer, '\0'));
		if (has(slice[fd], '\n') >= 0)
			return (handle_new_line(&slice[fd], &buffer));
		if (fset(buffer, 0, BUFFER_SIZE) && read(fd, buffer, BUFFER_SIZE) <= 0)
			return (handle_end(&slice[fd], &buffer));
	}
}
