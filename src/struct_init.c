/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:38:50 by lgalloux          #+#    #+#             */
/*   Updated: 2024/04/03 15:53:24 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_stack	*stack_a_init(char **argv, int argc)
{
	t_stack	*stack_a;
	size_t	first;
	char	**strs;
	int		i;

	if (argc == 2)
	{
		strs = ft_split(argv[1], ' ');
		first = ft_atoull(strs[0]);
		i = 1;
		verif_errors(strs, 1);
	}
	else
	{
		strs = argv;
		first = ft_atoull(strs[1]);
		i = 2;
	}
	verif_errors(strs, 0);
	stack_a = ft_lstnew(first);
	while (strs[i])
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoull(strs[i++])));
	if (argc == 2)
		clean_split(strs);
	return (stack_a);
}

int	find_min(t_stack *stack_a)
{
	int	min;

	if (!stack_a)
		return (1);
	min = INT_MAX;
	while (stack_a)
	{
		if (stack_a->checked != 1 && stack_a->data <= min)
			min = stack_a->data;
		stack_a = stack_a->next;
	}
	return (min);
}

void	indexing(t_stack *stack_a, int index)
{
	t_stack	*first;
	t_stack	*second;
	int		min;

	first = stack_a;
	second = stack_a;
	min = find_min(first);
	while (second)
	{
		if (second->data == min && second->checked != 1)
		{
			second->index = index;
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
		stack->checked = 0;
		if (bits > maxbits)
			maxbits = bits;
		stack = stack->next;
	}
	return (maxbits);
}
