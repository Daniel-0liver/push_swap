/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:52:22 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/23 12:57:59 by dateixei         ###   ########.fr       */
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

void	is_non_number(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while ((ft_isdigit(argv[i][j])) == 1 && argv[i][j])
			j++;
		if ((argv[i][j] == '-' || argv[i][j] == '+') && (ft_isdigit(argv[i][j + 1])))
		{
			j++;
			while ((ft_isdigit(argv[i][j]) == 1))
				j++;
		}
		if (argv[i][j] && ft_isdigit(argv[i][j]) == 0)
		{
			write (2, "Error\n", 6);
			exit (-1);
		}
		i++;
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

void	find_lowest_nbr(t_stacks *stack)
{
	int	i;

	i = 0;
	stack->nbr_lowest = stack->stack_a[0];
	stack->posit_lowest = 0;
	while (i < (stack->size_stack_a - 1) && stack->size_stack_a > 0)
	{
		if (stack->stack_a[i] <= stack->nbr_lowest)
		{
			stack->nbr_lowest = stack->stack_a[i];
			stack->posit_lowest = i;
		}
		i++;
	}
}

void	find_second_lowest_nbr(t_stacks *stack)
{
	long	i;
	long	j;
	long 	k;
	long 	nbr_count[SIZE_NBR];
	long 	posit_count[SIZE_NBR];

	find_lowest_nbr(stack);
	find_biggest_nbr(stack);
	nbr_count[0] = stack->nbr_lowest;
	posit_count[0] = stack->posit_lowest;
	j = 1;
	i = 0;
	while (j < SIZE_NBR)
		nbr_count[j++] = stack->nbr_biggest;
	k = 1;
	while (k < SIZE_NBR && stack->size_stack_a > 1)
	{
		stack->nbr_lowest = stack->nbr_biggest;
		stack->posit_lowest = stack->posit_biggest;
		i = 0;
		while (i < stack->size_stack_a)
		{
			j = 0;
			while (j < SIZE_NBR)
			{
				if (stack->stack_a[i] > nbr_count[k - 1] && stack->stack_a[i] < stack->nbr_lowest)
				{
					stack->nbr_lowest = stack->stack_a[i];
					stack->posit_lowest = i;
				}
				j++;
			}
			i++;
		}
		nbr_count[k] = stack->nbr_lowest;
		posit_count[k] = stack->posit_lowest;
		k++;
	}
	k = 0;
	j = 0;
	if ((stack->size_stack_a - posit_count[k]) < posit_count[k])
		i = stack->size_stack_a - posit_count[k];
	else
		i = posit_count[k];
	while (k < SIZE_NBR)
	{
		if ((stack->size_stack_a - posit_count[k]) < posit_count[k] && (stack->size_stack_a - posit_count[k]) < i)
		{
			i = stack->size_stack_a - posit_count[k];
			j = k;
		}
		else if (posit_count[k] < i)
		{
			i = posit_count[k];
			j = k;
		}
		k++;
	}
	if (stack->size_stack_a > SIZE_NBR)
	{
		stack->nbr_lowest = nbr_count[j];
		stack->posit_lowest = posit_count[j];
	}
	else 
		find_lowest_nbr(stack);
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