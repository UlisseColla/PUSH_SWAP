/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_and_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:04:17 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/24 17:26:57 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_dll.h"

void	sa(t_stack **stack)
{
	t_stack	*node;

	node = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	node->next = *stack;
	*stack = node;
	ft_printf("sa\n");
}

void	sb(t_stack **stack)
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
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
}

void	pa(t_stack **stack, t_stack **node)
{
	t_stack	*tmp_node;

	tmp_node = (*node)->next;
	ft_list_addfront(stack, *node);
	*node = tmp_node;
	ft_printf("pa\n");
}

void	pb(t_stack **stack, t_stack **node)
{
	t_stack	*tmp_node;

	tmp_node = (*node)->next;
	ft_list_addfront(stack, *node);
	*node = tmp_node;
	ft_printf("pb\n");
}