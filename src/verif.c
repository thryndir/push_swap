/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:51:02 by lgalloux          #+#    #+#             */
/*   Updated: 2024/04/03 15:57:26 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	verif_errors(char **argv, int which)
{
	if (!only_digit(argv))
		ft_error(argv, which);
	if (twice(argv))
		ft_error(argv, which);
	if (sup_to_maxint(argv))
		ft_error(argv, which);
}

int	only_digit(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (((argv[i][j] < '0' || (argv[i][j] > '9')) && argv[i][j] != '-')
			|| (argv[i][j] == '-' && (argv[i][j + 1] < '0'
			|| argv[i][j + 1] > '9')))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	twice(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atolli(argv[j]) == ft_atolli(argv[i]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	sup_to_maxint(char	**argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if ((nbr_size(argv[i]) > 10) || (ft_atoull(argv[i]) > INT_MAX
				&& argv[i][0] != '-') || (ft_atolli(argv[i]) < INT_MIN))
			return (1);
		i++;
	}
	return (0);
}

void	ft_error(char **argv, int which)
{
	int	i;

	i = 0;
	ft_printf("Error\n");
	if (which == 1)
		clean_split(argv);
	exit(EXIT_FAILURE);
}
