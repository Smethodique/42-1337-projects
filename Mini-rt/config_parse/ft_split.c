/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 09:53:11 by stakhtou          #+#    #+#             */
/*   Updated: 2025/01/25 21:04:37 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	is_delimiter(char c, const char *delim)
{
	while (*delim)
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

static int	count_words(char const *s, const char *delim)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (s[i])
	{
		while (s[i] && is_delimiter(s[i], delim))
			i++;
		if (s[i])
			wc++;
		while (s[i] && !is_delimiter(s[i], delim))
			i++;
	}
	return (wc);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = strlen(src);
	if (!n)
		return (len);
	while (i < n - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (len);
}

char	**split_words(const char *s, const char *delim, int wc, char **arr)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (i < wc)
	{
		while (s[j] && is_delimiter(s[j], delim))
			j++;
		len = 0;
		while (s[j + len] && !is_delimiter(s[j + len], delim))
			len++;
		if (len > 0)
		{
			arr[i] = (char *)malloc(len + 1);
			if (!arr[i])
				return (free_arr(arr, i));
			ft_strlcpy(arr[i], s + j, len + 1);
			i++;
		}
		j += len;
	}
	return (arr);
}

char	**ft_split(char const *s, const char *delim)
{
	char	**arr;
	int		wc;

	if (!s || !delim)
		return (NULL);
	while (*s && is_delimiter(*s, delim))
		s++;
	wc = count_words(s, delim);
	if (wc == 0)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!arr)
		return (NULL);
	if (!split_words(s, delim, wc, arr))
		return (NULL);
	arr[wc] = NULL;
	return (arr);
}
