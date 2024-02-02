/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:41:00 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/01 17:38:50 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_four(t_stack **stack_a, t_stack **stack_b)
{
	push_smallest(stack_a, stack_b);
	ft_three_numbers(stack_a);
	pa(stack_a, stack_b);
}

void	ft_sort_two(t_stack **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	
	a = NULL;
	b = NULL;
	if (initialize_stack(&a, argv, argc) == 1)
		return (1);
	if (check_order(&a) == 0 && argc > 1)
	{
		if (ft_list_size(&a) == 2)
			ft_sort_two(&a);
		else if (ft_list_size(&a) == 3)
			ft_three_numbers(&a);
		else if (ft_list_size(&a) == 4)
			ft_sort_four(&a, &b);
		else if (ft_list_size(&a) == 5)
			ft_five_numbers(&a, &b);
		else
			sorting(&a, &b);
	}
	// ft_printf("STACK_A\n");
	// show_stack(&a);
	// ft_printf("STACK_B\n");
	// show_stack(&b);
	ft_free_list(a);
	// ft_free_list(b);
	return (0);
}
