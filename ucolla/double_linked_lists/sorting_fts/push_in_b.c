/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:21:03 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/15 18:29:10 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dll.h"

/* 
	1. Pusho i primi due numeri in B
	2. Calcolo di volta in volta chi mi conviene pushar in B e poi lo pusho
 */

long	calculate_cost()
{
	
}

void	push_in_b(t_stack stack_a, t_satck stack_b, int first_moves)
{
	while (first_moves > 0)
	{
		if (stack_a->push == true)
			push_b(&stack_b, &stack_a);
		first_moves--;
	}
	
}
