/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:49:41 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/14 23:44:32 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    print_stacks(t_stacks *stack)
{
	int	i;

	i = 0;
    while (i < stack->size_stack_a)
    {
		printf("stack A position %d = %d\n", i, stack->stack_a[i]);
		i++;
    }
	puts("");
    i = 0;
    while (i < stack->size_stack_b && stack->size_stack_b != 0)
    {
        printf("stack B position %d = %d\n", i, stack->stack_b[i]);
	    i++; 
    }
	puts("");
}

int	is_sorted(t_stacks *stack)
{
	int	i;

	i = 0;
	if (stack->size_stack_b == 0)
	{
		while (i < (stack->size_of_elements - 1))
		{
			if (stack->stack_a[i] > stack->stack_a[i + 1])
				return (1);
			i++;
		}
	}
	return (0);
}

void    push_swap(t_stacks *stack)
{
	int i;

	i = is_sorted(stack);
	printf("%d", i);
	if (i == 1)
	{
		while (i == 1)
		{	
			rotate_a(stack);
			print_stacks(stack);
			i = is_sorted(stack);
			// sort_logic(stack);
		}
	}
}

int main(int argc, char **argv)
{
    t_stacks    stack;

	if (argc <= 2)
		return (0);
	init_stacks(&stack, argc, argv);
	if (handiling_erros(&stack) == 1)
		return (0);
	print_stacks(&stack);
	push_swap(&stack);
	free_stack(&stack);
	return (0);
}