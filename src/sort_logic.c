/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 23:52:42 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/23 12:28:23 by dateixei         ###   ########.fr       */
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
