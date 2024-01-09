/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:03:33 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/09 14:33:27 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dll.h"

int	find_smallest(t_stack **stack)
{
	int		min_value;
	int		current_value;
	t_stack	*tmp;

	min_value = INT_MAX;
	tmp = *stack;
	while (tmp)
	{
		current_value = tmp->value;
		if (current_value < min_value)
			min_value = current_value;
		tmp = tmp->next;
	}
	return (min_value);
}

int	find_biggest(t_stack **stack)
{
	int		max_value;
	int		current_value;
	t_stack	*tmp;

	max_value = INT_MIN;
	tmp = *stack;
	while (tmp)
	{
		current_value = tmp->value;
		if (current_value > max_value)
			max_value = current_value;
		tmp = tmp->next;
	}
	return (max_value);
}

int	check_order(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value < stack->next->value)
			stack = stack->next;
		else
			return (0);
	}
	if (stack->value > stack->prev->value)
		return (1);
	return (0);
}
