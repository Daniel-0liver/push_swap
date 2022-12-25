/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 23:11:41 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/25 23:18:20 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_lowest_nbr(t_stacks *stack)
{
	int	i;

	i = 0;
	stack->nbr_lowest = stack->stack_a[0];
	stack->posit_lowest = 0;
	while (i < (stack->size_stack_a - 1) && stack->size_stack_a > 0)
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
	long	i;
	long	j;
	long 	k;
	long 	nbr_count[stack->nbr_lowest_by_size];
	long 	posit_count[stack->nbr_lowest_by_size];

	find_lowest_nbr(stack);
	find_biggest_nbr(stack);
	nbr_count[0] = stack->nbr_lowest;
	posit_count[0] = stack->posit_lowest;
	j = 1;
	i = 0;
	while (j < stack->nbr_lowest_by_size)
		nbr_count[j++] = stack->nbr_biggest;
	k = 1;
	while (k < stack->nbr_lowest_by_size && stack->size_stack_a > 1)
	{
		stack->nbr_lowest = stack->nbr_biggest;
		stack->posit_lowest = stack->posit_biggest;
		i = 0;
		while (i < stack->size_stack_a)
		{
			j = 0;
			while (j < stack->nbr_lowest_by_size)
			{
				if (stack->stack_a[i] > nbr_count[k - 1] && stack->stack_a[i] < stack->nbr_lowest)
				{
					stack->nbr_lowest = stack->stack_a[i];
					stack->posit_lowest = i;
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
	if ((stack->size_stack_a - posit_count[k]) < posit_count[k])
		i = stack->size_stack_a - posit_count[k];
	else
		i = posit_count[k];
	while (k < stack->nbr_lowest_by_size)
	{
		if ((stack->size_stack_a - posit_count[k]) < posit_count[k] && (stack->size_stack_a - posit_count[k]) < i)
		{
			i = stack->size_stack_a - posit_count[k];
			j = k;
		}
		else if (posit_count[k] < i)
		{
			i = posit_count[k];
			j = k;
		}
		k++;
	}
	if (stack->size_stack_a > stack->nbr_lowest_by_size)
	{
		stack->nbr_lowest = nbr_count[j];
		stack->posit_lowest = posit_count[j];
	}
	else 
		find_lowest_nbr(stack);
}
