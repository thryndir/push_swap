#include "push_swap.h"
#include "libft.h"

int	swap(t_stack **stack_a, t_stack **stack_b, char type, int print)
{
	t_stack	*temp;
	t_stack	**stack;

	if (type == 'a' || type == 's')
		stack = stack_a;
	else
		stack = stack_b;
	if ((*stack)->next != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		temp->next = (*stack)->next;
		(*stack)->next = temp;
	}
	if ((type == 's' || type == 'a') && print == 1)
		ft_printf("sa\n");
	else if (type == 'b' && print == 1)
		ft_printf("sb\n");
	if (type == 's')
		swap(stack_a, stack_b, 'b', print);
	return (0);
}

int	push(t_stack **stack_a, t_stack **stack_b, char type, int print)
{
	t_stack	**stack;

	if (type == 'a')
		stack = stack_b;
	else
		stack = stack_a;
	if (*stack != NULL)
	{
		t_stack *temp = *stack;
		*stack = (*stack)->next;
		if (type == 'b')
			ft_lstadd_front(stack_b, temp);
		else if (type == 'a')
			ft_lstadd_front(stack_a, temp);
		if (print == 1)
			ft_printf("p%c\n", type);
	}
	return (0);
}

int	rotate(t_stack **stack_a, t_stack **stack_b, char type, int print)
{
	t_stack	**stack;

	if (type == 'a' || type == 'r')
		stack = stack_a;
	else
		stack = stack_b;
	if (!*stack)
		return (1);
	if ((type == 'r' || type == 'a') && print == 1)
		ft_printf("ra\n");
	else if (type == 'b' && print == 1)
		ft_printf("rb\n");
	t_stack	*last;
	last = ft_lstlast(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = NULL;
	if (type == 'r')
		rotate(stack_a, stack_b, 'b', print);
	return (0);
}

int	rrotate(t_stack **stack_a, t_stack **stack_b, char type, int print)
{
	t_stack	**stack;
	t_stack	*second;
	t_stack	*first;

	if (type == 'a' || type == 'r')
		stack = stack_a;
	else
		stack = stack_b;
	if (!stack)
		return (1);
	if ((type == 'r' || type == 'a') && print == 1)
		ft_printf("rra\n");
	else if (type == 'b' && print == 1)
		ft_printf("rrb\n");
	second = *stack;
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	first = (*stack)->next;
	(*stack)->next = NULL;
	first->next = second;
	*stack = first;
	if (type == 'r')
		rrotate(stack_a, stack_b, 'b', print);
	return (0);
}
