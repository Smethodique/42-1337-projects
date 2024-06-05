/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingT.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 07:04:57 by stakhtou          #+#    #+#             */
/*   Updated: 2024/06/05 08:44:38 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	dup_check(char *arg)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	split = ft_split(arg, ' ');
	while (split[i] != NULL)
	{
		j = i + 1;
		while (split[j] != NULL)
		{
			if (ft_atoi(split[i]) == ft_atoi(split[j]))
			{
				free_split(split);
				return (0);
			}
			j++;
		}
		i++;
	}
	free_split(split);
	return (1);
}
void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}
void	add_to_stackk(Stack *stack, int argc, char *argv[])
{
	int		i;
	char	**split;
	int		*numbers;
	int		len;
	int		j;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		len = 0;
		while (split[len])
			len++;
		numbers = split_to_int(split, len);
		j = 0;
		while (j < len)
		{
			push(stack, numbers[j]);
			j++;
		}
		free(numbers);
		free_split(split);
		i++;
	}
}

char	*join_args_in_str(int argc, char *argv[])
{
	int		i;
	char	*str;

	i = 1;
	str = ft_strdup("");
	while (i < argc)
	{
		str = ft_strjoin(str, argv[i]);
		str = ft_strjoin(str, " ");
		i++;
	}
	if (parse_args(str) == 0)
	{
		printf("Error\n");
		exit(1);
	}
	return (str);
}

int	*split_to_int(char **split, int argc)
{
	int	i;
	int	j;
	int	*arr;
	int	len;

	(void)argc;
	i = 0;
	j = 0;
	len = 0;
	while (split[len])
		len++;
	arr = malloc(sizeof(int) * len + 1);
	while (split[i] != NULL)
	{
		arr[j] = ft_atoi(split[i]);
		i++;
		j++;
	}
	i = 0;
	while (i < argc - 1)
		i++;
	return (arr);
}
