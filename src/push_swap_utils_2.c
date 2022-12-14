/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:52:22 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/14 01:31:36 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isalpha(int c)
{
	if (((c >= 'A' && c <= 'Z') || (c
				>= 'a' && c <= 'z')))
	{
		return (0);
	}
	else
		return (1);
}

void	is_non_number(char **argv, t_stacks *stack)
{
	int	i;
	int j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isalpha(argv[i][j]) == 0)
				stack->flag = 2;
			j++;
		}
		i++;
	}
}