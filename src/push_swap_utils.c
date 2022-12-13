/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 23:45:56 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/13 01:30:26 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    init_stacks(t_stacks *stack, int argc, char **argv)
{
	int	i;

    stack->flag = 0;
	stack->count_moves = 0;
	stack->size_of_elements = (argc -1);
    stack->size_stack_a = stack->size_of_elements;
    stack->size_stack_b = 0;
	stack->stack_a = (int*) malloc(stack->size_of_elements * sizeof(int));
	i = 0;
	while (i < stack->size_of_elements)
		stack->stack_a[i++] = ft_atoi(argv[i + 1]);
	if (stack->size_of_elements > 1)
		stack->stack_b = (int*) malloc(stack->size_of_elements * sizeof(int));
}

void	free_stack(t_stacks *stack)
{
	free(stack->stack_a);
	stack->stack_a = NULL;
	if (stack->stack_b)
	{
		free(stack->stack_b);
		stack->stack_b = NULL;
	}
}

int	is_duplicated(t_stacks *stack)
{
	int	i;
	int	j;

	i = 0;
	while (stack->stack_a[i])
	{
		j = i + 1;
		while (stack->stack_a[j])
		{
			if (stack->stack_a[i] == stack->stack_a[j])
			{
				write(2,"Error\n", 6);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	sing;

	i = 0;
	sing = 1;
	result = 0;
	while (nptr[i] && (nptr[i] == '\f' || nptr[i] == ' ' || nptr[i] == '\n'
			|| nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v'))
		i++;
	if (nptr[i] && (nptr[i] == '-' || nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sing *= -1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sing);
}
