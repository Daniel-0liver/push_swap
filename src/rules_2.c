/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 05:28:41 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/11 06:29:25 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_stacks *stack)
{
	int	i;

	i = 0;
    stack->tmp = stack->stack1[0];
	while (i < stack->size_stack_a)
        stack->stack1[i++] = stack->stack1[i + 1];
    stack->stack1[stack->size_stack_a - 1] = stack->tmp;
	write(1, "ra\n", 3);
}

void	rotate_b(t_stacks *stack)
{
	int	i;

	i = 0;
    if (stack->size_stack_b > 0)
	{
		stack->tmp = stack->stack2[0];
		while (i < stack->size_stack_b)
			stack->stack2[i++] = stack->stack2[i + 1];
		stack->stack2[stack->size_stack_b - 1] = stack->tmp;
		write(1, "rb\n", 3);
	}
}

void	rotate_a_and_b(t_stacks *stack)
{
	rotate_a(stack);
	rotate_b(stack);
	write(1, "rr\n", 3);
}
