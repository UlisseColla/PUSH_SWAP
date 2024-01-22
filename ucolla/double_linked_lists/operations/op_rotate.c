/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:54:15 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/16 15:26:39 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_dll.h"

void	rotate_a(t_stack **stack)
{
	t_stack	*value;

	value = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	value->next = NULL;
	ft_list_addback(stack, value);
	ft_printf("ra\n");
}

void	rotate_b(t_stack **stack)
{
	t_stack	*value;

	value = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	value->next = NULL;
	ft_list_addback(stack, value);
	ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	ft_printf("rr\n");
}
