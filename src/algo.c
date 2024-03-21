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
			return (0);
		node_nbr++;
	}
	return (node_nbr);
}

int	is_negative(t_stack	*stack_a, int type)
{
	while (stack_a)
	{
		if (type == 0)
		{
			if (stack_a->data < 0)
				return (1);
		}
		else 
		{
			if (stack_a->pdata < 0)
					return (1);
		}
		stack_a = stack_a->next;
	}
	return (0);
}

void	reindexing(t_stack *stack_a)
{
	while (stack_a)
	{
		stack_a->data = stack_a->pdata;
		stack_a = stack_a->next;
	}
}

void	print_node(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d->", stack->data);
		stack = stack->next;
	}
	write(1, "\n", 1);
}

void	print_bits(int	nbr)
{
	int	bit = 31;
	ft_printnbr(nbr);
	write(1, "\n", 1);
	while (bit >= 0)
	{
		if ((nbr >> bit) & 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		bit--;
	}
	write(1, "\n", 1);
}

void	big_sort(t_stack **stack_a, t_stack *stack_b, int offset, int maxbits)
{
	int	cpt;
	int	size;

	cpt = 0;
	size = ft_lstsize(*stack_a);
	if (!is_ascending(*stack_a))
	{
		if (ft_lstsize(*stack_a) > 5)
		{
			while (cpt < size)
			{
				if ((*stack_a)->data >> offset & 1)
					rotate(stack_a, &stack_b, 'a', 1);
				else
					push(stack_a, &stack_b, 'b', 1);
				cpt++;
			}
			while (stack_b)
				push(stack_a, &stack_b, 'a', 1);
		}
	}
	if (offset + 1 <= maxbits)
		big_sort(stack_a, stack_b, offset + 1, maxbits);
}
