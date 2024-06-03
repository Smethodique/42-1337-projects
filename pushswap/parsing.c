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
int	stack_size(Stack *stack)
{
	int		size;
	t_node	*tmp;

	size = 0;
	tmp = stack->top;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
void	pushT(Stack *stack, int data)
{
	t_node	*new_node;

	// Create a new node
	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
	{
		fprintf(stderr, "Out of memory\n");
		exit(1);
	}
	// Set the data and next node
	new_node->data = data;
	new_node->next = stack->top;
	// Set the new node as the top of the stack
	stack->top = new_node;
}

int	main(int argc, char *argv[])
{
	Stack *stack;
	Stack *stack_b;

	if (argc < 2)
		return (1);

	stack = malloc(sizeof(Stack));
	stack_b = malloc(sizeof(Stack));
	stack->top = NULL;
	stack_b->top = NULL;
	process_args(argv[1], argc, argv);
	add_to_stackk(stack, argc, argv);

	if (is_stack_sorted(stack) == 1)
	{
		free(stack);
		free(stack_b);
		return (0);
	}

	 sort_more(stack, stack_b);
	if (is_stack_sorted(stack) == 1)
		printf("OK\n");

	return (0);
}