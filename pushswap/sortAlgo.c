#include "pushswap.h"

void	sort_two(Stack *stack)
{
	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	if (stack->top->data > stack->top->next->data)
		do_sa(stack, 1);
}
int	find_max_index(Stack *stack)
{
	int		max;
	t_node	*tmp;
	int		i;
	int		index;

	max = stack->top->data;
	tmp = stack->top;
	i = 0;
	index = 0;
	while (tmp)
	{
		if (tmp->data > max)
		{
			max = tmp->data;
			index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (index);
}

int	find_min_index(Stack *stack)
{
	int		min;
	t_node	*tmp;
	int		i;
	int		index;

	min = stack->top->data;
	tmp = stack->top;
	i = 0;
	index = 0;
	while (tmp)
	{
		if (tmp->data < min)
		{
			min = tmp->data;
			index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (index);
}
void	sort_three(Stack *stack)
{
	int	max;

	max = find_max_index(stack);
	if (stack->top == NULL || stack->top->next == NULL
		|| stack->top->next->next == NULL)
		return ;
	if (max == 0)
	{
		do_ra(stack, 1);
	}
	else if (max == 1)
	{
		do_rra(stack, 1);
	}
	if (stack->top->data > stack->top->next->data)
		do_sa(stack, 1);
}

void	sort_four(Stack *stack_a, Stack *stack_b)
{
	int	max_index;

	if (stack_a->top == NULL || stack_a->top->next == NULL
		|| stack_a->top->next->next == NULL
		|| stack_a->top->next->next->next == NULL)
		return ;
	max_index = find_max_index(stack_a);
	if (max_index == 1)
		do_sa(stack_a, 1);
	else if (max_index == 2)
	{
		do_ra(stack_a, 1);
		do_ra(stack_a, 1);
	}
	else if (max_index == 3)
		do_rra(stack_a, 1);
	do_pb(stack_a, stack_b);
	sort_three(stack_a);
	do_pa(stack_a, stack_b);
	do_ra(stack_a, 1);
}
void	sort_fiveT(Stack *stack_a, Stack *stack_b)
{
	int	min_index;

	min_index = find_min_index(stack_a);
	if (min_index == 4)
		do_rra(stack_a, 1);
	do_pb(stack_a, stack_b);
	min_index = find_min_index(stack_a);
	if (min_index == 1)
		do_sa(stack_a, 1);
	else if (min_index == 2)
	{
		do_ra(stack_a, 1);
		do_ra(stack_a, 1);
	}
	else if (min_index == 3)
		do_rra(stack_a, 1);
	do_pb(stack_a, stack_b);
	sort_three(stack_a);
	do_pa(stack_a, stack_b);
	do_pa(stack_a, stack_b);
	if (stack_a->top->data > stack_a->top->next->data)
		do_sa(stack_a, 1);
}
void	sort_five(Stack *stack_a, Stack *stack_b)
{
	int	min_index;

	if (stack_a->top == NULL || stack_a->top->next == NULL
		|| stack_a->top->next->next == NULL
		|| stack_a->top->next->next->next == NULL
		|| stack_a->top->next->next->next->next == NULL)
		return ;
	min_index = find_min_index(stack_a);
	if (min_index == 1)
		do_sa(stack_a, 1);
	else if (min_index == 2)
	{
		do_ra(stack_a, 1);
		do_ra(stack_a, 1);
	}
	else if (min_index == 3)
	{
		do_rra(stack_a, 1);
		do_rra(stack_a, 1);
	}
	sort_fiveT(stack_a, stack_b);
}

int	is_empty(Stack *stack)
{
	if (stack->top == NULL)
		return (1);
	return (0);
}

int	*copy_stack_to_array(Stack *stack)
{
	int		size;
	int		*arr;
	t_node	*tmp;
	int		i;

	size = stack_size(stack);
	arr = malloc(sizeof(int) * size);
	if (arr == NULL)
	{
		return (NULL);
	}
	tmp = stack->top;
	i = 0;
	while (tmp)
	{
		arr[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	arr[i] = 0;
	return (arr);
}
int	*sorting_array(int *arr, int size)
{
	int	*sorted_arr;
	int	i;
	int	j;
	int	temp;

	sorted_arr = malloc(sizeof(int) * size);
	if (sorted_arr == NULL)
	{
		free(arr);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		sorted_arr[i] = arr[i];
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (sorted_arr[i] > sorted_arr[j])
			{
				temp = sorted_arr[i];
				sorted_arr[i] = sorted_arr[j];
				sorted_arr[j] = temp;
			}
			j++;
		}
		i++;
	}
	free(arr);
	return (sorted_arr);
}
int	find_position(Stack *stack, int value)
{
	t_node	*tmp;
	int		i;

	tmp = stack->top;
	i = 0;
	while (tmp)
	{
		if (tmp->data == value)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

void sort_six(Stack *stack_a, Stack *stack_b)
{
	int i;
	i = 0;
	while (i < 2)
	{
		do_pb(stack_a, stack_b);
		i++;
	}
	sort_four(stack_a, stack_b);
	while (stack_b->top)
	{
		do_pa(stack_a, stack_b);
	}
}
void sort_seven(Stack *stack_a, Stack *stack_b)
{
	int i;
	i = 0;
	while (i < 3)
	{
		do_pb(stack_a, stack_b);
		i++;
	}
	sort_four(stack_a, stack_b);
	while (stack_b->top)
	{
		do_pa(stack_a, stack_b);
	}
}
void sort_eight(Stack *stack_a, Stack *stack_b)
{
	int i;
	i = 0;
	while (i < 4)
	{
		do_pb(stack_a, stack_b);
		i++;
	}
	sort_four(stack_a, stack_b);
	while (stack_b->top)
	{
		do_pa(stack_a, stack_b);
	}
}
int find_max_value(Stack *stack)
{
	int max;
	t_node *tmp;

	max = stack->top->data;
	tmp = stack->top;
	while (tmp)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}
void sort_more(Stack *stack_a, Stack *stack_b)
{
    int *arr;
    int *sorted_arr;
    int range, start, end;
    int size, position;

    size = stack_size(stack_a);

    // Determine range based on the size of the stack
    if (size < 15)
        range = size;
    else if (size <= 100)
        range = 22;
    else if (size <= 500)
        range = 30;
    else
        range = 50; 

    arr = copy_stack_to_array(stack_a);
    if (!arr)
        return;

    sorted_arr = sorting_array(arr, size);
    if (!sorted_arr)
    {
        free(arr);
        return;
    }

    start = 0;
    end = range;

    // Push elements from stack_a to stack_b based on the range

while (stack_size(stack_a) > 0)
{


    if (stack_a->top->data >= sorted_arr[start] && stack_a->top->data <= sorted_arr[end])
    {
        do_pb(stack_a, stack_b);
        start++;
        end++;
    }
    else if (stack_a->top->data < sorted_arr[start])
    {
        do_pb(stack_a, stack_b);
        do_ra(stack_b, 1);
        start++;
        end++;
    }
    else
    {
        do_ra(stack_a, 1);
    }

}


    while (stack_size(stack_b) > 0)
    {
        int max_val = find_max_value(stack_b);
        position = find_position(stack_b, max_val);

        while (stack_b->top->data != max_val)
        {
            if (position <= stack_size(stack_b) / 2)
                do_ra(stack_b, 1);
            else
                do_rra(stack_b, 1);
        }
		

        do_pa(stack_a, stack_b);
    }

}