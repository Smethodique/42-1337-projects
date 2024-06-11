/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 07:04:57 by stakhtou          #+#    #+#             */
/*   Updated: 2024/06/10 12:15:45 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	initialize(t_Stack *Stack)
{
	Stack->top = NULL;
}

void	push(t_Stack *Stack, int data)
{
	t_node	*new_node;
	t_node	*current;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = data;
	new_node->next = NULL;
	if (Stack->top == NULL)
	{
		Stack->top = new_node;
	}
	else
	{
		current = Stack->top;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
	}
}

int	is_stack_sorted(t_Stack *Stack)
{
	t_node	*current;

	current = Stack->top;
	if(!Stack)
	  write(2,"Error\n",7);
	while (current->next != NULL)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

int	find_max_index(t_Stack *Stack)
{
	int		max;
	t_node	*tmp;
	int		i;
	int		index;

	max = Stack->top->data;
	tmp = Stack->top;
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

char	**split_args(int argc, char *argv[])
{
	char	*args;
	char	**split;

	args = join_args_in_str(argc, argv);
	if (!args)
		return (NULL);
	split = ft_split(args, ' ');
	free(args);
	if (!split)
		return (NULL);
	return (split);
}
