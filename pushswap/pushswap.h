#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "1337Libft/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}					t_node;

typedef struct
{
	t_node			*top;
}					Stack;

int					is_stack_sorted(Stack *stack);
int					dup_check(char *arg);
int					isnumarg(char *arg);
int					parse_args(char *arg);
char				*join_args_in_str(int argc, char *argv[]);
char				**split_args(int argc, char *argv[]);
int					*split_to_int(char **split, int len);
int					process_args(char *arg, int argc, char *argv[]);
void				push(Stack *stack, int value);
void				add_to_stackk(Stack *stack, int argc, char *argv[]);
void				print_stack(Stack *stack);
void				free_split(char **split);
void				do_sa(Stack *stack, int flag);
void				do_ss(Stack *stack_a, Stack *stack_b);
void				do_pa(Stack *stack_a, Stack *stack_b);
void				do_pb(Stack *stack_a, Stack *stack_b);
void				do_ra(Stack *stack, int flag);
void				do_rra(Stack *stack, int flag);
void				do_rr(Stack *stack_a, Stack *stack_b);
void				do_rrr(Stack *stack_a, Stack *stack_b);
void				sort_two(Stack *stack);
void				sort_three(Stack *stack);
void				sort_four(Stack *stack_a, Stack *stack_b);
void				sort_five(Stack *stack_a, Stack *stack_b);
int					is_empty(Stack *stack_b);
int					stack_size(Stack *stack);
int					find_max_index(Stack *stack);
int					find_min_index(Stack *stack);
void sort_six(Stack *stack_a, Stack *stack_b);
void sort_seven(Stack *stack_a, Stack *stack_b);
void sort_eight(Stack *stack_a, Stack *stack_b);
int* copy_stack_to_array(Stack *stack);

int* sorting_array(int *arr, int size);
void sort_more(Stack *stack_a, Stack *stack_b);

#endif