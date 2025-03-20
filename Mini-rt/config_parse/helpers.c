/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 09:54:02 by stakhtou          #+#    #+#             */
/*   Updated: 2025/01/25 10:00:40 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "minirt.h"
#include "parse.h"

int	check_sign(const char *str, int *i)
{
	if (str[*i] == '-')
	{
		(*i)++;
		return (-1);
	}
	if (str[*i] == '+')
		(*i)++;
	return (1);
}

int	end_with(char *str, char *with)
{
	int	str_len;
	int	with_len;

	str_len = ft_strlen(str);
	with_len = ft_strlen(with);
	while (str_len > 0 && with_len > 0)
	{
		if (str[str_len] != with[with_len])
			return (-1);
		str_len--;
		with_len--;
	}
	return (1);
}

void	set_error(int8_t *error, enum e_ERROR_CODE code)
{
	*error = code;
}
