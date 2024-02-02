/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:26:15 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/01 18:42:59 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int		j;
	int		smallest;
	t_stack	*b;

	i = 1;
	j = ft_list_size(stack);
	b = *stack;
	while (i <= j)
	{
		smallest = index_find_smallest(&b);
		ft_list_find_node(b, smallest)->index = i;
		ft_list_find_node(b, smallest)->has_index = true;
		i++;
	}
}

void	index_push_init(t_stack *stack, int *lis)
{
	t_stack	*tmp;
	int		i;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		i = 0;
		tmp->push = 0;
		while (lis[i] != -1)
		{
			if (lis[i] == tmp->index)
				tmp->push = 1;
			i++;
		}
		tmp = tmp->next;
	}
}
