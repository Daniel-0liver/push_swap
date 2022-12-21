/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:52:22 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/21 01:36:01 by dateixei         ###   ########.fr       */
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

void	find_second_lowest_nbr(t_stacks *stack)
{
	int	i;
	int	j;
	int k;
	int nbr_count[SIZE_NBR];
	int posit_count[SIZE_NBR];

	j = 0;
	stack->nbr_lowest = stack->stack_a[0];
	stack->posit_lowest = 0;
	while (j < SIZE_NBR)
		nbr_count[j++] = stack->stack_a[0];
	k = 0;
	while (k < SIZE_NBR)
	{
		i = 0;
		while (i < stack->size_stack_a - 1 && stack->size_stack_a > 1)
		{
			j = 0;
			while (j < SIZE_NBR && stack->stack_a[i] != stack->nbr_lowest)
			{
				if (stack->stack_a[i] < stack->nbr_lowest)
				{
					if (stack->stack_a[i] != stack->nbr_lowest)
					{
						stack->nbr_lowest = stack->stack_a[i];
						stack->posit_lowest = i;
					}
					printf("nbr = %d, posit = %d\n", stack->nbr_lowest, stack->posit_lowest);
				}
				j++;
			}
			i++;
		}
		nbr_count[k] = stack->nbr_lowest;
		posit_count[k] = stack->posit_lowest;
		k++;
	}
	i = 0;
	while (i < SIZE_NBR)
	{
		printf("nbr_count[%d] = %d, posit_count[%d] = %d\n", i, nbr_count[i], i, posit_count[i]);
		i++;
	}
	exit(0);
}

void	stack_a_is_sorted(t_stacks *stack)
{
	int	i;

	i = 0;
	while (i < (stack->size_stack_a - 1))
	{
		if (stack->stack_a[i] < stack->stack_a[i + 1])
			stack->stack_a_is_sorted = 0;
		else
		{
			stack->stack_a_is_sorted = 1;
			stack->nbr_a_not_sorted = stack->stack_a[i];
			stack->posit_a_not_sorted = i;
			return ;
		}
		i++;
	}
}
