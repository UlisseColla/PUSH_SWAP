/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:26:15 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/10 18:55:10 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dll.h"

static int	index_find_smallest(t_stack **stack)
{
	int		min_value;
	int		current_value;
	t_stack	*tmp;

	min_value = INT_MAX;
	tmp = *stack;
	while (tmp)
	{
		current_value = tmp->value;
		if (current_value < min_value && tmp->has_index == false)
			min_value = current_value;
		tmp = tmp->next;
	}
	return (min_value);
}

void	index_stack_init(t_stack **stack)
{
	int		i;
	int		smallest;
	t_stack	*a;
	t_stack	*b;

	i = 1;
	a = *stack;
	while (a)
	{
		b = *stack;
		smallest = index_find_smallest(&b);
		ft_list_find_node(b, smallest)->index = i;
		ft_list_find_node(b, smallest)->has_index = true;
		a = a->next;
		i++;
	}
}
