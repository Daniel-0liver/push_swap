/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 23:52:42 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/19 21:19:36 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three_numbers_a(t_stacks *stack)
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

void	sort_three_numbers_b(t_stacks *stack)
{
	if (stack->stack_b[0] > stack->stack_b[1] && stack->stack_b[1] < 
			stack->stack_b[stack->size_stack_b - 1] && stack->stack_b[0]
				< stack->stack_b[stack->size_stack_b - 1])
		reverse_rotate_b(stack);
	if (stack->stack_b[0] < stack->stack_b[1] && stack->stack_b[1] < 
			stack->stack_b[stack->size_stack_b - 1] && stack->stack_b[0]
				< stack->stack_b[stack->size_stack_b - 1])
		sb_rrb(stack);
	if (stack->stack_b[0] > stack->stack_b[1] && stack->stack_b[1] < 
			stack->stack_b[stack->size_stack_b - 1] && stack->stack_b[0]
				> stack->stack_b[stack->size_stack_b - 1])
		sb_rb(stack);
	if (stack->stack_b[0] < stack->stack_b[1] && stack->stack_b[1] > 
			stack->stack_b[stack->size_stack_b - 1] && stack->stack_b[0]
				< stack->stack_b[stack->size_stack_b - 1])
		rotate_b(stack);
	if (stack->stack_b[0] < stack->stack_b[1] && stack->stack_b[1] > 
			stack->stack_b[stack->size_stack_b - 1] && stack->stack_b[0]
				> stack->stack_b[stack->size_stack_b - 1])
		swap_b(stack);
}

void	sort_five_numbers(t_stacks *stack)
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
	}
	// print_stacks(stack);
	// print_stacks(stack);
	sort_three_numbers_a(stack);
	// print_stacks(stack);
	stack_a_is_sorted(stack);
	while (stack->size_stack_b > 0 || stack->stack_a_is_sorted == 1)
	{
		// print_stacks(stack);
		if (stack->stack_a_is_sorted == 1)
		{
			while (stack->nbr_a_not_sorted != stack->stack_a[0])
				rotate_a(stack);
			if (stack->stack_a[0] > stack->stack_a[1])
				swap_a(stack);
			else if (stack->size_stack_b > 0)
				push_a(stack);
		}
		// print_stacks(stack);
		push_a(stack);
		sort_three_numbers_a(stack);
		stack_a_is_sorted(stack);
		// print_stacks(stack);
	}
	// print_stacks(stack);
	is_sorted(stack);
}

void	sort_logic(t_stacks *stack)
{
	while (stack->size_stack_a > 3)
	{
		find_lowest_nbr(stack);
		// printf("Lowest = %d\nBiggest = %d\nstack[0] = %d\n", stack->nbr_lowest, stack->nbr_biggest, stack->stack_a[0]);
		while (stack->stack_a[0] != stack->nbr_lowest)
		{
			if (stack->posit_lowest < (stack->size_stack_a / 2))
				rotate_a(stack);
			else
				reverse_rotate_a(stack);
		}
		push_b(stack);
		sort_three_numbers_b(stack);
	}
	while (stack->size_stack_b > 0)
	{
		sort_three_numbers_a(stack);
		push_a(stack);
	}
	stack->nbr_loops++;
}
