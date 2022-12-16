/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 06:14:27 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/16 01:39:30 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate_a(t_stacks *stack)
{
	int	i;

	i = stack->size_stack_a - 1;
	stack->tmp = stack->stack_a[stack->size_stack_a - 1];
	while (i > 0)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->stack_a[0] = stack->tmp;
    if (stack->flag == 0)
	{
    	write(1, "rra\n", 4);
	}
	stack->count_moves++;	
}

void	reverse_rotate_b(t_stacks *stack)
{
	int	i;

    if (stack->size_stack_b > 0)
    {
		i = stack->size_stack_b - 1;
		stack->tmp = stack->stack_b[stack->size_stack_b - 1];
		while (i > 0)
		{
			stack->stack_b[i] = stack->stack_b[i - 1];
			i--;
		}
		stack->stack_b[0] = stack->tmp;
		if (stack->flag == 0)
		{
			write(1, "rrb\n", 4);
		}
		stack->count_moves++;
    }
}

void    reverse_rotate_a_and_b(t_stacks *stack)
{
	stack->flag = 1;
    reverse_rotate_a(stack);
    reverse_rotate_b(stack);
	write(1, "rrr\n", 4);
	stack->flag = 0;
}

void	sb_rrb(t_stacks *stack)
{
	swap_b(stack);
	reverse_rotate_b(stack);
}

void	sb_rb(t_stacks *stack)
{
	swap_b(stack);
	rotate_b(stack);
}