#include "push_swap.h"
#include "libft.h"

int	is_ascending(t_stack *stack)
{
	int	node_nbr;

	node_nbr = 1;
	if (stack->next == NULL)
		return (0);
	while (stack->next)
	{
		if (stack->data <= stack->next->data)
			stack = stack->next;
		else
			return (node_nbr);
		node_nbr++;
	}
	return (node_nbr);
}

int	big_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (is_ascending(stack_a) != ft_lstsize(stack_a))
	{
		if (ft_lstsize(stack_a) > 5)
		{
			while (stack_a)
			{
				if (stack_a->data & 1 == 0)
					push(&stack_a, &stack_b, 'b', 1);
				else
					rotate(&stack_a, &stack_b, 'a', 1);
				stack_a = stack_a->next;
			}
		}
	}
	return (0);
}