/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 05:28:41 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/17 02:14:30 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_stacks *stack)
{
	int	i;

	i = 0;
	stack->tmp = stack->stack_a[0];
	while (i < (stack->size_stack_a - 1))
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->stack_a[stack->size_stack_a - 1] = stack->tmp;
    if (stack->flag == 0)
	{
    	write(1, "ra\n", 3);
	}
	stack->count_moves++;
}

void	rotate_b(t_stacks *stack)
{
	int	i;

	i = 0;
    if (stack->size_stack_b > 0)
	{
		stack->tmp = stack->stack_b[0];
		while (i < (stack->size_stack_b - 1))
		{
			stack->stack_b[i] = stack->stack_b[i + 1];
			i++;
		}
		stack->stack_b[stack->size_stack_b - 1] = stack->tmp;
        if (stack->flag == 0)
		{
	    	write(1, "rb\n", 3);
		}
		stack->count_moves++;
	}
}

void	rotate_a_and_b(t_stacks *stack)
{
    stack->flag = 1;
	rotate_a(stack);
	rotate_b(stack);
	write(1, "rr\n", 3);
    stack->flag = 0;
}

void	sa_rra(t_stacks *stack)
{
	swap_a(stack);
	reverse_rotate_a(stack);
}

void	sa_ra(t_stacks *stack)
{
	swap_a(stack);
	rotate_a(stack);
}