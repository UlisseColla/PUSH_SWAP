/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_efficiency.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:02:09 by aconciar          #+#    #+#             */
/*   Updated: 2024/01/18 15:08:54 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_stack *stack)
{
	int	min_value;
	int	current_value;

	min_value = INT_MAX;
	while (stack)
	{
		current_value = stack->index;
		if (current_value < min_value)
			min_value = current_value;
		stack = stack->next;
	}
	return (min_value);
}

void	ra_rra_counter_b(t_stack *stack_b, int index, t_operator **value)
{
	int	moves;
	int stack_size;

	stack_size = ft_list_size(stack_b);
	moves = 0;
	if ((index > find_biggest(stack_b) && find_biggest(stack_b) == stack_b->index) 
		|| (index < find_smallest(stack_b) && find_smallest(stack_b) == ft_list_last(stack_b)->index))
	{
		(*value)->rrb = 0;
		(*value)->rb = 0;
		return ;
	}
	if (index < find_smallest(stack_b))
	{
		while (stack_b->next && stack_b->index != find_smallest_after_index(stack_b, index))
		{
			moves++;
			stack_b = stack_b->next;
		}
		if (stack_b->index == find_smallest_after_index(stack_b, index))
		{
			moves++;
			stack_b = stack_b->next;
		}
	}
	else
	{
		while (stack_b->next && stack_b->index != find_biggest_before_index(stack_b, index))
		{
			moves++;
			stack_b = stack_b->next;
		}
	}
	(*value)->rrb = stack_size - moves;
	// ft_printf("(*value)->rrb %d\n", (*value)->rrb);
	(*value)->rb = moves;
	// ft_printf("(*value)->rb %d\n", (*value)->rb);
}

void	ra_rra_counter_a(t_stack *stack_a, int index, t_operator **value)
{
	int	moves;
	int stack_size;

	stack_size = ft_list_size(stack_a);
	moves = 0;
	while (stack_a->index != index && stack_a->next)
	{
		moves++;
		stack_a = stack_a->next;
	}
	(*value)->rra = stack_size - moves;
	// ft_printf("(*value)->rra %d\n", (*value)->rra);
	(*value)->ra = moves;
	// ft_printf("(*value)->ra %d\n", (*value)->ra);
}

void	efficiency_counter(t_stack *stack_a, t_stack *stack_b, int index, t_operator **value)
{
	int	r_moves = 0;
	int	rr_moves = 0;

	ra_rra_counter_a(stack_a, index, value);
	ra_rra_counter_b(stack_b, index, value);
	if ((*value)->ra < (*value)->rb)
	{
		(*value)->rr = (*value)->ra;
		(*value)->rb -= (*value)->ra;
		(*value)->ra = 0;
	}
	else
	{
		(*value)->rr = (*value)->rb;
		(*value)->ra -= (*value)->rb;
		(*value)->rb = 0;
	}
	if ((*value)->rra < (*value)->rrb)
	{
		(*value)->rrr = (*value)->rra;
		(*value)->rrb -= (*value)->rra;
		(*value)->rra = 0;
	}
	else
	{
		(*value)->rrr = (*value)->rrb;
		(*value)->rra -= (*value)->rrb;
		(*value)->rrb = 0;
	}
	r_moves += (*value)->ra + (*value)->rb + (*value)->rr;
	rr_moves += (*value)->rra + (*value)->rrb + (*value)->rrr;
	// ft_printf("r_moves_save %d\n", r_moves);
	// ft_printf("rr_moves_save %d\n", rr_moves);
	if (r_moves < rr_moves)
	{
		(*value)->rra = 0;
		(*value)->rrb = 0;
		(*value)->rrr = 0;
	}
	else
	{
		(*value)->ra = 0;
		(*value)->rb = 0;
		(*value)->rr = 0;
	}
}

void	check_efficiency(t_stack *stack_a, t_stack *stack_b, int c, t_operator *value)
{
	t_stack	*temp_a;
	t_stack *temp_b;
	int		min_moves;
	int		current_moves;
	int		index_min_value;

	min_moves = INT_MAX;
	temp_a = stack_a;
	temp_b = stack_b;
	while (stack_a)
	{
		if (stack_a->chunk == c)
		{
			// ft_printf("ciclo\n\n\n");
			current_moves = efficiency_counter_no_save(temp_a, temp_b, stack_a->index);
			// ft_printf("current_moves %d\n", current_moves);
			if (current_moves < min_moves)
			{
				min_moves = current_moves;
				index_min_value = stack_a->index;
			}
		}
		// ft_printf("index_min1 %d\n", index_min_value);
		stack_a = stack_a->next;
	}
	// ft_printf("index_min2 %d\n", index_min_value);
	efficiency_counter(temp_a, temp_b, index_min_value, &value);
}
