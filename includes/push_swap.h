/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:46:01 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/14 01:20:54 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct d_stacks
{
	int		*stack_a;
	int		*stack_b;
    int     size_stack_a;
    int     size_stack_b;
    int		nbr_random;
    int		size_of_elements;
    int     tmp;
    int     flag;
	int		count_moves;
}              t_stacks;

// libft functions
int		ft_atoi(const char *nptr);
int		ft_isalpha(int c);


// push_swap functions
void	init_stacks(t_stacks *stack, int argc, char **argv);
int		is_duplicated(t_stacks *stack);
void	is_non_number(char **argv, t_stacks *stack);
int		handiling_erros(t_stacks *stack);
void	swap_a(t_stacks *stack);
void	swap_b(t_stacks *stack);
void	swap_a_and_b(t_stacks *stack);
void	push_a(t_stacks *stack);
void	push_b(t_stacks *stack);
void	rotate_a(t_stacks *stack);
void	rotate_b(t_stacks *stack);
void	rotate_a_and_b(t_stacks *stack);
void	reverse_rotate_a(t_stacks *stack);
void	reverse_rotate_b(t_stacks *stack);
void    reverse_rotate_a_and_b(t_stacks *stack);
void	sort_logic(t_stacks *stack);
void	free_stack(t_stacks *stack);

#endif