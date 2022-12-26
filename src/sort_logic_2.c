/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_logic_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 22:50:36 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/26 12:57:16 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three_numbers_a(t_stacks *stack)
{
	if (stack->stack_a[0] > stack->stack_a[1] && stack->stack_a[0]
		< stack->stack_a[stack->size_stack_a - 1] && stack->stack_a[1]
		< stack->stack_a[stack->size_stack_a - 1])
		swap_a(stack);
	if (stack->stack_a[0] > stack->stack_a[1] && stack->stack_a[0]
		> stack->stack_a[stack->size_stack_a - 1] && stack->stack_a[1]
		> stack->stack_a[stack->size_stack_a - 1])
		sa_rra(stack);
	if (stack->stack_a[0] > stack->stack_a[1] && stack->stack_a[1]
		< stack->stack_a[stack->size_stack_a - 1] && stack->stack_a[0]
		> stack->stack_a[stack->size_stack_a - 1])
		rotate_a(stack);
	if (stack->stack_a[0] < stack->stack_a[1] && stack->stack_a[1]
		> stack->stack_a[stack->size_stack_a - 1] && stack->stack_a[0]
		< stack->stack_a[stack->size_stack_a - 1])
		sa_ra(stack);
	if (stack->stack_a[0] < stack->stack_a[1] && stack->stack_a[1]
		> stack->stack_a[stack->size_stack_a - 1] && stack->stack_a[0]
		> stack->stack_a[stack->size_stack_a - 1])
		reverse_rotate_a(stack);
}

void	sort_three_numbers_b(t_stacks *stack)
{
	if (stack->stack_b[0] > stack->stack_b[1] && stack->stack_b[1]
		< stack->stack_b[stack->size_stack_b - 1] && stack->stack_b[0]
		< stack->stack_b[stack->size_stack_b - 1])
		reverse_rotate_b(stack);
	if (stack->stack_b[0] < stack->stack_b[1] && stack->stack_b[1]
		< stack->stack_b[stack->size_stack_b - 1] && stack->stack_b[0]
		< stack->stack_b[stack->size_stack_b - 1])
		sb_rrb(stack);
	if (stack->stack_b[0] > stack->stack_b[1] && stack->stack_b[1]
		< stack->stack_b[stack->size_stack_b - 1] && stack->stack_b[0]
		> stack->stack_b[stack->size_stack_b - 1])
		sb_rb(stack);
	if (stack->stack_b[0] < stack->stack_b[1] && stack->stack_b[1]
		> stack->stack_b[stack->size_stack_b - 1] && stack->stack_b[0]
		< stack->stack_b[stack->size_stack_b - 1])
		rotate_b(stack);
	if (stack->stack_b[0] < stack->stack_b[1] && stack->stack_b[1]
		> stack->stack_b[stack->size_stack_b - 1] && stack->stack_b[0]
		> stack->stack_b[stack->size_stack_b - 1])
		swap_b(stack);
}

void	sort_five_nbr_util(t_stacks *stack)
{
	while (stack->size_stack_a > 3)
	{
		if (stack->size_stack_b > 2 && stack->stack_b[0] < stack->stack_b[1])
		{
			if (stack->stack_a[0] < stack->stack_a[1])
				swap_a_and_b(stack);
			else
				swap_b(stack);
		}
		else if (stack->stack_a[0] > stack->stack_a[1])
			swap_a(stack);
		else if (stack->stack_a[0] > stack->stack_a[stack->size_stack_a - 1])
			reverse_rotate_a(stack);
		else
			push_b(stack);
		if (stack->size_stack_b > 2)
			sort_three_numbers_b(stack);
	}
}

void	sort_five_numbers(t_stacks *stack)
{
	sort_five_nbr_util(stack);
	sort_three_numbers_a(stack);
	stack_a_is_sorted(stack);
	if (stack->stack_b[0] < stack->stack_b[1])
		swap_b(stack);
	while (stack->size_stack_b > 0 || stack->stack_a_is_sorted == 1)
	{
		while (stack->stack_a_is_sorted == 1)
		{
			while (stack->nbr_a_not_sorted != stack->stack_a[0])
				rotate_a(stack);
			if (stack->stack_a[0] > stack->stack_a[1])
				swap_a(stack);
			sort_three_numbers_a(stack);
			stack_a_is_sorted(stack);
		}
		push_a(stack);
		if (stack->stack_b[0] < stack->stack_b[1] && stack->size_stack_b > 1)
			swap_b(stack);
		stack_a_is_sorted(stack);
	}
	is_sorted(stack);
}
