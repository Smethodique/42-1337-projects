#ifndef PUSHSWAP_H
#define PUSHSWAP_H
# include "1337Libft/libft.h"

typedef struct s_node
{
    int data;
    struct s_node *next;
} t_node;

typedef struct {
    t_node* top;
} Stack;

int is_stack_sorted(Stack* stack);
int	duplicate_check(int argc, char *argv[]);
int	isnumarg(char *arg);
int	parse_args(char *arg);
void	free_args(char **arr);
int	process_args(int argc, char *argv[]);
int	is_sorted(int argc, char *argv[]);
int	check_args(int argc, char *argv[]);
void push(Stack* stack, int value);
void add_tostack(Stack* stack, int argc, char *argv[]);
void print_stack(Stack* stack);
void initialize(Stack* stack);
#endif