/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 23:43:53 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/17 02:14:23 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    swap_a(t_stacks *stack)
{
	int tmp;

	tmp = stack->stack_a[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_a[1] = tmp;
    if (stack->flag == 0)
	{
	    write(1, "sa\n", 3);
	}
	stack->count_moves++;
}

void    swap_b(t_stacks *stack)
{
	stack->tmp = stack->stack_b[0];
	stack->stack_b[0] = stack->stack_b[1];
	stack->stack_b[1] = stack->tmp;
    if (stack->flag == 0)
	{
	    write(1, "sb\n", 3);
	}
	stack->count_moves++;
}

void    swap_a_and_b(t_stacks *stack)
{
    stack->flag = 1;
	swap_a(stack);
	swap_b(stack);
    write(1, "ss\n", 3);
    stack->flag = 0;
	stack->count_moves++;
}

void    push_a(t_stacks *stack)
{
	int i;

	i = stack->size_stack_a;
	if (stack->size_stack_b > 0)
	{
		while (i > 0)
		{
			stack->stack_a[i] = stack->stack_a[i - 1];
			i--;
		}
		stack->stack_a[0] = stack->stack_b[0];
		stack->size_stack_a++;
		stack->size_stack_b--;
		if (stack->size_stack_b > 0)
		{
			i = 0;
			while (i < stack->size_stack_b)
			{
				stack->stack_b[i] = stack->stack_b[i + 1];
				i++;
			}
			stack->stack_b[stack->size_stack_b] = 0;
		}
        write(1, "pa\n", 3);
		stack->count_moves++;
	}
}

void	push_b(t_stacks *stack)
{
	int	i;

	i = stack->size_stack_b;
	if (stack->size_stack_a > 0)
	{
		while (i > 0)
		{
			stack->stack_b[i] = stack->stack_b[i - 1];
			i--;
		}
		stack->stack_b[0] = stack->stack_a[0];
		stack->size_stack_a--;
		stack->size_stack_b++;
		if (stack->size_stack_b > 0)
		{
			i = 0;
			while (i < stack->size_stack_a)
			{
				stack->stack_a[i] = stack->stack_a[i + 1];
				i++;
			}
			stack->stack_a[stack->size_stack_a] = 0;
		}
        write(1, "pb\n", 3);
		stack->count_moves++;
	}
}
