/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortAlgoF.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 07:04:57 by stakhtou          #+#    #+#             */
/*   Updated: 2024/06/10 09:57:24 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_two(t_Stack *Stack)
{
	if (Stack->top == NULL || Stack->top->next == NULL)
		return ;
	if (Stack->top->data > Stack->top->next->data)
		do_sa(Stack, 1);
}

void	sort_three(t_Stack *Stack)
{
	int	max;

	max = find_max_index(Stack);
	if (Stack->top == NULL || Stack->top->next == NULL
		|| Stack->top->next->next == NULL)
		return ;
	if (max == 0)
	{
		do_ra(Stack, 1);
	}
	else if (max == 1)
	{
		do_rra(Stack, 1);
	}
	if (Stack->top->data > Stack->top->next->data)
		do_sa(Stack, 1);
}

int	*copy_array(int *arr, int size)
{
	int	*copy;
	int	i;

	copy = malloc(sizeof(int) * size);
	if (copy == NULL || size < 0)
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

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	*sorting_array(int *arr, int size)
{
	int	*sorted_arr;

	sorted_arr = copy_array(arr, size);
	if (sorted_arr == NULL)
		return (NULL);
	sort_array(sorted_arr, size);
	free(arr);
	return (sorted_arr);
}
