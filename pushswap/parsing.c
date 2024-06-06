/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 07:04:57 by stakhtou          #+#    #+#             */
/*   Updated: 2024/06/06 23:16:36 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	isnumarg(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parse_args(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '-' || arg[i] == '+')
		{
			if (i != 0 && arg[i - 1] != ' ')
			{
				return (0);
			}
		}
		else if (!ft_isdigit(arg[i]) && arg[i] != ' ')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	process_args(char *arg, int argc, char *argv[])
{
	char	**split;

	arg = join_args_in_str(argc, argv);
	split = split_args(argc, argv);
	if (dup_check(arg) == 0)
	{
		printf("Error\n");
		free(arg);
		free_split(split);
		exit(1);
	}
	free(arg);
	free_split(split);
	return (1);
}

int	stack_size(t_Stack *stack)
{
	int		size;
	t_node	*tmp;

	size = 0;
	tmp = stack->top;
	while (tmp != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

int	main(int argc, char *argv[])
{
	t_Stack	*stack;
	t_Stack	*stack_b;
	int		size;

	if (argc < 3)
		return (1);
	stack = malloc(sizeof(t_Stack));
	stack_b = malloc(sizeof(t_Stack));
	stack->top = NULL;
	stack_b->top = NULL;
	process_args(argv[1], argc, argv);
	add_to_stackk(stack, argc, argv);
	size = stack_size(stack);
	if (is_stack_sorted(stack) == 1)
	{
		free(stack);
		free(stack_b);
		return (0);
	}
	if (size >= 2 && size <= 5)
		sort_size(stack, stack_b);
	sort_more(stack, stack_b);
	free_stack(stack);
	free_stack(stack_b);
	return (0);
}
