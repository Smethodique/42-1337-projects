/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 09:57:37 by stakhtou          #+#    #+#             */
/*   Updated: 2025/01/25 20:35:48 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"
#include <stdint.h>
#include <sys/types.h>

static int	validate_result(long long result, int min, int max, int8_t *err)
{
	if (result > INT_MAX || result < INT_MIN || result < min || result > max)
	{
		*err = OUT_OF_RANGE;
		return (0);
	}
	return ((int)result);
}

int	ft_atoi(const char *str, int8_t *err, int min, int max)
{
	long long	result;
	int			sign;
	int			i;

	result = 0;
	i = 0;
	while (is_space(str[i]))
		i++;
	sign = check_sign(str, &i);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 10 + (str[i] - '0');
		else if (str[i] == '\n' || str[i] == '\r')
			break ;
		else
		{
			*err = 1;
			return (0);
		}
		i++;
	}
	return (validate_result(result * sign, min, max, err));
}

static double	parse_integer_part(char *str, int *i)
{
	double	nb;

	nb = 0;
	while (str[*i] && str[*i] >= '0' && str[*i] <= '9' && str[*i] != '.')
	{
		nb = (nb * 10.0) + (str[*i] - '0');
		(*i)++;
	}
	return (nb);
}

static double	parse_decimal_part(char *str, int *i)
{
	double	nb;
	double	div;

	nb = 0;
	div = 0.1;
	if (str[*i] == '.')
		(*i)++;
	while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
	{
		nb = nb + ((str[*i] - '0') * div);
		div *= 0.1;
		(*i)++;
	}
	return (nb);
}

double	ft_atof(char *str, int8_t *error_code, double min, double max)
{
	int		i;
	double	nb;
	int		sign;

	i = 0;
	while (is_space(str[i]))
		i++;
	sign = check_sign(str, &i);
	nb = parse_integer_part(str, &i) + parse_decimal_part(str, &i);
	if ((str[i] && str[i] != '\n'))
	{
		printf("Error: %s %f %f\n", str, min, max);
		*error_code = PARSE_ERROR;
	}
	if ((nb * sign) < min || (nb * sign) > max)
		*error_code = OUT_OF_RANGE;
	return (nb * sign);
}
