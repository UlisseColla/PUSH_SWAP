/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:30:43 by ucolla            #+#    #+#             */
/*   Updated: 2023/12/20 15:23:26 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	push_b(stack_b, stack_a);
	push_b(stack_b, stack_a);
	
	if (*(int *)(*stack_b)->content < *(int *)(*stack_b)->next->content)
		swap_b(stack_b);
	sort_three(*stack_a);

	// ft_printf("stack_b: %d, %d\n", *(int *)(*stack_b)->content, *(int *)(*stack_b)->next->content);
	
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);

	// ft_printf("Stack in ordine\n");
	// show_stacks(stack_a, stack_b);
}