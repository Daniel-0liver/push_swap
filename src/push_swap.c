/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:49:41 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/11 06:30:30 by dateixei         ###   ########.fr       */
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

int main(int argc, char **argv)
{
    t_stacks    stack;
	init_stacks(&stack, argc, argv);
	// print_stacks(&stack);
    push_b(&stack);
    push_b(&stack);
    push_b(&stack);
    push_b(&stack);
    // print_stacks(&stack);
    reverse_rotate_b(&stack);
    // print_stacks(&stack);
    reverse_rotate_a_and_b(&stack);
    // print_stacks(&stack);
	return (0);
}