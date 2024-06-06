/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveT.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 07:04:57 by stakhtou          #+#    #+#             */
/*   Updated: 2024/06/06 18:37:11 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	do_rra(t_Stack *stack, int flag)
{
	t_node	*temp;
	t_node	*temp2;

	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	temp = stack->top;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp2 = temp->next;
	temp->next = NULL;
	temp2->next = stack->top;
	stack->top = temp2;
	if (flag == 1)
		ft_printf("rra\n");
	else if (flag == 2)
		ft_printf("rrb\n");
}

void	do_rr(t_Stack *stack_a, t_Stack *stack_b)
{
	do_ra(stack_a, 0);
	do_ra(stack_b, 0);
	ft_printf("rr\n");
}

void	do_rrr(t_Stack *stack_a, t_Stack *stack_b)
{
	do_rra(stack_a, 0);
	do_rra(stack_b, 0);
	ft_printf("rrr\n");
}
