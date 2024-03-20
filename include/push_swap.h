#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

typedef struct s_env
{
	t_stack	stack;
}	t_env;

t_stack	*stack_a_init(char **argv);
int		swap(t_stack **stack_a, t_stack **stack_b, char type, int print);
int		push(t_stack **stack_a, t_stack **stack_b, char type, int print);
int		rotate(t_stack **stack_a, t_stack **stack_b, char type, int print);
int		rrotate(t_stack **stack_a, t_stack **stack_b, char type, int print);
void	big_sort(t_stack **stack_a, t_stack *stack_b, int offset, int maxbits);
int		is_ascending(t_stack *stack_a);
void	ft_maxbits(t_stack *stack);

#endif