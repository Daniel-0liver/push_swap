/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 23:45:56 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/25 23:04:17 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	ft_atoi(const char *nptr, t_stacks *stack)
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
	if ((result * sig) > 2147483647 || (result * sig) < -2147483648)
		free_stack(stack);
	return (result * sig);
}

void    init_stacks(t_stacks *stack, int argc, char **argv)
{
	stack->flag = 0;
	stack->count_moves = 0;
	stack->size_of_elements = (argc -1);
	stack->size_stack_a = stack->size_of_elements;
	stack->size_stack_b = 0;
	stack->stack_a = (int*) malloc(stack->size_of_elements * sizeof(int));
	is_non_number(argv, stack);
	stack->i = 0;
	while (stack->i < stack->size_of_elements)
	{
		stack->stack_a[stack->i] = ft_atoi(argv[stack->i + 1], stack);
		stack->i++;
	}
	if (stack->size_of_elements == 1)
	{
		write(STDOUT_FILENO, "\n", 1);
		free(stack->stack_a);
		exit(1);
	}
	if (stack->size_of_elements > 1)
		stack->stack_b = (int*) malloc(stack->size_of_elements * sizeof(int));
}

void	handiling_erros(t_stacks *stack)
{
	if (stack->size_of_elements == 2)
	{
		if (stack->stack_a[0] > stack->stack_a[1])
			swap_a(stack);
		else
			write(STDOUT_FILENO, "\n", 1);
		free(stack->stack_a);
		stack->stack_a = NULL;
		free(stack->stack_b);
		stack->stack_b = NULL;
		exit(1);
	}
	is_duplicated(stack);
	if (stack->flag == 1)
		free_stack(stack);
}

void	is_duplicated(t_stacks *stack)
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
				free_stack(stack);
			j++;
		}
		i++;
	}
}

void	free_stack(t_stacks *stack)
{
	free(stack->stack_a);
	stack->stack_a = NULL;
	free(stack->stack_b);
	stack->stack_b = NULL;
	write(STDERR_FILENO,"Error\n", 6);
	exit(-1);
}