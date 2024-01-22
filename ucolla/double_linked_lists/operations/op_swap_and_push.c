/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_and_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:04:17 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/16 15:26:41 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_dll.h"

void	swap_a(t_stack **stack)
{
	t_stack	*node;

	node = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	node->next = *stack;
	*stack = node;
	ft_printf("sa\n");
}

void	swap_b(t_stack **stack)
{
	t_stack	*node;

	node = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	node->next = *stack;
	*stack = node;
	ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	ft_printf("ss\n");
}

void	push_a(t_stack **stack, t_stack **node)
{
	t_stack	*tmp_node;

	tmp_node = (*node)->next;
	ft_list_addfront(stack, *node);
	*node = tmp_node;
	ft_printf("pa\n");
}

void	push_b(t_stack **stack, t_stack **node)
{
	t_stack	*tmp_node;

	tmp_node = (*node)->next;
	ft_list_addfront(stack, *node);
	*node = tmp_node;
	ft_printf("pb\n");
}