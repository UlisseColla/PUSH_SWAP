/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:03:33 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/01 18:43:42 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_value(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->index == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	check_order(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (tmp->next == NULL)
		return (1);
	while (tmp)
	{
		if (tmp->value < tmp->next->value && tmp->next)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

void	show_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!(*stack))
		ft_printf("Empty stack\n\n");
	tmp = *stack;
	while (tmp)
	{
		printf("stack: %d, value: %d, push: %d\n", tmp->index, tmp->value, tmp->push);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

/* int	find_smallest(t_stack *stack)
{
	int		min_value;
	int		current_value;
	t_stack	*tmp;

	min_value = INT_MAX;
	tmp = stack;
	while (tmp)
	{
		current_value = tmp->value;
		if (current_value < min_value)
			min_value = current_value;
		tmp = tmp->next;
	}
	return (min_value);
} */

/* int	find_biggest(t_stack *stack)
{
	int		max_value;
	int		current_value;
	t_stack	*tmp;

	max_value = INT_MIN;
	tmp = stack;
	while (tmp)
	{
		current_value = tmp->value;
		if (current_value > max_value)
			max_value = current_value;
		tmp = tmp->next;
	}
	return (max_value);
} */
