/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 07:04:57 by stakhtou          #+#    #+#             */
/*   Updated: 2024/06/11 00:16:31 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "1337Libft/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}					t_node;

typedef struct s_push
{
	int				*start;
	int				*end;
	int				*rotations;
	int				size;
}					t_push;

typedef struct s_Stack
{
	t_node			*top;
}					t_Stack;

int					is_stack_sorted(t_Stack *stack);
int					dup_check(char *arg);
int					isnumarg(char *arg);
int					parse_args(char *arg);
char				*join_args_in_str(int argc, char *argv[]);
char				**split_args(int argc, char *argv[]);
int					*split_to_int(char **split, int len);
int					process_args(char *arg, int argc, char *argv[]);
void				push(t_Stack *stack, int value);
void				add_to_stackk(t_Stack *stack, int argc, char *argv[]);
void				prinStack(t_Stack *stack);
void				free_split(char **split);
void				do_sa(t_Stack *stack, int flag);
void				do_ss(t_Stack *stack_a, t_Stack *stack_b);
void				do_pa(t_Stack *stack_a, t_Stack *stack_b);
void				do_pb(t_Stack *stack_a, t_Stack *stack_b);
void				do_ra(t_Stack *stack, int flag);
void				do_rra(t_Stack *stack, int flag);
void				do_rr(t_Stack *stack_a, t_Stack *stack_b);
void				do_rrr(t_Stack *stack_a, t_Stack *stack_b);
void				sort_two(t_Stack *stack);
void				sort_three(t_Stack *stack);
void				sort_four(t_Stack *stack_a, t_Stack *stack_b);
void				sort_five(t_Stack *stack_a, t_Stack *stack_b);
int					is_empty(t_Stack *stack_b);
int					stack_size(t_Stack *stack);
int					find_max_index(t_Stack *stack);
int					find_min_index(t_Stack *stack);
int					find_position(t_Stack *stack, int value);
int					find_max_value(t_Stack *stack);
int					*copy_stack_to_array(t_Stack *stack);
void				sort_fivet(t_Stack *stack_a, t_Stack *stack_b);
int					*sorting_array(int *arr, int size);
void				sort_more(t_Stack *stack_a, t_Stack *stack_b);
int					*copy_arrayy(int *arr, int size);
void				sort_array(int *arr, int size);
void				free_stack(t_Stack *stack);
void				sort_size(t_Stack *stack, t_Stack *stack_b);
int					is_space(char *str);
#endif