/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortAlgo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 07:04:57 by stakhtou          #+#    #+#             */
/*   Updated: 2024/06/06 18:38:19 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_four(t_Stack *Stack_a, t_Stack *Stack_b)
{
	int	max_index;

	if (Stack_a->top == NULL || Stack_a->top->next == NULL
		|| Stack_a->top->next->next == NULL
		|| Stack_a->top->next->next->next == NULL)
		return ;
	max_index = find_max_index(Stack_a);
	if (max_index == 1)
		do_sa(Stack_a, 1);
	else if (max_index == 2)
	{
		do_ra(Stack_a, 1);
		do_ra(Stack_a, 1);
	}
	else if (max_index == 3)
		do_rra(Stack_a, 1);
	do_pb(Stack_a, Stack_b);
	sort_three(Stack_a);
	do_pa(Stack_a, Stack_b);
	do_ra(Stack_a, 1);
}

void	sort_fivet(t_Stack *Stack_a, t_Stack *Stack_b)
{
	int	min_index;

	min_index = find_min_index(Stack_a);
	if (min_index == 4)
		do_rra(Stack_a, 1);
	do_pb(Stack_a, Stack_b);
	min_index = find_min_index(Stack_a);
	if (min_index == 1)
		do_sa(Stack_a, 1);
	else if (min_index == 2)
	{
		do_ra(Stack_a, 1);
		do_ra(Stack_a, 1);
	}
	else if (min_index == 3)
		do_rra(Stack_a, 1);
	do_pb(Stack_a, Stack_b);
	sort_three(Stack_a);
	do_pa(Stack_a, Stack_b);
	do_pa(Stack_a, Stack_b);
	if (Stack_a->top->data > Stack_a->top->next->data)
		do_sa(Stack_a, 1);
}

void	sort_five(t_Stack *Stack_a, t_Stack *Stack_b)
{
	int	min_index;

	if (Stack_a->top == NULL || Stack_a->top->next == NULL
		|| Stack_a->top->next->next == NULL
		|| Stack_a->top->next->next->next == NULL
		|| Stack_a->top->next->next->next->next == NULL)
		return ;
	min_index = find_min_index(Stack_a);
	if (min_index == 1)
		do_sa(Stack_a, 1);
	else if (min_index == 2)
	{
		do_ra(Stack_a, 1);
		do_ra(Stack_a, 1);
	}
	else if (min_index == 3)
	{
		do_rra(Stack_a, 1);
		do_rra(Stack_a, 1);
	}
	sort_fivet(Stack_a, Stack_b);
}

int	is_empty(t_Stack *Stack)
{
	if (Stack->top == NULL)
		return (1);
	return (0);
}

int	*copy_stack_to_array(t_Stack *Stack)
{
	int		size;
	int		*arr;
	t_node	*tmp;
	int		i;

	size = stack_size(Stack);
	arr = malloc(sizeof(int) * size);
	if (arr == NULL)
	{
		return (NULL);
	}
	tmp = Stack->top;
	i = 0;
	while (tmp)
	{
		arr[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	return (arr);
}
