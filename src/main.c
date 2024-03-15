#include "push_swap.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	t_stack	*stack_a = NULL;
	t_stack	*stack_b = NULL;
	stack_a = stack_a_init(argv);
	big_sort(stack_a, stack_b);
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