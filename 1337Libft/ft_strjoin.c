/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:53:17 by stakhtou          #+#    #+#             */
/*   Updated: 2023/11/15 11:41:23 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static char	*ft_strcat(char *dst, const char *src)
{
	size_t	c;
	size_t	d;

	c = ft_strlen(dst);
	d = 0;
	while (src[d] != '\0')
	{
		dst[c] = src[d];
		c++;
		d++;
	}
	dst[c] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	total_length;
	char	*result;

	if (s1 == NULL || s2 == NULL)
	{
		return (NULL);
	}
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	total_length = len_s1 + len_s2;
	result = (char *)malloc(total_length + 1);
	if (result == NULL)
	{
		return (NULL);
	}
	ft_strcpy(result, s1);
	ft_strcat(result, s2);
	return (result);
}
