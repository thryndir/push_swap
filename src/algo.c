/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:38:39 by lgalloux          #+#    #+#             */
/*   Updated: 2024/04/03 15:48:36 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	reverse_sort(t_stack *stack_a, t_stack **stack_b)
{
	char	buff[3];
	t_stack	*current;
	int		i;

	current = *stack_b;
	i = 0;
	while (current)
	{
		buff[i++] = current->index + '0';
		current = current->next;
	}
	if ((same(buff, "312")) || (same(buff, "123")) == 1)
	{
		swap(&stack_a, stack_b, 'b', 1);
		if (same(buff, "312"))
			rotate(&stack_a, stack_b, 'b', 1);
		else
			rrotate(&stack_a, stack_b, 'b', 1);
	}
	else if (same(buff, "213") == 1)
		rrotate(&stack_a, stack_b, 'b', 1);
	else if (same(buff, "231") == 1)
		swap(&stack_a, stack_b, 'b', 1);
	else if ((same(buff, "132")))
		rotate(&stack_a, stack_b, 'b', 1);
}

void	tiny_sort(t_stack **stack_a, t_stack *stack_b)
{
	char	buff[3];
	t_stack	*current;
	int		i;

	current = *stack_a;
	i = 0;
	while (current)
	{
		buff[i++] = current->index + '0';
		current = current->next;
	}
	if ((same(buff, "132")) == 1 || (same(buff, "321")) == 1)
	{
		swap(stack_a, &stack_b, 'a', 1);
		if (same(buff, "132"))
			rotate(stack_a, &stack_b, 'a', 1);
		else
			rrotate(stack_a, &stack_b, 'a', 1);
	}
	else if (same(buff, "213") == 1)
		swap(stack_a, &stack_b, 'a', 1);
	else if (same(buff, "231") == 1)
		rrotate(stack_a, &stack_b, 'a', 1);
	else if (same(buff, "312") == 1)
		rotate(stack_a, &stack_b, 'a', 1);
}

void	small_sort(t_stack **stack_a, t_stack *stack_b)
{
	int	size;
	int	cpt;

	size = ft_lstsize(*stack_a);
	cpt = 0;
	if (size == 2)
		rotate(stack_a, &stack_b, 'a', 1);
	else if (size == 3)
		tiny_sort(stack_a, stack_b);
	else
	{
		while (cpt < 3)
		{
			while ((*stack_a)->index != 1 && (*stack_a)->index != 2
				&& (*stack_a)->index != 3)
				rotate(stack_a, &stack_b, 'a', 1);
			push(stack_a, &stack_b, 'b', 1);
			cpt++;
		}
		reverse_sort(*stack_a, &stack_b);
		if (!is_ascending(*stack_a))
			swap(stack_a, &stack_b, 'a', 1);
		while (stack_b)
			push(stack_a, &stack_b, 'a', 1);
	}
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
				if ((*stack_a)->index >> offset & 1)
					rotate(stack_a, &stack_b, 'a', 1);
				else
					push(stack_a, &stack_b, 'b', 1);
				cpt++;
			}
			while (stack_b)
				push(stack_a, &stack_b, 'a', 1);
		}
		else
			small_sort(stack_a, stack_b);
	}
	if (offset + 1 <= maxbits && size > 5)
		big_sort(stack_a, stack_b, offset + 1, maxbits);
}
