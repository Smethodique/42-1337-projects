#include "pushswap.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	duplicate_check(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (!ft_strncmp(argv[i], argv[j], ft_strlen(argv[i])))
			{
				ft_printf("Error\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_args(int argc, char *argv[])
{
	int			i;
	long long	num;

	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (!isnumarg(argv[i]) || num > INT_MAX || num < INT_MIN)
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}


