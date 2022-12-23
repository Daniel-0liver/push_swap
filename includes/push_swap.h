/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:46:01 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/23 02:22:43 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define SIZE_NBR 20

typedef struct d_stacks
{
	long		*stack_a;
	long		*stack_b;
    long    	 size_stack_a;
    long    	 size_stack_b;
    long		nbr_loops;
    long		size_of_elements;
    long    	 tmp;
    long    	 flag;
	long		count_moves;
	long		is_sorted;
	long		stack_a_is_sorted;
	long		nbr_lowest;
	long		nbr_sec_lowest;
	long		nbr_biggest;
	long		posit_lowest;
	long		posit_sec_lowest;
	long		posit_biggest;
	long		nbr_a_not_sorted;
	long		posit_a_not_sorted;
}              t_stacks;

// libft functions
long	ft_atoi(const char *nptr);
int		ft_isdigit(int c);


// push_swap functions
void	init_stacks(t_stacks *stack, int argc, char **argv);
void    print_stacks(t_stacks *stack);
int		is_duplicated(t_stacks *stack);
void	is_non_number(char **argv);
int		handiling_erros(t_stacks *stack);
void	sa_rra(t_stacks *stack);
void	sa_ra(t_stacks *stack);
void	sb_rrb(t_stacks *stack);
void	sb_rb(t_stacks *stack);
void	is_sorted(t_stacks *stack);
void	stack_a_is_sorted(t_stacks *stack);
void	sort_logic(t_stacks *stack);
void	sort_three_numbers_a(t_stacks *stack);
void	sort_three_numbers_b(t_stacks *stack);
void	sort_five_numbers(t_stacks *stack);
void	find_biggest_nbr(t_stacks *stack);
void	find_biggest_nbr_b(t_stacks *stack);
void	find_lowest_nbr(t_stacks *stack);
void	find_second_lowest_nbr(t_stacks *stack);
void	free_stack(t_stacks *stack);

// commands
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

#endif