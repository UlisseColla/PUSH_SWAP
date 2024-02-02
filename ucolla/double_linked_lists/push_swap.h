/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:37:03 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/01 17:34:22 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./libft/get_next_line/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

typedef struct t_double_node
{
	int						value;
	int						index;
	int						push;
	bool					has_index;
	struct t_double_node	*next;
	struct t_double_node	*prev;
}	t_stack;

typedef struct s_lis
{
	int						length;
	int						index;
	int						lis_index;
	int						sub_sequence;
	bool					has_index;
	struct s_lis			*next;
}	t_lis;

typedef struct s_operator
{
	int	sa;
	int	sb;
	int	ss;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_operator;

/* Funzioni base --> lib_dll */
t_stack	*ft_create_node(int value);
t_stack	*ft_create_list(char *str_args);
t_stack	*ft_list_last(t_stack *list);
t_stack	*ft_list_find_node(t_stack *list, int value);
void	ft_free_list(t_stack *list);
void	ft_list_addfront(t_stack **list, t_stack *new);
void	ft_list_addback(t_stack **list, t_stack *new);
int		ft_list_size(t_stack **list);

/* Push */
void	pa(t_stack **stack, t_stack **node);
void	pb(t_stack **stack, t_stack **node);
/* Swap */
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);
/* Rotate */
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);
/* Reverse rotate */
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);

/* --- Logica --- */

/* Utils */
int		find_smallest(t_stack *stack);
int		find_biggest(t_stack *stack);
void	push_smallest(t_stack **stack_a, t_stack **stack_b);
int		check_order(t_stack **stack);
void	index_stack_init(t_stack **stack);
void	index_push_init(t_stack *stack, int *lis);
void	show_stack(t_stack **stack);
int		check_input(char *str);
void	free_mat(char **mat);

/* initialize_stack */
int		initialize_stack(t_stack **stack, char **argv, int argc);
int		*find_longest_lis(t_lis **lis, int list_size, int counter, int current_value);
char	*ft_strjoin_ps(char *s1, char *s2);

/* --- Sorting --- */
void	ft_three_numbers(t_stack **stack_a);
void	ft_five_numbers(t_stack **stack_a, t_stack **stack_b);
void	sorting(t_stack **stack_a, t_stack **stack_b);
int		find_eff(t_stack *stack, int index);
int		find_value(t_stack *stack, int value);
void	push_a_to_b(t_stack **stack_a, t_stack **stack_b);
void	push_b_to_a(t_stack **stack_a, t_stack **stack_b);
void	efficiency_counter(t_stack *stack_a, t_stack *stack_b, int index, t_operator **value);
int		efficiency_counter_no_save(t_stack *stack_a, t_stack *stack_b, int index);
int		find_smallest_after_index(t_stack *stack, int index);
int		find_biggest_before_index(t_stack *stack, int index);
void	check_efficiency(t_stack *stack_a, t_stack *stack_b, t_operator *value);

/* LIS CIRCOLARE */

/* circular_lis_utils */
t_lis	*ft_node_lis(int index);
t_lis	*ft_last_lis(t_lis *list);
t_lis	*ft_find_in_lis(t_lis **lis, int index, int size);
t_lis	*ft_find_lis_index(t_lis **lis, int lis_index, int size);
void	ft_addback_lis(t_lis **list, t_lis *new);
/* lis_utils */
t_lis	*find_biggest_length_node(t_lis *lis, int size, int length_to_search);
int		find_biggest_length(t_lis *lis, int size);
void	ft_free_lis(t_lis *lis, int head_lis);
/* circular_list */
t_lis	*index_lis_init(t_stack **stack, int size_stack);
void	refresh_lis(t_lis **lis, int stack_size);
int		*ft_circular_lis(t_lis **stack_lis, int stack_size);
int		*build_lis(t_lis **lis, int size);

/* TMP */
void 	ft_list_lis(t_stack **stack, int size);
t_stack	*ft_list_find_index(t_stack *list, int index);
int		*create_sub_array(t_stack *stack, int tail);
int		*ft_circular_lis(t_lis **stack_lis, int stack_size);
t_lis	*index_lis_init(t_stack **stack, int size_stack);
t_lis	*ft_last_lis(t_lis *list);
int		*find_best_lis(t_lis **lis, int diff, int tail, int size);
t_lis	*ft_find_in_lis(t_lis **lis, int index, int size);
int		*build_lis(t_lis **lis, int size);
int		find_biggest_length(t_lis *lis, int size);
t_lis	*find_biggest_length_node(t_lis *lis, int size, int length_to_search);

#endif
