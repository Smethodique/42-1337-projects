/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:48:38 by stakhtou          #+#    #+#             */
/*   Updated: 2023/11/24 05:22:51 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	if (!haystack && len == 0)
		return (NULL);
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i + needle_len - 1 < len)
	{
		if (ft_strncmp(&haystack[i], needle, needle_len) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
