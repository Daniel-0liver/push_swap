/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:52:22 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/14 23:09:27 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isalpha(int c)
{
	if (!((c >= 'A' && c <= 'Z') || (c
				>= 'a' && c <= 'z')))
	{
		return (1);
	}
	else
		return (0);
}

void	is_non_number(char **argv, t_stacks *stack)
{
	int	i;
	int j;
	int	k;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			k = ft_isalpha(argv[i][j]);
			if (k == 0)
				stack->flag = 1;
			j++;
		}
		i++;
	}
}