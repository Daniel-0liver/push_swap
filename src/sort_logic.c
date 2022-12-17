/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 23:52:42 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/17 01:25:13 by dateixei         ###   ########.fr       */
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

void	find_biggest(t_stacks *stack)
{
	int	i;

	i = 0;
	stack->nbr_biggest = stack->stack_a[0];
	while (i < stack->size_stack_a -1)
	{
		if (stack->stack_a[i] <= stack->nbr_biggest)
			stack->nbr_biggest = stack->stack_a[i];
		i++;
	}
}

void	sort_logic(t_stacks *stack)
{
	while (stack->stack_a)
	{
		/* code */
	}
	
}
