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
void free_stack(Stack *stack) ;
int					dup_check(char *arg);
int					isnumarg(char *arg);
int					parse_args(char *arg);
void				free_args(char **arr);
char				*join_args_in_str(int argc, char *argv[]);
char				**split_args(int argc, char *argv[]);
int					*split_to_int(char **split, int len);
int					process_args(char *arg, int argc, char *argv[]);
int					check_args(int argc, char *argv[]);
void				push(Stack *stack, int value);
void	add_to_stackk(Stack *stack, int argc, char *argv[]);
void				print_stack(Stack *stack);
void	free_split(char **split);
#endif