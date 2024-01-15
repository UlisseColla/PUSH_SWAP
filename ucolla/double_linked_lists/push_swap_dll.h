/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dll.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:37:03 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/15 17:36:06 by ucolla           ###   ########.fr       */
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
	struct t_double_node	*next;
	struct t_double_node	*prev;
}	t_stack;

/* Funzioni base --> lib_dll */
t_stack	*ft_create_node(int value);
t_stack	*ft_create_list(char *str_args);
t_stack	*ft_list_last(t_stack *list);
t_stack	*ft_list_find_node(t_stack *list, int value);
void	ft_free_list(t_stack *list);
void	ft_list_addfront(t_stack **list, t_stack *new);
void	ft_list_addback(t_stack **list, t_stack *new);
int		ft_list_size(t_stack *list);

/* --- Operazioni --- */

/* Push */
void	push_a(t_stack **stack, t_stack **node);
void	push_b(t_stack **stack, t_stack **node);

/* Swap */
void	swap_a(t_stack **stack);
void	swap_b(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);

/* Rotate */
void	rotate_a(t_stack **stack);
void	rotate_b(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);

/* Reverse rotate */
void	reverse_rotate_a(t_stack **stack);
void	reverse_rotate_b(t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);

/* --- Logica --- */

/* Utils */
int		find_smallest(t_stack **stack);
int		find_biggest(t_stack **stack);
int		check_order(t_stack *stack);
void	index_stack_init(t_stack **stack);
void	show_stack(t_stack **stack);
void	push_biggest(t_stack **stack_a, t_stack **stack_b);
int		check_input(char *str);
void	free_mat(char **mat);
int		arr_find_biggest(int *array);

/* --- Sorting --- */
void	ft_sort_three(t_stack **stack);
void	ft_sort_five(t_stack **stack_a, t_stack **stack_b);

/* Trova sequenza piu' lunga */
long	find_index(long *args, long num);
long	*find_longest_path(long *args, long num, long i);
long	find_next_smaller(long *args, long num, long index);
long	*create_array(t_stack *stack);
long	*ret_longest_array(long *array);
long	array_size(long *array);
void	free_mat_long(long **mat);

#endif
