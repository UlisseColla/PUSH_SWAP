/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:21:03 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/16 18:52:15 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_dll.h"

/* 
	1. Pusho i primi due numeri in B
	2. Calcolo di volta in volta chi mi conviene pushar in B e poi lo pusho
 */

/* comincio il calcolo con l'array di arrivo gia' in ordine decrescente */
// long	calculate_cost_b(t_stack **stack_a, t_stack **stack_b)
// {
// 	long	moves;

// 	moves = 0;
// 	if (((*stack_a)->value > (*stack_b)->value && (*stack_a)->value > ft_list_last((*stack_b))->value)
// 		|| ((*stack_a)->value > (*stack_b)->value && (*stack_a)->value < ft_list_last((*stack_b))->value))
// 		return (1); //Potrei pushare in B
// 	else if ((*stack_a)->value < (*stack_b)->value && (*stack_a)->value > ft_list_last((*stack_b))->value)
// 	{
// 		while ((*stack_a)->value < (*stack_b)->value && (*stack_a)->value < ft_list_last((*stack_b))->value)
// 		{
// 			rotate_b(stack_b); //ruoto A fino a che B non si trova nell'ordine giusto da poter pushare
// 			moves++;
// 		}
// 	}
// 	return (moves);
// }

void	push_in_b(t_stack **a, t_stack **b)
{
	long	i;

	i = ft_list_size(*a);
	printf("size_A: %ld\n", i);
	while (i > 0)
	{
		if ((*a)->push == true)
			push_b(b, a);
		else
			rotate_a(a);
		i--;
	}
}

void	push_in_a(t_stack **a, t_stack **b)
{
	long	i;

	i = ft_list_size(*b);
	printf("size_B: %ld\n", i);
	while (i > 0)
	{
		// if ((*b)->index > (*a)->index)
		// {
			
		// }
		// while ((*b)->index > (*a)->index)
		// {
		// 	if ((*a)->next->index > (*b)->index)
		// 		push_a(a, b);
		// 	rotate_a(a);
		// }
		if ((*b)->index > (*a)->index && (*b)->index > ft_list_last(*b)->index)
		{
			push_a(a, b);
			rotate_a(a);
		}
		else if ((*b)->index > (*a)->index)
		{
			rotate_a(a);
		}
		else
			push_a(a, b);
		i--;
	}
}

// while ((*b)->index > (*a)->index)
// {
// 	rotate_a(a);
// 	if ()
// }