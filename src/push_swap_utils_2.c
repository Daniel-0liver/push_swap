/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:52:22 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/25 23:12:38 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

void	is_non_number(char **argv, t_stacks *stack)
{
	int	j;

	stack->i = 1;
	while (argv[stack->i])
	{
		j = 0;
		while ((ft_isdigit(argv[stack->i][j])) == 1 && argv[stack->i][j])
			j++;
		if ((argv[stack->i][j] == '-' || argv[stack->i][j] == '+') && (ft_isdigit(argv[stack->i][j + 1])))
		{
			j++;
			while ((ft_isdigit(argv[stack->i][j]) == 1))
				j++;
		}
		if (argv[stack->i][j] && ft_isdigit(argv[stack->i][j]) == 0)
		{
			free(stack->stack_a);
			stack->stack_a = NULL;
			write(STDERR_FILENO,"Error\n", 6);
			exit(-1);
		}
		stack->i++;
	}
}

void	find_biggest_nbr(t_stacks *stack)
{
	int	i;

	i = 0;
	stack->nbr_biggest = stack->stack_a[0];
	stack->nbr_biggest = 0;
	while (i < (stack->size_stack_a - 1) && stack->size_stack_a > 0)
	{
		if (stack->stack_a[i] >= stack->nbr_biggest)
		{
			stack->nbr_biggest = stack->stack_a[i];
			stack->posit_biggest = i;
		}
		i++;
	}
}

void	stack_a_is_sorted(t_stacks *stack)
{
	int	i;

	i = 0;
	while (i < (stack->size_stack_a - 1))
	{
		if (stack->stack_a[i] < stack->stack_a[i + 1])
			stack->stack_a_is_sorted = 0;
		else
		{
			stack->stack_a_is_sorted = 1;
			stack->nbr_a_not_sorted = stack->stack_a[i];
			stack->posit_a_not_sorted = i;
			return ;
		}
		i++;
	}
}

void	find_biggest_nbr_b(t_stacks *stack)
{
	int	i;

	i = 0;
	stack->nbr_biggest = stack->stack_b[0];
	stack->posit_biggest = 0;
	while (i < (stack->size_stack_b) && stack->size_stack_b > 0)
	{
		if (stack->stack_b[i] >= stack->nbr_biggest)
		{
			stack->nbr_biggest = stack->stack_b[i];
			stack->posit_biggest = i;
		}
		i++;
	}
}