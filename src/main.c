/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:48:48 by lgalloux          #+#    #+#             */
/*   Updated: 2024/04/03 15:50:09 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		maxbits;

	if (argc == 1)
		return (1);
	stack_b = NULL;
	stack_a = stack_a_init(argv, argc);
	indexing(stack_a, 1);
	maxbits = ft_maxbits(stack_a);
	big_sort(&stack_a, stack_b, 0, maxbits);
	ft_lst_clean(stack_a);
	return (0);
}
