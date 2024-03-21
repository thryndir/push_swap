#include "push_swap.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	int		maxbits;
	t_stack	*stack_a;
	t_stack	*stack_b = NULL;

	stack_a = stack_a_init(argv);
	if (is_negative(stack_a, 0))
		indexing(stack_a, 1);
	maxbits = ft_maxbits(stack_a);
	big_sort(&stack_a, stack_b, 0, maxbits);
	if (is_negative(stack_a, 1))
		reindexing(stack_a);
	while (stack_a != NULL)
	{
		printf("stack a: %d\n", stack_a->data);
		stack_a = stack_a->next;
	}
	printf("\n");
	while (stack_b != NULL)
	{
		printf("stack b: %d\n", stack_b->data);
		stack_b = stack_b->next;
	}
}
