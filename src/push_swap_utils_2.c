/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:52:22 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/18 20:03:32 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isalpha(int c)
{
	if (!((c >= 'A' && c <= 'Z') || (c
				>= 'a' && c <= 'z')))
	{
		return (1);
	}
	else
		return (0);
}

void	is_non_number(char **argv)
{
	int	i;
	int j;
	int	k;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			k = ft_isalpha(argv[i][j]);
			if (k == 0)
			{
				write(2,"Error\n", 6);
				exit (1);
			}
			j++;
		}
		i++;
	}
}

void	find_biggest_nbr(t_stacks *stack)
{
	int	i;

	i = 0;
	stack->nbr_biggest = stack->stack_a[0];
	while (i < stack->size_stack_a -1)
	{
		if (stack->stack_a[i] >= stack->nbr_biggest)
		{
			stack->nbr_biggest = stack->stack_a[i];
			stack->posit_biggest = i;
		}
		i++;
	}
}

void	find_lowest_nbr(t_stacks *stack)
{
	int	i;

	i = 0;
	stack->nbr_lowest = stack->stack_a[0];
	while (i < stack->size_stack_a -1)
	{
		if (stack->stack_a[i] <= stack->nbr_lowest)
		{
			stack->nbr_lowest = stack->stack_a[i];
			stack->posit_lowest = i;
		}
		i++;
	}
}