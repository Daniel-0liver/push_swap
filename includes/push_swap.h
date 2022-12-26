/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:46:01 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/26 00:39:33 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_stacks
{
	int			i;
	int			*stack_a;
	int			*stack_b;
    int	    	size_stack_a;
    int	    	size_stack_b;
    int			size_of_elements;
    int	    	tmp;
    int	    	flag;
	int			count_moves;
	int			is_sorted;
	int			stack_a_is_sorted;
	int			nbr_lowest;
	int			nbr_lowest_by_size;
	int			nbr_biggest;
	int			posit_lowest;
	int			posit_sec_lowest;
	int			posit_biggest;
	int			nbr_a_not_sorted;
	int			posit_a_not_sorted;
}              t_stacks;

typedef struct s_low
{
	int		i;
	int		j;
	int		k;
	int		*nbr_count;
	int		*posit_count;
}				t_low;


// libft functions
int		ft_atoi(const char *nptr, t_stacks *stack);
int		ft_isdigit(int c);


// push_swap functions
void	init_stacks(t_stacks *stack, int argc, char **argv);
void    print_stacks(t_stacks *stack);
void	is_duplicated(t_stacks *stack);
void	is_non_number(char **argv, t_stacks *stack);
void	handiling_erros(t_stacks *stack);
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
void	find_x_lowest_nbr(t_stacks *stack);
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