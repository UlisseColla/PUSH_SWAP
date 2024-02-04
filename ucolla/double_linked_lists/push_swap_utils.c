/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:03:33 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/04 17:59:33 by ucolla           ###   ########.fr       */
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
		printf("stack: %d, chunk: %d\n", tmp->value, tmp->chunk);
		tmp = tmp->next;
	}
	ft_printf("\n");
}
