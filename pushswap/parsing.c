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



void	free_args(char **arr)
{
	int	k;

	k = 0;
	while (arr[k])
	{
		free(arr[k]);
		k++;
	}
	free(arr);
}


int	main(int argc, char *argv[])
{
	Stack stack;
	if (argc < 2 )
	{
		ft_printf("Error\n");
		return (1);
	}
	
	initialize(&stack);
	add_tostack(&stack, argc, argv);
	if (is_stack_sorted(&stack))
		return (1);
	print_stack(&stack);
	return (0);
}
