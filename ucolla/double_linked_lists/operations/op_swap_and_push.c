/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_and_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:04:17 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/01 18:42:25 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack **stack)
{
	t_stack	*node;

	node = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	node->next = *stack;
	*stack = node;
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack)
{
	t_stack	*node;

	node = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	node->next = *stack;
	*stack = node;
	write(1, "sb\n", 3);
}

/* void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
} */

void	pa(t_stack **stack, t_stack **node)
{
	t_stack	*tmp_node;

	tmp_node = (*node)->next;
	ft_list_addfront(stack, *node);
	*node = tmp_node;
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack, t_stack **node)
{
	t_stack	*tmp_node;

	tmp_node = (*node)->next;
	ft_list_addfront(stack, *node);
	*node = tmp_node;
	write(1, "pb\n", 3);
}