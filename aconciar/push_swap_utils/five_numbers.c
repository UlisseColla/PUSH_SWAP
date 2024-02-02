/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:33:56 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/02 21:21:32 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_biggest(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	i = 0;
	a = *stack_a;
	while (a)
	{
		b = *stack_a;
		if (a->value == find_biggest(b))
			break ;
		a = a->next;
		i++;
	}
	if (i <= ft_list_size(*stack_a) / 2)
	{
		while (--i >= 0)
			ra(stack_a, 1);
	}
	else
	{
		while (++i <= ft_list_size(*stack_a))
			rra(stack_a, 1);
	}
	pb(stack_b, stack_a, 1);
}

void	five_numbers(t_stack **stack_a, t_stack **stack_b)
{
	push_biggest(stack_a, stack_b);
	push_biggest(stack_a, stack_b);
	three_numbers_a(stack_a);
	sb(stack_b, 1);
	pa(stack_a, stack_b, 1);
	pa(stack_a, stack_b, 1);
	ra(stack_a, 1);
	ra(stack_a, 1);
}
