/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 23:11:41 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/26 01:15:11 by dateixei         ###   ########.fr       */
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

void	init_find_x_lowest_nbr_util(t_stacks *stack, t_low *low)
{
	low->nbr_count = (int*)malloc(stack->nbr_lowest_by_size * sizeof(int));
	low->posit_count = (int*)malloc(stack->nbr_lowest_by_size * sizeof(int));
	find_lowest_nbr(stack);
	find_biggest_nbr(stack);
	low->nbr_count[0] = stack->nbr_lowest;
	low->posit_count[0] = stack->posit_lowest;
	low->j = 1;
	low->i = 0;
	while (low->j < stack->nbr_lowest_by_size)
		low->nbr_count[low->j++] = stack->nbr_biggest;
	low->k = 1;
}

void	find_x_lowest_nbr_util(t_stacks *stack, t_low *low)
{
	while (low->k < stack->nbr_lowest_by_size && stack->size_stack_a > 1)
	{
		stack->nbr_lowest = stack->nbr_biggest;
		stack->posit_lowest = stack->posit_biggest;
		low->i = 0;
		while (low->i < stack->size_stack_a)
		{
			low->j = 0;
			while (low->j < stack->nbr_lowest_by_size)
			{
				if (stack->stack_a[low->i] > low->nbr_count[low->k - 1] && stack->stack_a[low->i] < stack->nbr_lowest)
				{
					stack->nbr_lowest = stack->stack_a[low->i];
					stack->posit_lowest = low->i;
				}
				low->j++;
			}
			low->i++;
		}
		low->nbr_count[low->k] = stack->nbr_lowest;
		low->posit_count[low->k] = stack->posit_lowest;
		low->k++;
	}
}

void	find_x_posit_nbr(t_stacks *stack, t_low *low)
{
	low->k = 0;
	low->j = 0;
	if ((stack->size_stack_a - low->posit_count[low->k]) < low->posit_count[low->k])
		low->i = stack->size_stack_a - low->posit_count[low->k];
	else
		low->i = low->posit_count[low->k];
	while (low->k < stack->nbr_lowest_by_size)
	{
		if ((stack->size_stack_a - low->posit_count[low->k]) < low->posit_count[low->k] && (stack->size_stack_a - low->posit_count[low->k]) < low->i)
		{
			low->i = stack->size_stack_a - low->posit_count[low->k];
			low->j = low->k;
		}
		else if (low->posit_count[low->k] < low->i)
		{
			low->i = low->posit_count[low->k];
			low->j = low->k;
		}
		low->k++;
	}
}

void	find_x_lowest_nbr(t_stacks *stack)
{
	t_low	low;

	init_find_x_lowest_nbr_util(stack, &low);
	find_x_lowest_nbr_util(stack, &low);
	if (stack->size_stack_a > 1)
		find_x_posit_nbr(stack, &low);
	if (stack->size_stack_a > stack->nbr_lowest_by_size)
	{
		stack->nbr_lowest = low.nbr_count[low.j];
		stack->posit_lowest = low.posit_count[low.j];
	}
	else 
		find_lowest_nbr(stack);
	free(low.nbr_count);
	low.nbr_count = NULL;
	free(low.posit_count);
	low.posit_count = NULL;
}
