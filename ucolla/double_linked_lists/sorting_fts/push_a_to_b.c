/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:16:48 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/26 15:22:23 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_dll.h"

void	r_operations(t_stack **stack_a, t_stack **stack_b, t_operator operator)
{
	while (operator.rr > 0)
	{
		rr(stack_a, stack_b);
		operator.rr--;
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
}

void	rr_operations(t_stack **stack_a, t_stack **stack_b, t_operator operator)
{
	while (operator.rrr > 0)
	{
		rrr(stack_a, stack_b);
		operator.rrr--;
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
}

void	push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_operator operator;

	// check_efficiency(*stack_a, *stack_b, &operator);
	r_operations(stack_a, stack_b, operator);
	rr_operations(stack_a, stack_b, operator);
	pb(stack_b, stack_a);
	if ((*stack_b)->index == find_smallest(*stack_b))
		rb(stack_b);
}