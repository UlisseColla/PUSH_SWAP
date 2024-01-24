/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:14:30 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/24 17:27:29 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_dll.h"

void	rra(t_stack **stack)
{
	t_stack	*value;
	t_stack	*seclast_node;

	value = *stack;
	while (value->next)
	{
		if (value->next->next == NULL)
			seclast_node = value;
		value = value->next;
	}
	seclast_node->next = NULL;
	ft_list_addfront(stack, value);
	ft_printf("rra\n");
}

void	rrb(t_stack **stack)
{
	t_stack	*value;
	t_stack	*seclast_node;

	value = *stack;
	while (value->next)
	{
		if (value->next->next == NULL)
			seclast_node = value;
		value = value->next;
	}
	seclast_node->next = NULL;
	ft_list_addfront(stack, value);
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_printf("rrr\n");
}
