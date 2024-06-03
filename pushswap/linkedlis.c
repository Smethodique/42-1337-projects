
#include "pushswap.h"
#include <stdio.h>
#include <stdlib.h>

void	initialize(Stack *stack)
{
	stack->top = NULL;
}

void	push(Stack *stack, int data)
{
	t_node	*new_node;
	t_node	*current;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = data;
	new_node->next = NULL;
	if (stack->top == NULL)
	{
		stack->top = new_node;
	}
	else
	{
		current = stack->top;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
	}
}

int	is_stack_sorted(Stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current->next != NULL)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

void	print_stack(Stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current != NULL)
	{
		printf("%d\n", current->data);

		current = current->next;
	}
}
