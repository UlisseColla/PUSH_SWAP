/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dll.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:37:03 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/29 12:35:50 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_DLL_H
# define PUSH_SWAP_DLL_H

# include "../libft/libft.h"
# include "../libft/get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

typedef struct t_double_node
{
	int						value;
	int						index;
	bool					has_index;
	bool					push;
	struct t_operations		*ops;
	struct t_double_node	*next;
	struct t_double_node	*prev;
}	t_stack;

typedef struct s_lis
{
	int						length;
	int						index;
	int						lis_index;
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

/* --- Operazioni --- */
void	init_moves(t_stack **node);

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
int		check_order(t_stack *stack);
void	index_stack_init(t_stack **stack);
void	index_push_init(t_stack *stack, int *lis);
void	show_stack(t_stack **stack);
void	push_biggest(t_stack **stack_a, t_stack **stack_b);
int		check_input(char *str);
void	free_mat(char **mat);
// int		arr_find_biggest(int *array);
void	free_mat_long(int **mat);

/* --- Sorting --- */
void	ft_sort_three(t_stack **stack);
void	ft_sort_five(t_stack **stack_a, t_stack **stack_b);
// void	push_in_b(t_stack **stack_a, t_stack **stack_b);
// void	push_in_a(t_stack **a, t_stack **b);

int		find_eff(t_stack *stack, int index);
int		find_value(t_stack *stack, int value);
void	push_a_to_b(t_stack **stack_a, t_stack **stack_b);
void	push_b_to_a(t_stack **stack_a, t_stack **stack_b);
int		find_smallest_after_index(t_stack *stack, int index);
void	efficiency_counter(t_stack *stack_a, t_stack *stack_b, int index, t_operator **value);
int		efficiency_counter_no_save(t_stack *stack_a, t_stack *stack_b, int index);
int		find_smallest_after_index(t_stack *stack, int index);
int		find_biggest_before_index(t_stack *stack, int index);
void	check_efficiency(t_stack *stack_a, t_stack *stack_b, t_operator *value);

/* LIS */
int		*create_array(t_stack *stack, int size);
int		*ft_lis(int *array, int size, int i, int j);
int		*build_array(int *length, int *array, int *sub_sequence, int size);
int		ft_index(int *args, int num);
int		arr_biggest(int *array, int size);

/* TMP */
void ft_list_lis(t_stack **stack, int size);
t_stack	*ft_list_find_index(t_stack *list, int index);
int	*create_sub_array(t_stack *stack, int tail);
void	ft_circular_lis(t_lis **stack_lis);
t_lis	*index_lis_init(t_stack **stack, int size_stack);
t_lis	*ft_last_lis(t_lis *list);
int	*find_best_lis(t_lis **lis, int diff, int tail, int size);
t_lis	*ft_find_in_lis(t_lis **lis, int index, int size);

#endif
