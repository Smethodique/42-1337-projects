/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortAlgoTH.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 07:04:57 by stakhtou          #+#    #+#             */
/*   Updated: 2024/06/06 18:42:30 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	determine_range(int size)
{
	if (size < 15)
		return (size);
	else if (size <= 100)
		return (18);
	else if (size <= 500)
		return (34);
	else
		return (29);
}

void	handle_push_conditions(t_Stack *stack_a, t_Stack *stack_b,
		int *sorted_arr, t_push *params)
{
	if (stack_a->top->data >= sorted_arr[*params->start]
		&& stack_a->top->data <= sorted_arr[*params->end])
	{
		do_pb(stack_a, stack_b);
		(*params->start)++;
		(*params->end)++;
	}
	else if (stack_a->top->data < sorted_arr[*params->start])
	{
		do_pb(stack_a, stack_b);
		do_ra(stack_b, 1);
		(*params->start)++;
		(*params->end)++;
	}
	else if (stack_a->top->data > sorted_arr[*params->end])
	{
		do_ra(stack_a, 1);
		(*params->rotations)++;
	}
	if (*params->rotations >= stack_size(stack_a))
	{
		do_pb(stack_a, stack_b);
		(*params->start)++;
		(*params->end)++;
	}
}

void	push_to_stack_b(t_Stack *stack_a, t_Stack *stack_b, int *sorted_arr,
		int range)
{
	int		start;
	int		end;
	int		rotations;
	t_push	params;

	start = 0;
	end = range;
	rotations = 0;
	params.start = &start;
	params.end = &end;
	params.rotations = &rotations;
	while (stack_size(stack_a) > 0)
	{
		handle_push_conditions(stack_a, stack_b, sorted_arr, &params);
	}
}

void	sort_stack_b_to_stack_a(t_Stack *stack_a, t_Stack *stack_b)
{
	int	max_val;
	int	position;

	while (stack_size(stack_b) > 0)
	{
		max_val = find_max_value(stack_b);
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

void	sort_more(t_Stack *stack_a, t_Stack *stack_b)
{
	int	size;
	int	range;
	int	*arr;
	int	*sorted_arr;

	size = stack_size(stack_a);
	range = determine_range(size);
	arr = copy_stack_to_array(stack_a);
	if (!arr)
		return ;
	sorted_arr = sorting_array(arr, size);
	if (!sorted_arr)
	{
		free(arr);
		return ;
	}
	push_to_stack_b(stack_a, stack_b, sorted_arr, range);
	sort_stack_b_to_stack_a(stack_a, stack_b);
}
