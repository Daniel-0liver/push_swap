/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:49:41 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/11 23:35:33 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    print_stacks(t_stacks *stack)
{
	int	i;

	i = 0;
    while (i < stack->size_stack_a)
    {
		printf("stack A position %d = %d\n", i, stack->stack1[i]);
		i++;
    }
	puts("");
    i = 0;
    while (i < stack->size_stack_b && stack->size_stack_b != 0)
    {
        printf("stack B position %d = %d\n", i, stack->stack2[i]);
	    i++; 
    }
	puts("");
}

int	is_sorted(t_stacks *stack)
{
	int	i;

	i = 0;
	if (stack->stack2)
	while (stack.)
	{
		/* code */
	}
	
}

void    push_swap(t_stacks *stack)
{
	while ()
	{
		/* code */
	}
	
}

int main(int argc, char **argv)
{
    t_stacks    stack;
	init_stacks(&stack, argc, argv);
	print_stacks(&stack);
	push_b(&stack);
	push_b(&stack);
	push_b(&stack);
	push_a(&stack);
	swap_a(&stack);
	swap_b(&stack);
	swap_a_and_b(&stack);
	print_stacks(&stack);
    printf("Moves = %d\n", stack.count_moves);
	free_stack(&stack);
	return (0);
}