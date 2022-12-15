/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 23:52:42 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/15 23:43:09 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three_numbers(t_stacks *stack)
{
	if (stack->stack_a[0] > stack->stack_a[1] && stack->stack_a[0] < 
			stack->stack_a[stack->size_stack_a - 1] && stack->stack_a[1] 
				< stack->stack_a[stack->size_stack_a - 1])
		swap_a(stack);
	if (stack->stack_a[0] > stack->stack_a[1] && stack->stack_a[0] >
			stack->stack_a[stack->size_stack_a - 1] && stack->stack_a[1]
				> stack->stack_a[stack->size_stack_a - 1])
		sa_rra(stack);
	if (stack->stack_a[0] > stack->stack_a[1] && stack->stack_a[1] <
			stack->stack_a[stack->size_stack_a - 1] && stack->stack_a[0]
				> stack->stack_a[stack->size_stack_a - 1])
		rotate_a(stack);
	if (stack->stack_a[0] < stack->stack_a[1] && stack->stack_a[1] >
			stack->stack_a[stack->size_stack_a - 1] && stack->stack_a[0]
				< stack->stack_a[stack->size_stack_a - 1])
		sa_ra(stack);
	if (stack->stack_a[0] < stack->stack_a[1] && stack->stack_a[1] >
			stack->stack_a[stack->size_stack_a - 1] && stack->stack_a[0]
				> stack->stack_a[stack->size_stack_a - 1])
		reverse_rotate_a(stack);
}

void	sort_logic(t_stacks *stack)
{
	if (stack->size_stack_a == 3)
		sort_three_numbers(stack);
}
