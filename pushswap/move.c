/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 07:04:57 by stakhtou          #+#    #+#             */
/*   Updated: 2024/06/05 08:45:03 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	do_sa(Stack *Stack, int flag)
{
	t_node	*temp;
	int		temp_data;

	if (Stack->top == NULL || Stack->top->next == NULL)
		return ;
	temp = Stack->top;
	temp_data = temp->data;
	temp->data = temp->next->data;
	temp->next->data = temp_data;
	if (flag == 1)
		ft_printf("sa\n");
	else if (flag == 2)
		ft_printf("sb\n");
}

void	do_ss(Stack *Stack_a, Stack *Stack_b)
{
	do_sa(Stack_a, 0);
	do_sa(Stack_b, 0);
	ft_printf("ss\n");
}
void	do_pa(Stack *Stack_a, Stack *Stack_b)
{
	t_node	*temp;

	if (Stack_b->top == NULL)
		return ;
	temp = Stack_b->top;
	Stack_b->top = Stack_b->top->next;
	temp->next = Stack_a->top;
	Stack_a->top = temp;
	ft_printf("pa\n");
}

void	do_pb(Stack *Stack_a, Stack *Stack_b)
{
	t_node	*temp;

	if (Stack_a->top == NULL)
		return ;
	temp = Stack_a->top;
	Stack_a->top = Stack_a->top->next;
	temp->next = Stack_b->top;
	Stack_b->top = temp;
	ft_printf("pb\n");
}

void	do_ra(Stack *Stack, int flag)
{
	t_node	*temp;
	t_node	*temp2;

	if (Stack->top == NULL || Stack->top->next == NULL)
		return ;
	temp = Stack->top;
	Stack->top = Stack->top->next;
	temp2 = Stack->top;
	while (temp2->next != NULL)
		temp2 = temp2->next;
	temp2->next = temp;
	temp->next = NULL;
	if (flag == 1)
		ft_printf("ra\n");
	else if (flag == 2)
		ft_printf("rb\n");
}
