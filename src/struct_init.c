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

void	indexing(t_stack *stack_a, int index)
{
	t_stack	*first;
	t_stack	*second;
	int		min;

	min = INT_MAX;
	first = stack_a;
	second = stack_a;
	while (first)
	{
		if (first->checked != 1 && first->data <= min)
			min = first->data;
		first = first->next;
	}
	while (second)
	{
		if (second->data == min && second->checked != 1)
		{
			second->pdata = second->data;
			second->data = index;
			second->checked = 1;
		}
		second = second->next;
	}
	if (index + 1 <= ft_lstsize(stack_a))
		indexing(stack_a, index + 1);
}

int	ft_maxbits(t_stack *stack)
{
	int	offset;
	int	bits;
	int	maxbits;

	maxbits = 0;
	while (stack)
	{
		offset = 0;
		while (stack->data << offset >= 0 && offset <= 32)
			offset++;
		bits = 32 - offset;
		if (bits > maxbits)
			maxbits = bits;
		stack = stack->next;
	}
	return (maxbits);
}
