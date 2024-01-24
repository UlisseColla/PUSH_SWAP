/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:02:54 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/24 17:28:48 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_dll.h"

void	ft_sort_three(t_stack **stack)
{
	// t_list *tmp = NULL;
	
	if (((*stack)->value) == find_biggest(stack)) //max all'inizio
	{
		if (((*stack)->next->value) == find_smallest(stack))
			ra(stack);
		else
		{
			sa(stack);
			rra(stack);
		}
	}
	else if (((*stack)->value) == find_smallest(stack)) //min all'inizio
	{
		if (((*stack)->next->value) == find_biggest(stack))
		{
			rra(stack);
			sa(stack);
		}
	}
	else // middle all'inizio
	{
		if (((*stack)->next->value) == find_biggest(stack))
			rra(stack);
		else
			sa(stack);
	}
}
