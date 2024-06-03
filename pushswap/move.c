
#include "pushswap.h"

void	do_sa(Stack *stack, int flag)
{
	t_node	*temp;
	int		temp_data;

	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	temp = stack->top;
	temp_data = temp->data;
	temp->data = temp->next->data;
	temp->next->data = temp_data;
	if (flag == 1)
		ft_printf("sa\n");
	else if (flag == 2)
		ft_printf("sb\n");
}

void	do_ss(Stack *stack_a, Stack *stack_b)
{
	do_sa(stack_a, 0);
	do_sa(stack_b, 0);
	ft_printf("ss\n");
}
void	do_pa(Stack *stack_a, Stack *stack_b)
{
	t_node	*temp;

	if (stack_b->top == NULL)
		return ;
	temp = stack_b->top;
	stack_b->top = stack_b->top->next;
	temp->next = stack_a->top;
	stack_a->top = temp;
	ft_printf("pa\n");
}

void	do_pb(Stack *stack_a, Stack *stack_b)
{

	t_node	*temp;

	if (stack_a->top == NULL)
		return ;
	temp = stack_a->top;
	stack_a->top = stack_a->top->next;
	temp->next = stack_b->top;
	stack_b->top = temp;
	ft_printf("pb\n");
}

void	do_ra(Stack *stack, int flag)
{
	t_node	*temp;
	t_node	*temp2;

	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	temp = stack->top;
	stack->top = stack->top->next;
	temp2 = stack->top;
	while (temp2->next != NULL)
		temp2 = temp2->next;
	temp2->next = temp;
	temp->next = NULL;
	if (flag == 1)
		ft_printf("ra\n");
	else if (flag == 2)
		ft_printf("rb\n");
}
