/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:49:41 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/10 22:11:52 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

int	ft_strlen_int(int *arr)
{
	int count;

	count = 0;
	while (arr[count])
		count++;
	return (count);
}

int main(int argc, char **argv)
{
	int arr[argc];
	int count;
	int tmp;

	count = 0;
	while (count < (argc - 1))
	{
		arr[count] = atoi(argv[count + 1]);
		printf("posi %d = arr[%d]\n", count, arr[count]);
		count++;
	}
	puts("");
	count = 0;
	tmp = arr[0];
	while (count < (argc - 1))
	{
		arr[count] = arr[count + 1];
		count++;
	}
	arr[count - 1] = tmp;
	count = 0;
	while (count < (argc - 1))
	{
		printf("posi %d = arr[%d]\n", count, arr[count]);
		count++;
	}
	
	return (0);
}