/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:05:05 by aconciar          #+#    #+#             */
/*   Updated: 2024/01/23 18:14:24 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_eff(t_stack *stack, int index)
{
	int i;

	i = 0;
	while (stack)
	{
		if (stack->index == index)
			return (i);
		stack = stack->next;
		i++;
	}
	return(-1);
}

void	push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_operator operator;

	check_efficiency(*stack_a, *stack_b, &operator);
	while (operator.rr > 0)
	{
		rr(stack_a, stack_b);
		operator.rr--;
	}
	while (operator.rrr > 0)
	{
		rrr(stack_a, stack_b);
		operator.rrr--;
	}
	while (operator.ra > 0)
	{
		ra(stack_a);
		operator.ra--;
	}
	while (operator.rb > 0)
	{
		rb(stack_b);
		operator.rb--;
	}
	while (operator.rra > 0)
	{
		rra(stack_a);
		operator.rra--;
	}
	while (operator.rrb > 0)
	{
		rrb(stack_b);
		operator.rrb--;
	}
	pb(stack_b, stack_a);
	if ((*stack_b)->index == find_smallest(*stack_b))
		rb(stack_b);
}

void	push_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_b)->index > find_biggest(*stack_a) || (*stack_b)->index < find_smallest(*stack_a))
		while (ft_list_last(*stack_a)->index != find_biggest(*stack_a))
		{
			if (find_eff(*stack_a, find_biggest(*stack_a)) > (ft_list_size(*stack_a) / 2))
				rra(stack_a);
			else
				ra(stack_a);
		}
	else
	{
		if (find_value(*stack_a, (*stack_b)->index + 1) == 1)
			while ((*stack_a)->index != (*stack_b)->index + 1)
			{
				if (find_eff(*stack_a, (*stack_b)->index + 1) > (ft_list_size(*stack_a) / 2))
					rra(stack_a);
				else
					ra(stack_a);
			}
		else
			while ((*stack_b)->index > (*stack_a)->index)
			{
				if (find_eff(*stack_a, find_biggest_before_index(*stack_a, (*stack_b)->index)) > (ft_list_size(*stack_a) / 2))
					rra(stack_a);
				else
					ra(stack_a);
			}
	}
	pa(stack_a, stack_b);
}

void	sorting(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_b, stack_a);
	pb(stack_b, stack_a);
	while (ft_list_size(*stack_a) > 3)
		push_a_to_b(stack_a, stack_b);
	three_numbers_a(stack_a);
	while ((*stack_b)->next)
		push_b_to_a(stack_a, stack_b);
	push_b_to_a(stack_a, stack_b);
	while((*stack_a)->index != find_smallest(*stack_a))
	{
		if (find_eff(*stack_a, find_smallest(*stack_a)) > (ft_list_size(*stack_a) / 2))
			rra(stack_a);
		else
			ra(stack_a);
	}
}
