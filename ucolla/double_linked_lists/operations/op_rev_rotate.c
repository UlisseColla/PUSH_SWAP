/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:14:30 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/01 15:26:47 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	write(1, "rra\n", 4);
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
	write(1, "rrb\n", 4);
}

void	rra_no_print(t_stack **stack)
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
}

void	rrb_no_print(t_stack **stack)
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
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra_no_print(stack_a);
	rrb_no_print(stack_b);
	write(1, "rrr\n", 4);
}
