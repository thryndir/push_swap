/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:57:43 by lgalloux          #+#    #+#             */
/*   Updated: 2024/04/03 15:58:56 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	is_ascending(t_stack *stack)
{
	int	node_nbr;

	node_nbr = 1;
	if (stack->next == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->index <= stack->next->index)
			stack = stack->next;
		else
			return (0);
		node_nbr++;
	}
	return (node_nbr);
}

int	same(char *first, char *second)
{
	int	i;

	i = 0;
	while (first[i] && second[i])
	{
		if (first[i] != second[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_lst_clean(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

int	nbr_size(char	*nbr)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	if (nbr[i] == '-')
		i++;
	while (nbr[i] == '0')
		i++;
	while (nbr[i])
	{
		i++;
		size++;
	}
	return (size);
}

void	clean_split(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}
