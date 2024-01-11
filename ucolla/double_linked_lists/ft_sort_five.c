/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:44 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/10 19:36:58 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dll.h"

static void	push_biggest(t_stack **stack_a, t_stack **stack_b)
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
	if (i <= 2)
	{
		while (i > 0)
		{
			rotate_a(stack_a);
			i--;
		}
	}
	else
	{
		while (i <= 5)
		{
			reverse_rotate_a(stack_a);
			i++;
		}
	}
	push_b(stack_b, stack_a);
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	push_biggest(stack_a, stack_b);
}