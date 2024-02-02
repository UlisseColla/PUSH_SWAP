/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:33:56 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/01 17:35:42 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_to_a_five(t_stack **stack_a, t_stack **stack_b)
{
		if ((*stack_b)->index > find_biggest(*stack_a) || (*stack_b)->index < find_smallest(*stack_a))
			while (ft_list_last(*stack_a)->index != find_biggest(*stack_a))
			{
				if (find_eff(*stack_a, find_biggest(*stack_a)) > (ft_list_size(*stack_a) / 2))
					rra(stack_a);
				else
					ra(stack_a);
			}
		else
		{
			if (find_value(*stack_a, (*stack_b)->index + 1) == 1)
				while ((*stack_a)->index != (*stack_b)->index + 1)
				{
					if (find_eff(*stack_a, (*stack_b)->index + 1) > (ft_list_size(*stack_a) / 2))
						rra(stack_a);
					else
						ra(stack_a);
				}
			else
				while ((*stack_b)->index > (*stack_a)->index)
				{
					if (find_eff(*stack_a, find_biggest_before_index(*stack_a, (*stack_b)->index)) > (ft_list_size(*stack_a) / 2))
						rra(stack_a);
					else
						ra(stack_a);
				}
		}
	pa(stack_a, stack_b);
}

void	five_numbers(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_b, stack_a);
	pb(stack_b, stack_a);
	three_numbers_a(stack_a);
	push_b_to_a_five(stack_a, stack_b);
	push_b_to_a_five(stack_a, stack_b);
	while((*stack_a)->index > find_smallest(*stack_a))
		ra(stack_a);
}
