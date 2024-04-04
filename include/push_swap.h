/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:38:31 by lgalloux          #+#    #+#             */
/*   Updated: 2024/04/03 15:37:01 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_env
{
	t_stack	stack;
}	t_env;

t_stack	*stack_a_init(char **argv, int argc);
int		swap(t_stack **stack_a, t_stack **stack_b, char type, int print);
int		push(t_stack **stack_a, t_stack **stack_b, char type, int print);
int		rotate(t_stack **stack_a, t_stack **stack_b, char type, int print);
int		rrotate(t_stack **stack_a, t_stack **stack_b, char type, int print);
void	big_sort(t_stack **stack_a, t_stack *stack_b, int offset, int maxbits);
int		is_ascending(t_stack *stack_a);
int		ft_maxbits(t_stack *stack);
void	indexing(t_stack *stack_a, int index);
void	ft_error(char **argv, int which);
int		only_digit(char **argv);
int		sup_to_maxint(char **argv);
int		twice(char **argv);
void	verif_errors(char **argv, int which);
void	clean_split(char **strs);
void	ft_lst_clean(t_stack *stack);
int		nbr_size(char	*nbr);
int		same(char *first, char *second);

#endif