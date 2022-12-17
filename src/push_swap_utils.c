/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 23:45:56 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/17 01:11:52 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	long	result;
	int		sig;

	i = 0;
	sig = 1;
	result = 0;
	while (nptr[i] && (nptr[i] == '\f' || nptr[i] == ' ' || nptr[i] == '\n'
			|| nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v'))
		i++;
	if (nptr[i] && (nptr[i] == '-' || nptr[i] == '+'))
		if (nptr[i++] == '-')
			sig *= -1;
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
		result = result * 10 + (nptr[i++] - '0');
	if ((result * sig) == 2147483648 || (result * sig) == -2147483649)
	{
		write(2,"Error\n", 6);
		exit (1);
	}
	return (result * sig);
}

void    init_stacks(t_stacks *stack, int argc, char **argv)
{
	int	i;

	stack->flag = 0;
	stack->count_moves = 0;
	stack->nbr_loops = 0;
	stack->size_of_elements = (argc -1);
	stack->size_stack_a = stack->size_of_elements;
	stack->size_stack_b = 0;
	stack->stack_a = (int*) malloc(stack->size_of_elements * sizeof(int));
	is_non_number(argv);
	i = 0;
	while (i < stack->size_of_elements)
	{
		stack->stack_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (stack->size_of_elements > 1)
		stack->stack_b = (int*) malloc(stack->size_of_elements * sizeof(int));
}

int	handiling_erros(t_stacks *stack)
{
	if (stack->size_of_elements == 2)
	{
		if (stack->stack_a[0] > stack->stack_a[1])
			swap_a(stack);
		free_stack(stack);
		return (1);
	}
	if (is_duplicated(stack) == 1)
		return (1);
	if (stack->flag == 1)
	{
		write(2,"Error\n", 6);
		return (1);
	}
	return (0);
}

int	is_duplicated(t_stacks *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size_of_elements)
	{
		j = i + 1;
		while (j < stack->size_of_elements)
		{
			if (stack->stack_a[i] == stack->stack_a[j])
			{
				write(2,"Error\n", 6);
				free_stack(stack);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
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