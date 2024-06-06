/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortAlgoT.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 21:53:53 by stakhtou          #+#    #+#             */
/*   Updated: 2024/06/06 18:41:28 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_position(t_Stack *Stack, int value)
{
	t_node	*tmp;
	int		i;

	tmp = Stack->top;
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

int	find_max_value(t_Stack *Stack)
{
	int		max;
	t_node	*tmp;

	max = Stack->top->data;
	tmp = Stack->top;
	while (tmp)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}

int	*copy_arrayy(int *arr, int size)
{
	int	*copy;
	int	i;

	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
	{
		free(arr);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		copy[i] = arr[i];
		i++;
	}
	return (copy);
}

int	find_min_index(t_Stack *Stack)
{
	int		min;
	t_node	*tmp;
	int		i;
	int		index;

	min = Stack->top->data;
	tmp = Stack->top;
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
