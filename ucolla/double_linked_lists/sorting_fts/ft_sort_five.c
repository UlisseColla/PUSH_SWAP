/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:44 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/24 17:29:59 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_dll.h"

void	push_biggest(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	t_stack *a;
	t_stack *b;

	i = 0;
	a = *stack_a;
	while (a)
	{
		b = *stack_a;
		if (a->value == find_biggest(&b))
			break ;
		a = a->next;
		i++;
	}
	if (i <= ft_list_size(*stack_a) / 2)
	{
		while (--i >= 0)
			ra(stack_a);
	}
	else
	{
		while (++i <= ft_list_size(*stack_a))
			rra(stack_a);
	}
	pb(stack_b, stack_a);
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	push_biggest(stack_a, stack_b);
	push_biggest(stack_a, stack_b);
	ft_sort_three(stack_a);
	sb(stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	ra(stack_a);
	ra(stack_a);
}
