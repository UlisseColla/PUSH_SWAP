/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:13:37 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/02 19:35:34 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_push(t_stack *stack, int push_value)
{
	int i;

	i = 0;
	while (stack)
	{
		if (stack->push == push_value)
			return (i);
		stack = stack->next;
		i++;
	}
	return(-1);
}

void	push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_a)->push != 0)
	{
		if (find_push(*stack_a, 0) > (ft_list_size(stack_a) / 2))
			rra(stack_a);
		else
			ra(stack_a);
	}
	if ((*stack_a)->chunk == 2)
		pb(stack_b, stack_a);
	else
	{
		pb(stack_b, stack_a);
		if (ft_list_size(stack_b) > 1)
			rb(stack_b);
	}
}
