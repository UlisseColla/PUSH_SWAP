/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:39:39 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/01 18:39:17 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_lis
{
	int						length;
	int						index;
	int						lis_index;
	int						sub_sequence;
	bool					has_index;
	struct s_lis			*next;
}				t_lis;

typedef struct s_operator
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	rr;
	int	rrr;
}				t_operator;

typedef struct s_stack
{
	int						value;
	int						index;
	int						has_index;
	int						chunk;
	int						push;
	struct s_stack			*next;
	struct s_stack			*prev;
}				t_stack;

void	ft_print_stack(t_stack *stack);
t_stack	*ft_create_node(int value);
t_stack	*ft_create_list(int argc, char **argv);
t_stack	*ft_list_last(t_stack *list);
void	ft_free_list(t_stack *list);
void	ft_list_addfront(t_stack **list, t_stack *new);
void	ft_list_addback(t_stack **list, t_stack *new);
t_stack	*ft_list_find_node(t_stack *list, int value);
int		ft_list_size(t_stack *list);
int		check_input(char *str);
int		stack_init(int	argc, char *argv[], t_stack **stack_a);
t_lis	*index_lis_init(t_stack **stack, int size_stack);
int		*ft_circular_lis(t_lis **stack_lis, int stack_size);
int		find_biggest_length(t_lis *lis, int size);
t_lis	*find_biggest_length_node(t_lis *lis, int size, int length_to_search);
t_lis	*ft_node_lis(int index);
void	ft_addback_lis(t_lis **list, t_lis *new);
t_lis	*ft_last_lis(t_lis *list);
t_lis	*ft_find_in_lis(t_lis **lis, int index, int size);
t_lis	*ft_find_lis_index(t_lis **lis, int lis_index, int size);
int		*build_lis(t_lis **lis, int size);
void	pa(t_stack **stack, t_stack **node);
void	pb(t_stack **stack, t_stack **node);
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rbb(t_stack **stack);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);
int		check_input(char *str);
int		check_order(t_stack *stack);
void	free_mat(char **mat);
char	*ft_strjoingnl(char *left_str, char *buff);
void	two_numbers_a (t_stack **stack_a);
void	two_numbers_b(t_stack **stack_b);
void	three_numbers_a(t_stack **stack_a);
void	three_numbers_b(t_stack **stack_b);
void	five_numbers(t_stack **stack_a, t_stack **stack_b);
void	sorting(t_stack **stack_a, t_stack **stack_b);
void	push_a_to_b(t_stack **stack_a, t_stack **stack_b);
void	push_b_to_a(t_stack **stack_a, t_stack **stack_b);
void	index_init(t_stack **stack);
void	check_efficiency(t_stack *stack_a, t_stack *stack_b, t_operator *value);
int		efficiency_counter_no_save(t_stack *stack_a, t_stack *stack_b, int index);
int		find_biggest(t_stack *stack);
int		find_smallest(t_stack *stack);
int		find_biggest_before_index(t_stack *stack, int index);
int		find_smallest_after_index(t_stack *stack, int index);
int		find_value(t_stack *stack, int value);
int		find_eff(t_stack *stack, int index);

#endif
