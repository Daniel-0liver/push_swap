/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 23:52:42 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/25 22:51:45 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_logic(t_stacks *stack)
{
	while (stack->size_stack_a > 0)
	{
		find_second_lowest_nbr(stack);
		if ((stack->size_stack_a - stack->posit_lowest) > stack->posit_lowest)
			while (stack->stack_a[0] != stack->nbr_lowest)
				rotate_a(stack);
		else
			while (stack->stack_a[0] != stack->nbr_lowest)
				reverse_rotate_a(stack);
		if (stack->size_stack_a > 1 && stack->stack_a[0] > stack->stack_a[1])
			swap_a(stack);
		else if (stack->size_stack_a > 1 && stack->stack_a[0] > stack->stack_a[stack->size_stack_a - 1])
			reverse_rotate_a(stack);
		push_b(stack);
		if (stack->size_stack_b > 1 && stack->stack_b[0] < stack->stack_b[1])
		{
			if (stack->stack_a[0] > stack->stack_a[1])
				swap_a_and_b(stack);
			else
				swap_b(stack);
		}
	}
	stack_a_is_sorted(stack);
	if (stack->stack_b[0] < stack->stack_b[1])
		swap_b(stack);
	while (stack->size_stack_b > 0 || stack->stack_a_is_sorted == 1)
	{
		find_biggest_nbr_b(stack);
		if ((stack->size_stack_b - stack->posit_biggest) > stack->posit_biggest)
			while (stack->stack_b[0] != stack->nbr_biggest)
				rotate_b(stack);
		else
			while (stack->stack_b[0] != stack->nbr_biggest)
				reverse_rotate_b(stack);
		push_a(stack);
		stack_a_is_sorted(stack);
	}
}
