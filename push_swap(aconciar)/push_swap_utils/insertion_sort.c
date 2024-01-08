/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:05:05 by aconciar          #+#    #+#             */
/*   Updated: 2024/01/03 17:57:45 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_list *stack)
{
	int	min_value;
	int	current_value;

	min_value = INT_MAX;
	while (stack)
	{
		current_value = *(int *)(stack->content);
		if (current_value < min_value)
			min_value = current_value;
		stack = stack->next;
	}
	return (min_value);
}

int	find_eff(t_list *stack)
{
	int	min_value;
	int	current_value;
	int	i;

	i = 0;
	current_value = *(int *)(stack->content);
	min_value = find_smallest(stack);
	while (current_value != min_value)
	{
		current_value = *(int *)(stack->content);
		if (current_value < min_value)
			min_value = current_value;
		stack = stack->next;
		i++;
	}
	return (i);
}

void	insertion_sort(t_list **stack_a, t_list **stack_b, int i)
{
	while ((*stack_a)->next)
	{
		if ((*(int *)(*stack_a)->content) == find_smallest(*stack_a))
		{
			pb(stack_b, stack_a);
			i--;
		}
		else if (find_eff(*stack_a) <= i)
			ra(stack_a);
		else if (find_eff(*stack_a) > i)
			rra(stack_a);
	}
	while ((*stack_b))
		pa(stack_a, stack_b);
}
