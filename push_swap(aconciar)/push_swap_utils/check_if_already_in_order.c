/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_already_in_order.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:29:05 by aconciar          #+#    #+#             */
/*   Updated: 2024/01/03 17:44:42 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_list *stack)
{
	int	min_value;
	int	current_value;

	if (stack->next == NULL)
		return (1);
	current_value = *(int *)(stack->content);
	min_value = current_value;
	stack = stack->next;
	current_value = *(int *)(stack->content);
	if (current_value < min_value)
			return (1);
	while (stack)
	{
		current_value = *(int *)(stack->content);
		if (current_value < min_value)
			return (1);
		min_value = current_value;
		stack = stack->next;
	}
	return (0);
}
