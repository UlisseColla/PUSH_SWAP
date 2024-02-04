/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:54:15 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/04 14:04:09 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack **stack, int i)
{
	t_stack	*value;

	value = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	value->next = NULL;
	ft_list_addback(stack, value);
	if (i == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack **stack, int i)
{
	t_stack	*value;

	value = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	value->next = NULL;
	ft_list_addback(stack, value);
	if (i == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	write(1, "rr\n", 3);
}
