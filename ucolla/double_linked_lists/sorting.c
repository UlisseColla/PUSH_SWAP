/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:05:05 by aconciar          #+#    #+#             */
/*   Updated: 2024/01/29 12:31:02 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dll.h"

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

void	sorting(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_b, stack_a);
	pb(stack_b, stack_a);
	while (ft_list_size(stack_a) > 3)
		push_a_to_b(stack_a, stack_b);
	// three_numbers_a(stack_a);
	ft_sort_three(stack_a);
	while ((*stack_b)->next)
		push_b_to_a(stack_a, stack_b);
	push_b_to_a(stack_a, stack_b);
	while((*stack_a)->index != find_smallest(*stack_a))
	{
		if (find_eff(*stack_a, find_smallest(*stack_a)) > (ft_list_size(stack_a) / 2))
			rra(stack_a);
		else
			ra(stack_a);
	}
}
