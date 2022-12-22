/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:52:22 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/22 01:05:15 by dateixei         ###   ########.fr       */
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
	stack->nbr_biggest = 0;
	while (i < stack->size_stack_a -1 && stack->size_stack_a > 0)
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
	stack->posit_lowest = 0;
	while (i < stack->size_stack_a && stack->size_stack_a > 0)
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

	find_lowest_nbr(stack);
	find_biggest_nbr(stack);
	nbr_count[0] = stack->nbr_lowest;
	posit_count[0] = stack->posit_lowest;
	j = 1;
	i = 0;
	while (j < SIZE_NBR)
		nbr_count[j++] = stack->nbr_biggest;
	k = 1;
	while (k < SIZE_NBR && stack->size_stack_a > 1)
	{
		stack->nbr_lowest = stack->nbr_biggest;
		stack->posit_lowest = stack->posit_biggest;
		i = 0;
		while (i < stack->size_stack_a)
		{
			j = 0;
			while (j < SIZE_NBR)
			{
				if (stack->stack_a[i] > nbr_count[k - 1] && stack->stack_a[i] < stack->nbr_lowest)
				{
					stack->nbr_lowest = stack->stack_a[i];
					stack->posit_lowest = i;
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
	k = 0;
	j = 0;
	if (((stack->size_stack_a - 1) - posit_count[k]) < posit_count[k])
		i = (stack->size_stack_a - 1) - posit_count[k];
	else
		i = posit_count[k];
	while (k < SIZE_NBR)
	{
		if (((stack->size_stack_a - 1) - posit_count[k]) < posit_count[k] && ((stack->size_stack_a - 1) - posit_count[k]) < i)
		{
			i = (stack->size_stack_a - 1) - posit_count[k];
			printf("%d\n", i);
			j = k;
		}
		else if (posit_count[k] < i)
		{
			i = posit_count[k];
			j = k;
		}
		k++;
	}
	stack->nbr_lowest = nbr_count[j];
	stack->posit_lowest = posit_count[j];
	i = 0;
	while (i < SIZE_NBR)
	{
		printf("nbr_count[%d] = %d, posit_count[%d] = %d\n", i, nbr_count[i], i, posit_count[i]);
		i++;
	}
	printf("low = %d, posit = %d\n", stack->nbr_lowest, stack->posit_lowest);
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
