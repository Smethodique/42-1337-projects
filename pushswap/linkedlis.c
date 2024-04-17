#include <stdlib.h>
#include <stdio.h>
#include  "pushswap.h"


void initialize(Stack* stack) {
    stack->top = NULL;
}

void push(Stack* stack, int value) {
    t_node* new_node = (t_node*)malloc(sizeof(t_node));
    new_node->data = value;
    new_node->next = stack->top;
    stack->top = new_node;
}
int is_stack_sorted(Stack* stack)
{
    t_node* current = stack->top;
    while(current->next != NULL)
    {
        if (current->data > current->next->data)
            return 0;
        current = current->next;
    }
    return 1;
}

void add_tostack(Stack* stack, int argc, char *argv[])
{
	while(argc > 1)
	{
		if (check_args(argc, argv) && duplicate_check(argc, argv))
		{
			push(stack, ft_atoi(argv[argc - 1]));
			argc--;
		}
		else
			exit(0);
	}
}

void print_stack(Stack* stack)
{
    t_node* current = stack->top;
    while(current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}
























