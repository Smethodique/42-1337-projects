/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baarif <baarif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:40:04 by baarif            #+#    #+#             */
/*   Updated: 2025/01/25 10:00:36 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strdup(char *str1)
{
	size_t	len;
	char	*s;
	size_t	i;

	i = 0;
	len = ft_strlen((char *)str1);
	s = (char *)malloc(len + 1);
	if (s == NULL)
		return (NULL);
	while (i < len)
	{
		s[i] = str1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

int	has(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	if (str[i] == c)
		return (i);
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2, int limit)
{
	int		i;
	char	*s;
	int		tmp;

	tmp = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	s = (char *)malloc(ft_strlen((char *)s1) + limit + 1);
	if (s == NULL)
		return (NULL);
	while (s1[i])
		s[i++] = s1[tmp++];
	tmp = 0;
	while (s2[tmp] && tmp < limit)
		s[i++] = s2[tmp++];
	s[i] = '\0';
	free(s1);
	return (s);
}

void	*fset(void *s, int c, size_t n)
{
	unsigned char	*str;
	int				i;

	str = (unsigned char *)s;
	i = 0;
	while ((size_t)i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return ((str));
}
