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
			printf("%s", arg);
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
		system("leaks push_swap");
		exit(1);
	}
	free(arg);
	free_split(split);
	return (1);
}

int	main(int argc, char *argv[])
{
	Stack	*stack;
	if (argc < 2)
	{
		return (1);
	}
	stack = malloc(sizeof(Stack));
	stack->top = NULL;
	process_args(argv[1], argc, argv);
	add_to_stackk(stack, argc, argv);
	print_stack(stack);
	free_stack(stack);
	free(stack);
	return (0);
}
