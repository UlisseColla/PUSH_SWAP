/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:57:09 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/02 21:15:24 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack, int i)
{
	t_stack	*node;

	node = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	node->next = *stack;
	*stack = node;
	if (i == 1)
		ft_printf("sa\n");
}

void	sb(t_stack **stack, int i)
{
	t_stack	*node;

	node = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	node->next = *stack;
	*stack = node;
	if (i == 1)
		ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b, int i)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (i == 1)
		ft_printf("ss\n");
}
