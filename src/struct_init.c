#include "push_swap.h"
#include "libft.h"

t_stack	*stack_a_init(char **argv)
{
	int	i = 2;
	t_stack	*stack_a;
	int	first = ft_atoi(argv[1]);
	stack_a = ft_lstnew(first);
	while (argv[i])
	{
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	return (stack_a);
}

void	ft_maxbits(t_stack *stack)
{
	int	offset;
	int	bits;

	while (stack)
	{
		offset = 0;
		while (stack->data << offset >= 0 && offset <= 32)
			offset++;
		bits = 32 - (32 - offset);
		if (bits > stack->maxbits)
			stack->maxbits = bits;
		stack = stack->next;
	}
}