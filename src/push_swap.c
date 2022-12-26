/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:49:41 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/26 02:55:35 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void	print_stacks(t_stacks *stack)
// {
// 	int	i;

// 	i = 0;
// 	while (i < stack->size_stack_a)
// 	{
// 		printf("stack A position %d = %d\n", i, stack->stack_a[i]);
// 		i++;
// 	}
// 	puts("");
// 	i = 0;
// 	while (i < stack->size_stack_b && stack->size_stack_b != 0)
// 	{
// 		printf("stack B position %d = %d\n", i, stack->stack_b[i]);
// 		i++;
// 	}
// 	puts("");
// }

void	is_sorted(t_stacks *stack)
{
	int	i;

	i = 0;
	if (stack->size_stack_b == 0)
	{
		while (i < (stack->size_of_elements - 1))
		{
			if (stack->stack_a[i] < stack->stack_a[i + 1])
				stack->is_sorted = 0;
			else
			{
				stack->is_sorted = 1;
				return ;
			}
			i++;
		}
	}
}

void	push_swap(t_stacks *stack)
{
	is_sorted(stack);
	if (stack->is_sorted == 1 && stack->size_of_elements == 3)
		sort_three_numbers_a(stack);
	is_sorted(stack);
	if (stack->size_of_elements > 3 && stack->size_of_elements
		<= 9 && stack->is_sorted == 1)
		sort_five_numbers(stack);
	is_sorted(stack);
	if (stack->is_sorted == 1)
	{
		if (stack->size_of_elements > 9 && stack->size_of_elements < 110)
			stack->nbr_lowest_by_size = 8;
		else
			stack->nbr_lowest_by_size = 20;
		while (stack->is_sorted == 1)
		{
			sort_logic(stack);
			is_sorted(stack);
		}
	}
}

int	main(int argc, char **argv)
{
	t_stacks	stack;

	if (argc <= 1)
		return (0);
	init_stacks(&stack, argc, argv);
	handiling_erros(&stack);
	push_swap(&stack);
	free(stack.stack_a);
	stack.stack_a = NULL;
	free(stack.stack_b);
	stack.stack_b = NULL;
	return (0);
}
