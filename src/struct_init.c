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
